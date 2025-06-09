class Sortownia {
public:
    // Enum do wyboru kryterium sortowania
    enum class KryteriumSortowania {
        WG_MIASTA,
        WG_KODU_POCZTOWEGO
    };

    // Metody publiczne
    void wczytajPaczkiZPliku(const std::string& nazwaPliku); //
    void sortujPaczki(KryteriumSortowania kryterium); //
    void sortujPaczkiPoMiescie(); // Dodano metodê sortujPaczkiPoMiescie
    const std::vector<Paczka>& getPaczki() const; //

private:
    std::vector<Paczka> paczki; // Wektor do przechowywania paczek
};
