#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream> 
#include "json.hpp"

class Paczka;

class Sortownia {
public:
    enum class KryteriumSortowania {
        WG_MIASTA,
        WG_KODU_POCZTOWEGO,
        WG_ADRESU_DORECZENIA
    };

    void wczytajPaczkiZPliku(const std::string& nazwaPliku);
    void zapiszPaczkiDoPliku(const std::string& nazwaPliku);
    void sortujPaczki(KryteriumSortowania kryterium);
    std::vector<Paczka>& getPaczki();

private:
    std::vector<Paczka> paczki;
};

class Adres {
public:
    std::string ulica, miasto, wojewodztwo, kodPocztowy, kraj;
    virtual ~Adres() = default;
private:
    virtual void klasaWirtualnaAdres() = 0;
};

class Osoba {
public:
    std::string imie, nazwisko, telefon, email;
    virtual ~Osoba() = default;
private:
    virtual void klasaWirtualnaOsoba() = 0;
};

class Nadawca : public Osoba, public Adres {
private:
    void klasaWirtualnaOsoba() override {}
    void klasaWirtualnaAdres() override {}
};

class Odbiorca : public Osoba, public Adres {
private:
    void klasaWirtualnaOsoba() override {}
    void klasaWirtualnaAdres() override {}
};

class Paczka {
public:
    enum class RozmiarPaczki { MALA, SREDNIA, DUZA };
    enum class StatusPaczki { W_SORTOWNI, W_DORECZENIU, DOSTARCZONO };

private:
    std::string numerPaczki;
    Nadawca nadawca;
    Odbiorca odbiorca;
    RozmiarPaczki rozmiar;
    StatusPaczki status;

    static std::string generateRandomPackageNumber();

public:
    Paczka(const Nadawca& n, const Odbiorca& o, RozmiarPaczki r);
    Paczka(std::string num, const Nadawca& n, const Odbiorca& o, RozmiarPaczki r, StatusPaczki s);

    const Nadawca& getNadawca() const { return nadawca; }
    const Odbiorca& getOdbiorca() const { return odbiorca; }
    std::string getNumerPaczki() const { return numerPaczki; }
    RozmiarPaczki getRozmiar() const { return rozmiar; }
    StatusPaczki getStatus() const { return status; }

    void setStatus(StatusPaczki newStatus) { status = newStatus; }

    friend std::ostream& operator<<(std::ostream& os, const Paczka& p);
};

// POPRAWKA: Deklaracje funkcji pomocniczych przeniesione tutaj
Paczka::RozmiarPaczki stringToRozmiar(const std::string& s);
std::string rozmiarToString(Paczka::RozmiarPaczki r);
Paczka::StatusPaczki stringToStatus(const std::string& s);
std::string statusToString(Paczka::StatusPaczki s);