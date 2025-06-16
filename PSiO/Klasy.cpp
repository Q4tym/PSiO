#include "Klasy.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <ostream>

using json = nlohmann::json;

std::ostream& operator<<(std::ostream& os, const Paczka& p) {
    os << "Paczka #" << p.getNumerPaczki()
        << " | Odbiorca: " << p.getOdbiorca().imie << " " << p.getOdbiorca().nazwisko
        << " | Adres: " << p.getOdbiorca().ulica << ", " << p.getOdbiorca().kodPocztowy << " " << p.getOdbiorca().miasto;
    return os;
}

std::string Paczka::generateRandomPackageNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000, 999999);
    return "PKZ" + std::to_string(distrib(gen));
}

Paczka::Paczka(const Nadawca& n, const Odbiorca& o, RozmiarPaczki r)
    : numerPaczki(generateRandomPackageNumber()), nadawca(n), odbiorca(o), rozmiar(r), status(StatusPaczki::W_SORTOWNI) {
}

Paczka::Paczka(std::string num, const Nadawca& n, const Odbiorca& o, RozmiarPaczki r, StatusPaczki s)
    : numerPaczki(std::move(num)), nadawca(n), odbiorca(o), rozmiar(r), status(s) {
}

std::vector<Paczka>& Sortownia::getPaczki() {
    return paczki;
}

Paczka::RozmiarPaczki stringToRozmiar(const std::string& s) {
    if (s == "SREDNIA") return Paczka::RozmiarPaczki::SREDNIA;
    if (s == "DUZA") return Paczka::RozmiarPaczki::DUZA;
    return Paczka::RozmiarPaczki::MALA;
}
std::string rozmiarToString(Paczka::RozmiarPaczki r) {
    if (r == Paczka::RozmiarPaczki::SREDNIA) return "SREDNIA";
    if (r == Paczka::RozmiarPaczki::DUZA) return "DUZA";
    return "MALA";
}
Paczka::StatusPaczki stringToStatus(const std::string& s) {
    if (s == "W doreczeniu") return Paczka::StatusPaczki::W_DORECZENIU;
    if (s == "Dostarczono") return Paczka::StatusPaczki::DOSTARCZONO;
    return Paczka::StatusPaczki::W_SORTOWNI;
}
std::string statusToString(Paczka::StatusPaczki s) {
    if (s == Paczka::StatusPaczki::W_DORECZENIU) return "W doreczeniu";
    if (s == Paczka::StatusPaczki::DOSTARCZONO) return "Dostarczono";
    return "W sortowni";
}

void Sortownia::wczytajPaczkiZPliku(const std::string& nazwaPliku) {
    paczki.clear();
    std::ifstream ifs(nazwaPliku);
    if (!ifs.is_open()) return;
    json data;
    try {
        if (ifs.peek() != std::ifstream::traits_type::eof()) {
            ifs >> data;
        }
        else {
            return;
        }
    }
    catch (json::parse_error&) { return; }
    ifs.close();
    if (!data.is_array()) return;

    for (const auto& item : data) {
        if (!item.is_object()) continue;
        Nadawca n;
        if (item.contains("nadawca") && item["nadawca"].is_object()) {
            const auto& jNadawca = item["nadawca"];
            n.imie = jNadawca.value("imie", "");
            n.nazwisko = jNadawca.value("nazwisko", "");
            if (jNadawca.contains("adres") && jNadawca["adres"].is_object()) {
                const auto& jAdres = jNadawca["adres"];
                n.ulica = jAdres.value("ulica", "");
                n.miasto = jAdres.value("miasto", "");
                n.kodPocztowy = jAdres.value("kodPocztowy", "");
            }
        }
        Odbiorca o;
        if (item.contains("odbiorca") && item["odbiorca"].is_object()) {
            const auto& jOdbiorca = item["odbiorca"];
            o.imie = jOdbiorca.value("imie", "");
            o.nazwisko = jOdbiorca.value("nazwisko", "");
            if (jOdbiorca.contains("adres") && jOdbiorca["adres"].is_object()) {
                const auto& jAdres = jOdbiorca["adres"];
                o.ulica = jAdres.value("ulica", "");
                o.miasto = jAdres.value("miasto", "");
                o.kodPocztowy = jAdres.value("kodPocztowy", "");
            }
        }

        Paczka::RozmiarPaczki rozmiar = stringToRozmiar(item.value("rozmiar", "MALA"));
        Paczka::StatusPaczki status = stringToStatus(item.value("status", "W sortowni"));
        std::string numer = item.value("numerPaczki", "");
        if (!numer.empty()) {
            paczki.emplace_back(numer, n, o, rozmiar, status);
        }
    }
}

void Sortownia::zapiszPaczkiDoPliku(const std::string& nazwaPliku) {
    json paczkiJson = json::array();
    for (const auto& p : paczki) {
        json jPaczka;
        jPaczka["numerPaczki"] = p.getNumerPaczki();
        jPaczka["rozmiar"] = rozmiarToString(p.getRozmiar());
        jPaczka["status"] = statusToString(p.getStatus());
        jPaczka["nadawca"]["imie"] = p.getNadawca().imie;
        jPaczka["nadawca"]["nazwisko"] = p.getNadawca().nazwisko;
        jPaczka["nadawca"]["adres"]["ulica"] = p.getNadawca().ulica;
        jPaczka["nadawca"]["adres"]["miasto"] = p.getNadawca().miasto;
        jPaczka["nadawca"]["adres"]["kodPocztowy"] = p.getNadawca().kodPocztowy;
        jPaczka["odbiorca"]["imie"] = p.getOdbiorca().imie;
        jPaczka["odbiorca"]["nazwisko"] = p.getOdbiorca().nazwisko;
        jPaczka["odbiorca"]["adres"]["ulica"] = p.getOdbiorca().ulica;
        jPaczka["odbiorca"]["adres"]["miasto"] = p.getOdbiorca().miasto;
        jPaczka["odbiorca"]["adres"]["kodPocztowy"] = p.getOdbiorca().kodPocztowy;
        paczkiJson.push_back(jPaczka);
    }
    std::ofstream ofs(nazwaPliku);
    ofs << std::setw(4) << paczkiJson << std::endl;
    ofs.close();
}

void Sortownia::sortujPaczki(KryteriumSortowania kryterium) {
    if (kryterium == KryteriumSortowania::WG_MIASTA) {
        std::sort(paczki.begin(), paczki.end(), [](const Paczka& a, const Paczka& b) {
            return a.getOdbiorca().miasto < b.getOdbiorca().miasto;
            });
    }
    else if (kryterium == KryteriumSortowania::WG_KODU_POCZTOWEGO) {
        std::sort(paczki.begin(), paczki.end(), [](const Paczka& a, const Paczka& b) {
            return a.getOdbiorca().kodPocztowy < b.getOdbiorca().kodPocztowy;
            });
    }
    else if (kryterium == KryteriumSortowania::WG_ADRESU_DORECZENIA) {
        std::sort(paczki.begin(), paczki.end(), [](const Paczka& a, const Paczka& b) {
            const auto& adrA = a.getOdbiorca();
            const auto& adrB = b.getOdbiorca();
            return std::tie(adrA.miasto, adrA.kodPocztowy, adrA.ulica) <
                std::tie(adrB.miasto, adrB.kodPocztowy, adrB.ulica);
            });
    }
}