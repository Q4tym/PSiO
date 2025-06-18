class Sortownia {
public:
    enum class KryteriumSortowania {
        WG_MIASTA,
        WG_KODU_POCZTOWEGO
    };

    void wczytajPaczkiZPliku(const std::string& nazwaPliku); 
    void sortujPaczki(KryteriumSortowania kryterium); 
    void sortujPaczkiPoMiescie();
    const std::vector<Paczka>& getPaczki() const; 

private:
    std::vector<Paczka> paczki;
};
