#include "Klasy.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iomanip>
#include <stdexcept>

using json = nlohmann::json;

// --- Implementacja metod klasy Paczka ---

// Statyczna metoda do generowania losowego numeru paczki
std::string Paczka::generateRandomPackageNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100000, 999999);
    return "PKZ" + std::to_string(distrib(gen));
}

// Konstruktor tworzący nową paczkę
Paczka::Paczka(const Nadawca& n, const Odbiorca& o)
    : numerPaczki(generateRandomPackageNumber()), nadawca(n), odbiorca(o) {
}

// Konstruktor wczytujący paczkę z pliku
Paczka::Paczka(std::string num, const Nadawca& n, const Odbiorca& o)
    : numerPaczki(std::move(num)), nadawca(n), odbiorca(o) {
}

// Metoda wywoływana po przyjęciu paczki
void Paczka::paczkaPrzyjeta() const {
    // Można tutaj dodać logikę, np. zapis do logu systemowego
    // Na razie zostawiamy pustą
}


// --- Implementacja metod klasy Sortownia ---

const std::vector<Paczka>& Sortownia::getPaczki() const {
    return paczki;
}

void Sortownia::wczytajPaczkiZPliku(const std::string& nazwaPliku) {
    paczki.clear();
    std::ifstream ifs(nazwaPliku);
    if (!ifs.is_open()) {
        // Jeśli plik nie istnieje, to nie jest błąd, po prostu nie ma paczek
        return;
    }

    json data;
    try {
        ifs >> data;
    }
    catch (json::parse_error&) {
        // Plik jest uszkodzony lub pusty, traktujemy jakby nie było paczek
        ifs.close();
        return;
    }
    ifs.close();

    if (!data.is_array()) {
        return; // Oczekujemy tablicy w pliku JSON
    }

    for (const auto& item : data) {
        if (!item.is_object()) continue;

        Nadawca n;
        if (item.contains("nadawca") && item["nadawca"].is_object()) {
            const auto& jNadawca = item["nadawca"];
            if (jNadawca.contains("imie")) n.imie = jNadawca["imie"].get<std::string>();
            if (jNadawca.contains("nazwisko")) n.nazwisko = jNadawca["nazwisko"].get<std::string>();
            if (jNadawca.contains("adres") && jNadawca["adres"].is_object()) {
                if (jNadawca["adres"].contains("miasto")) n.miasto = jNadawca["adres"]["miasto"].get<std::string>();
                if (jNadawca["adres"].contains("kodPocztowy")) n.kodPocztowy = jNadawca["adres"]["kodPocztowy"].get<std::string>();
            }
        }

        Odbiorca o;
        if (item.contains("odbiorca") && item["odbiorca"].is_object()) {
            const auto& jOdbiorca = item["odbiorca"];
            if (jOdbiorca.contains("imie")) o.imie = jOdbiorca["imie"].get<std::string>();
            if (jOdbiorca.contains("nazwisko")) o.nazwisko = jOdbiorca["nazwisko"].get<std::string>();
            if (jOdbiorca.contains("adres") && jOdbiorca["adres"].is_object()) {
                if (jOdbiorca["adres"].contains("miasto")) o.miasto = jOdbiorca["adres"]["miasto"].get<std::string>();
                if (jOdbiorca["adres"].contains("kodPocztowy")) o.kodPocztowy = jOdbiorca["adres"]["kodPocztowy"].get<std::string>();
            }
        }

        std::string numer = item.value("numerPaczki", "");
        if (!numer.empty()) {
            paczki.emplace_back(numer, n, o);
        }
    }
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
}