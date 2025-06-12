#include "Formularz_paczki.h"
#include "json.hpp"      // Do³¹czamy nag³ówki potrzebne do implementacji
#include "Logger.h"
#include <fstream>
#include <vector>
#include <iomanip>

// U¿ywamy przestrzeni nazw i aliasów tutaj, w pliku .cpp
using json = nlohmann::json;
using namespace PSiO;

// Implementacja konstruktora i destruktora (jeœli s¹ bardziej z³o¿one)
Formularz_paczki::Formularz_paczki(void)
{
	InitializeComponent(); // Ta metoda jest generowana przez Windows Forms i jej cia³o jest w .h
	this->fileName = "paczka_data.json";
}

Formularz_paczki::~Formularz_paczki()
{
	if (components)
	{
		delete components;
	}
}

// Implementacja (cia³o) metody InitializeComponent - skopiuj j¹ tutaj z pliku .h, jeœli jej tam nie ma
// Zazwyczaj Visual Studio zarz¹dza tym automatycznie i zostawia j¹ w pliku .h, co jest w porz¹dku.
// Jeœli masz j¹ w pliku .h wewn¹trz dyrektywy #pragma region, zostaw j¹ tam.

// Implementacja metod obs³ugi zdarzeñ
System::Void Formularz_paczki::buttonAnuluj_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

System::Void Formularz_paczki::buttonNadaj_Click(System::Object^ sender, System::EventArgs^ e) {
	// Walidacja podstawowych pól
	if (String::IsNullOrWhiteSpace(textNadawcaImie->Text) || String::IsNullOrWhiteSpace(textOdbiorcaImie->Text) ||
		String::IsNullOrWhiteSpace(textNadawcaNazwisko->Text) || String::IsNullOrWhiteSpace(textOdbiorcaNazwisko->Text) ||
		String::IsNullOrWhiteSpace(textNadawcaMiasto->Text) || String::IsNullOrWhiteSpace(textOdbiorcaMiasto->Text) ||
		String::IsNullOrWhiteSpace(textNadawcaKod->Text) || String::IsNullOrWhiteSpace(textOdbiorcaKod->Text) ||
		String::IsNullOrWhiteSpace(textNadawcaUlica->Text) || String::IsNullOrWhiteSpace(textOdbiorcaUlica->Text)) {
		MessageBox::Show("Pola: imiê, nazwisko, ulica, miasto i kod pocztowy musz¹ byæ wype³nione.", "B³¹d Walidacji", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Tworzenie obiektu Nadawcy
	Nadawca n;
	n.imie = toStdString(textNadawcaImie->Text);
	n.nazwisko = toStdString(textNadawcaNazwisko->Text);
	n.telefon = toStdString(textNadawcaTelefon->Text);
	n.email = toStdString(textNadawcaEmail->Text);
	n.ulica = toStdString(textNadawcaUlica->Text);
	n.miasto = toStdString(textNadawcaMiasto->Text);
	n.wojewodztwo = toStdString(textNadawcaWojewodztwo->Text);
	n.kodPocztowy = toStdString(textNadawcaKod->Text);
	n.kraj = toStdString(textNadawcaKraj->Text);

	// Tworzenie obiektu Odbiorcy
	Odbiorca o;
	o.imie = toStdString(textOdbiorcaImie->Text);
	o.nazwisko = toStdString(textOdbiorcaNazwisko->Text);
	o.telefon = toStdString(textOdbiorcaTelefon->Text);
	o.email = toStdString(textOdbiorcaEmail->Text);
	o.ulica = toStdString(textOdbiorcaUlica->Text);
	o.miasto = toStdString(textOdbiorcaMiasto->Text);
	o.wojewodztwo = toStdString(textOdbiorcaWojewodztwo->Text);
	o.kodPocztowy = toStdString(textOdbiorcaKod->Text);
	o.kraj = toStdString(textOdbiorcaKraj->Text);

	// Odczytanie rozmiaru paczki
	Paczka::RozmiarPaczki rozmiar;
	if (radioSrednia->Checked) {
		rozmiar = Paczka::RozmiarPaczki::SREDNIA;
	}
	else if (radioDuza->Checked) {
		rozmiar = Paczka::RozmiarPaczki::DUZA;
	}
	else {
		rozmiar = Paczka::RozmiarPaczki::MALA;
	}

	Paczka nowaPaczka(n, o, rozmiar);

	// Zapis do pliku JSON
	std::string stdFileName = toStdString(this->fileName);
	json paczkiJson;

	std::ifstream ifs(stdFileName);
	if (ifs.is_open()) {
		try {
			// Dodano sprawdzenie, czy plik nie jest pusty, aby unikn¹æ b³êdu parsowania
			if (ifs.peek() != std::ifstream::traits_type::eof()) {
				paczkiJson = json::parse(ifs);
			}

			if (!paczkiJson.is_array()) paczkiJson = json::array();
		}
		// Tutaj typ b³êdu jest ju¿ w pe³ni rozpoznawalny
		catch (json::parse_error&) {
			paczkiJson = json::array();
		}
		ifs.close();
	}
	else {
		paczkiJson = json::array();
	}

	std::string rozmiarStr = "MALA";
	if (rozmiar == Paczka::RozmiarPaczki::SREDNIA) rozmiarStr = "SREDNIA";
	else if (rozmiar == Paczka::RozmiarPaczki::DUZA) rozmiarStr = "DUZA";

	// Dodaj now¹ paczkê
	json jPaczka;
	jPaczka["numerPaczki"] = nowaPaczka.getNumerPaczki();
	jPaczka["rozmiar"] = rozmiarStr;
	jPaczka["nadawca"]["imie"] = n.imie;
	jPaczka["nadawca"]["nazwisko"] = n.nazwisko;
	jPaczka["nadawca"]["adres"]["ulica"] = n.ulica;
	jPaczka["nadawca"]["adres"]["miasto"] = n.miasto;
	jPaczka["nadawca"]["adres"]["kodPocztowy"] = n.kodPocztowy;
	jPaczka["odbiorca"]["imie"] = o.imie;
	jPaczka["odbiorca"]["nazwisko"] = o.nazwisko;
	jPaczka["odbiorca"]["adres"]["ulica"] = o.ulica;
	jPaczka["odbiorca"]["adres"]["miasto"] = o.miasto;
	jPaczka["odbiorca"]["adres"]["kodPocztowy"] = o.kodPocztowy;

	paczkiJson.push_back(jPaczka);

	std::ofstream ofs(stdFileName);
	ofs << std::setw(4) << paczkiJson << std::endl;
	ofs.close();

	Logger<Paczka> p_logger("package_log.txt");
	p_logger.log(nowaPaczka);

	String^ numerPaczki = msclr::interop::marshal_as<String^>(nowaPaczka.getNumerPaczki());
	MessageBox::Show("Paczka o numerze " + numerPaczki + " zosta³a pomyœlnie nadana!", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);

	this->Hide();
	AnimationForm^ animForm = gcnew AnimationForm();
	animForm->ShowDialog();

	EtykietaForm^ etykietaForm = gcnew EtykietaForm(nowaPaczka);
	etykietaForm->ShowDialog();

	this->Close();
}