#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;
class HistoryCL
{
protected:
	string m_imie;
	string m_nazwisko;
	string m_mail;
	string m_grupa;
	HistoryCL * m_nastepnaOsoba;
public:
	void Inicjuj();
	void Sprzatnij();
	void Wypelnij();
	HistoryCL * GetNastepnaOsoba();
	void ShowDaneOsoby(int fImieWidth = 12, int fNazwiskoWidth = 20, int fMailWidth = 30, int fGrupaWidth = 4);
	void DodajOsobeNaKoniec();
};

void HistoryCL::Inicjuj()
{
	m_nastepnaOsoba = NULL;
}

void HistoryCL::Sprzatnij()
{
	if (m_nastepnaOsoba != NULL)
	{
		m_nastepnaOsoba->Sprzatnij();
		delete m_nastepnaOsoba;
		m_nastepnaOsoba = NULL;
	}
}

HistoryCL * HistoryCL::GetNastepnaOsoba()
{
	return(m_nastepnaOsoba);
}

void HistoryCL::Wypelnij()
{
	cout << "Podaj imie: ";
	cin >> m_imie;
	cout << "Podaj nazwisko: ";
	cin >> m_nazwisko;
	cout << "Podaj email: ";
	cin >> m_mail;
	cout << "Podaj grupę: ";
	cin >> m_grupa;
}

void HistoryCL::ShowDaneOsoby(int fImieWidth, int fNazwiskoWidth, int fEmailWidth, int fGrupaWidth )
{
	cout << setw(fImieWidth) << m_imie << " " << setw(fNazwiskoWidth) << m_nazwisko << " " << setw(fEmailWidth) << m_mail << " " << setw(fGrupaWidth) << m_grupa<< endl;
}

void HistoryCL::DodajOsobeNaKoniec()
{
	//Szukanie ostatniej osoby
	HistoryCL * tOstatniaOsoba = this; //Zapisanie wskaźnika obecnej osoby do zmiennej
	while (tOstatniaOsoba->m_nastepnaOsoba != NULL) tOstatniaOsoba = tOstatniaOsoba->m_nastepnaOsoba;

	//Utworzenie nowej osoby i zapisanie do ostatniej osoby
	HistoryCL * tNowaOsoba = new HistoryCL;
	tNowaOsoba->Inicjuj();
	tNowaOsoba->Wypelnij();
	tOstatniaOsoba->m_nastepnaOsoba = tNowaOsoba;
}



class MenuCL
{
public:
	void main();
	void ProsteDzialania();
	void ProsteDzialania_1();
	void ProsteDzialania_2();
};

void MenuCL::main()
{
	cout << "1. Proste działania ( + - x / ) \n";
	cout << "2. Figury płaskie \n";
	cout << "3. Figury przestrzenne \n";
	cout << "4. Silnia \n";
	cout << "5. Ciąg Fibonacciego \n";
	cout << "6. Potęga \n";
	cout << "7. Konwerter liczb dziesietnych na binarne \n";
	cout << "8. bleu screen \n";


}

void MenuCL::ProsteDzialania()
{
	cout << "1. Wczytaj z pliku zadania do wykonania \n";
	cout << "2. Wpisz działanie \n";
	cout << "Wybierz opcje \n";
}

void MenuCL::ProsteDzialania_1()
{
	cout << "podaj nazwę pliku \n";

}


int main()
{

	MenuCL * menu = new MenuCL;
	menu->main();

	exit(0);


	/*Utworzenie pierwszej osoby*/
	HistoryCL * tPierwszaOsoba = new HistoryCL;
	tPierwszaOsoba->Inicjuj();

	/*Wypełnienie pierwszej osoby*/
	tPierwszaOsoba->Wypelnij();

	/*Wczytywanie kolejnych osób*/
	char tZnak;
	do
	{
		cout << "Czy chcesz dodac nowa osobe? (T/N) ";
		do
		{
			tZnak = _getch();
		} while ((tZnak != 'n') && (tZnak != 'N') && (tZnak != 't') && (tZnak != 'T'));

		cout << tZnak << endl;
		if ((tZnak == 't') || (tZnak == 'T')) tPierwszaOsoba->DodajOsobeNaKoniec(); //Dodawanie nowej osoby

	} while ((tZnak != 'n') && (tZnak != 'N'));

	/*Wyświetlanie wszystkich osób*/
	HistoryCL * tWyswietlOsoby = tPierwszaOsoba;
	while (tWyswietlOsoby != NULL)
	{
		tWyswietlOsoby->ShowDaneOsoby();
		tWyswietlOsoby = tWyswietlOsoby->GetNastepnaOsoba();
	}


	/*Zwalnianie pamięci*/
	tPierwszaOsoba->Sprzatnij();
	delete tPierwszaOsoba;

	_getch();
	return 0;
}
