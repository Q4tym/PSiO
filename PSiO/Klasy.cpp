#include "Klasy.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <ostream> // Dodane dla ostream

using json = nlohmann::json;

//--[REQUIREMENT: Operator Overloading]--
// Implementacja przeciążonego operatora '<<' dla klasy Paczka.
// Umożliwia to łatwe logowanie obiektu Paczka do dowolnego strumienia wyjściowego.
std::ostream& operator<<(std::ostream& os, const Paczka& p) {
    os << "Paczka #" << p.getNumerPaczki()
        << " | Rozmiar: " << (p.getRozmiar() == Paczka::RozmiarPaczki::MALA ? "Mala" : p.getRozmiar() == Paczka::RozmiarPaczki::SREDNIA ? "Srednia" : "Duza")
        << " | Odbiorca: " << p.getOdbiorca().imie << " " << p.getOdbiorca().nazwisko
        << " | Adres: " << p.getOdbiorca().ulica << ", " << p.getOdbiorca().kodPocztowy << " " << p.getOdbiorca().miasto;
    return os;
}

// --- Implementacja metod klasy Paczka ---

std::string Paczka::generateRandomPackageNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000, 999999);
    return "PKZ" + std::to_string(distrib(gen));
}

Paczka::Paczka(const Nadawca& n, const Odbiorca& o, RozmiarPaczki r)
    : numerPaczki(generateRandomPackageNumber()), nadawca(n), odbiorca(o), rozmiar(r) {
}

Paczka::Paczka(std::string num, const Nadawca& n, const Odbiorca& o, RozmiarPaczki r)
    : numerPaczki(std::move(num)), nadawca(n), odbiorca(o), rozmiar(r) {
}

void Paczka::paczkaPrzyjeta() const {
    // Logika bez zmian
}


// --- Implementacja metod klasy Sortownia ---

const std::vector<Paczka>& Sortownia::getPaczki() const {
    return paczki;
}

Paczka::RozmiarPaczki stringToRozmiar(const std::string& rozmiarStr) {
    if (rozmiarStr == "SREDNIA") return Paczka::RozmiarPaczki::SREDNIA;
    if (rozmiarStr == "DUZA") return Paczka::RozmiarPaczki::DUZA;
    return Paczka::RozmiarPaczki::MALA;
}

void Sortownia::wczytajPaczkiZPliku(const std::string& nazwaPliku) {
    paczki.clear();
    std::ifstream ifs(nazwaPliku);
    if (!ifs.is_open()) {
        return;
    }

    json data;
    //--[REQUIREMENT: Error Handling]--
    try {
        ifs >> data;
    }
    catch (json::parse_error&) {
        ifs.close();
        return;
    }
    ifs.close();

    if (!data.is_array()) {
        return;
    }

    for (const auto& item : data) {
        if (!item.is_object()) continue;

        Nadawca n;
        if (item.contains("nadawca") && item["nadawca"].is_object()) {
            const auto& jNadawca = item["nadawca"];
            if (jNadawca.contains("imie")) n.imie = jNadawca["imie"].get<std::string>();
            if (jNadawca.contains("nazwisko")) n.nazwisko = jNadawca["nazwisko"].get<std::string>();
            if (jNadawca.contains("adres") && jNadawca["adres"].is_object()) {
                const auto& jAdres = jNadawca["adres"];
                if (jAdres.contains("ulica")) n.ulica = jAdres["ulica"].get<std::string>();
                if (jAdres.contains("miasto")) n.miasto = jAdres["miasto"].get<std::string>();
                if (jAdres.contains("kodPocztowy")) n.kodPocztowy = jAdres["kodPocztowy"].get<std::string>();
            }
        }

        Odbiorca o;
        if (item.contains("odbiorca") && item["odbiorca"].is_object()) {
            const auto& jOdbiorca = item["odbiorca"];
            if (jOdbiorca.contains("imie")) o.imie = jOdbiorca["imie"].get<std::string>();
            if (jOdbiorca.contains("nazwisko")) o.nazwisko = jOdbiorca["nazwisko"].get<std::string>();
            if (jOdbiorca.contains("adres") && jOdbiorca["adres"].is_object()) {
                const auto& jAdres = jOdbiorca["adres"];
                if (jAdres.contains("ulica")) o.ulica = jAdres["ulica"].get<std::string>();
                if (jAdres.contains("miasto")) o.miasto = jAdres["miasto"].get<std::string>();
                if (jAdres.contains("kodPocztowy")) o.kodPocztowy = jAdres["kodPocztowy"].get<std::string>();
            }
        }

        Paczka::RozmiarPaczki rozmiar = stringToRozmiar(item.value("rozmiar", "MALA"));
        std::string numer = item.value("numerPaczki", "");
        if (!numer.empty()) {
            paczki.emplace_back(numer, n, o, rozmiar);
        }
    }
}

//--[REQUIREMENT: STL Algorithm]--
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
        // Ulepszone sortowanie wielopoziomowe przy użyciu std::tie
        std::sort(paczki.begin(), paczki.end(), [](const Paczka& a, const Paczka& b) {
            const auto& adrA = a.getOdbiorca();
            const auto& adrB = b.getOdbiorca();
            return std::tie(adrA.miasto, adrA.kodPocztowy, adrA.ulica) <
                std::tie(adrB.miasto, adrB.kodPocztowy, adrB.ulica);
            });
    }
}