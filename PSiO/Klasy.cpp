#include "Klasy.h"
#include <msclr/marshal_cppstd.h>

// --- Implementacja metod dla klasy Sortownia ---

void Sortownia::wczytajPaczkiZPliku(const std::string& nazwaPliku) {
    paczki.clear(); // Wyczy�� wektor przed wczytaniem nowych danych
    std::ifstream ifs(nazwaPliku);
    if (!ifs.is_open()) {
        // Je�li plik nie istnieje, po prostu nic nie r�b.
        // W prawdziwej aplikacji mo�na by rzuci� wyj�tek lub zalogowa� b��d.
        // std::cerr << "Nie uda�o si� otworzy� pliku: " << nazwaPliku << std::endl;
        return;
    }

    nlohmann::json dane;
    try {
        ifs >> dane;
    }
    catch (nlohmann::json::parse_error& e) {
        // Je�li plik jest pusty lub uszkodzony
        // std::cerr << "B��d parsowania JSON: " << e.what() << std::endl;
        return;
    }

    if (!dane.is_array()) {
        return; // Oczekujemy tablicy paczek
    }

    for (const auto& jPaczka : dane) {
        Nadawca nadawca;
        nadawca.imie = jPaczka["nadawca"]["imie"];
        nadawca.nazwisko = jPaczka["nadawca"]["nazwisko"];
        nadawca.ulica = jPaczka["nadawca"]["adres"]["ulica"];
        nadawca.miasto = jPaczka["nadawca"]["adres"]["miasto"];
        nadawca.kodPocztowy = jPaczka["nadawca"]["adres"]["kodPocztowy"];

        Odbiorca odbiorca;
        odbiorca.imie = jPaczka["odbiorca"]["imie"];
        odbiorca.nazwisko = jPaczka["odbiorca"]["nazwisko"];
        odbiorca.ulica = jPaczka["odbiorca"]["adres"]["ulica"];
        odbiorca.miasto = jPaczka["odbiorca"]["adres"]["miasto"];
        odbiorca.kodPocztowy = jPaczka["odbiorca"]["adres"]["kodPocztowy"];

        std::string numerPaczki = jPaczka["numerPaczki"];

        paczki.emplace_back(numerPaczki, nadawca, odbiorca);
    }
}

void Sortownia::sortujPaczki(KryteriumSortowania kryterium) {
    // U�ycie algorytmu STL std::sort z w�asnym komparatorem (lambda)
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

const std::vector<Paczka>& Sortownia::getPaczki() const {
    return paczki;
}


// --- Implementacja metody dla klasy Paczka ---

void Paczka::paczkaPrzyjeta()
{
    std::stringstream ss;
    ss << "--- Potwierdzenie Nadania Paczki ---\n";
    ss << "Numer paczki: " << getNumerPaczki() << "\n\n";

    ss << "Nadawca:\n";
    ss << "  Imi� i nazwisko: " << nadawca.imie << " " << nadawca.nazwisko << "\n";
    ss << "  Adres: " << nadawca.ulica << ", " << nadawca.kodPocztowy << " " << nadawca.miasto << "\n\n";

    ss << "Odbiorca:\n";
    ss << "  Imi� i nazwisko: " << odbiorca.imie << " " << odbiorca.nazwisko << "\n";
    ss << "  Adres: " << odbiorca.ulica << ", " << odbiorca.kodPocztowy << " " << odbiorca.miasto << "\n";
    ss << "-------------------------------------\n";

    std::cout << ss.str() << std::endl;
}