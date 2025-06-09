// Dodaj funkcjê pomocnicz¹ poza klas¹
bool porownajWpisyMapy(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second < b.second;
}

void aktualizujStatystyki() {
    const auto& paczki = sortownia->getPaczki();
    labelLiczbaPaczekVal->Text = paczki.size().ToString();

    if (paczki.empty()) {
        labelMiastoVal->Text = "Brak";
        return;
    }

    std::map<std::string, int> licznikiMiast;
    for (const auto& paczka : paczki) {
        if (!paczka.getOdbiorca().miasto.empty()) {
            licznikiMiast[paczka.getOdbiorca().miasto]++;
        }
    }

    if (licznikiMiast.empty()) {
        labelMiastoVal->Text = "Brak";
        return;
    }

    // U¿yj funkcji globalnej zamiast lambdy
    auto najpopularniejsze = std::max_element(licznikiMiast.begin(), licznikiMiast.end(), porownajWpisyMapy);

    String^ miasto = msclr::interop::marshal_as<String^>(najpopularniejsze->first);
    String^ ilosc = String::Format("({0} szt.)", najpopularniejsze->second);
    labelMiastoVal->Text = String::Format("{0} {1}", miasto, ilosc);
}
