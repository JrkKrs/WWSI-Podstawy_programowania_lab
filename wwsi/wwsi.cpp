#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include <conio.h>
#include <vector>
#include <list>

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
private:
	int Check_isset_menu(int lenght_menu, int select_int );
	int GenMenu(string * list);
public:
	void main();
	void clear();
	void ProsteDzialania();
	void ProsteDzialania_1();
	void ProsteDzialania_2();
};

int MenuCL::Check_isset_menu(int lenght_menu, int select_int)
{
	vector<int> menu_numbers;
	for (int i =1; i <=lenght_menu; i++ )
	{
		menu_numbers.push_back(i);
	}
	if (std::find(menu_numbers.begin(), menu_numbers.end(), select_int) != menu_numbers.end())
		return 0;
	else
		return 1;
}

int MenuCL::GenMenu(string * list)
{
	
	int count = 1;
	for (auto in : *list)
	{
		//cout << in[0];
		string temp = "" + in;
		printf("%.0d. %s\n", count, in);
		count++;
	}
	char tZnak;
	MenuCL * menu = new MenuCL;
	int number;
	int force_break = 0;
	do
	{
		tZnak = _getch();
		number = (int)tZnak - 48;
		force_break++;
	} while (menu->Check_isset_menu(size(*list), number) || force_break > 100);
	return number;
	
}

void MenuCL::main()
{
	// 0 name
	// 1 menu id
	string list[8];
	list[0] = "Proste działania ( + - x / )";
	list[1] = "Figury płaskie ";
	list[2] = "Figury przestrzenne ";
	list[3] = "Silnia ";
	list[4] = "Ciąg Fibonacciego ";
	list[5] = "Potęga ";
	list[6] = "Konwerter liczb dziesietnych na binarne ";
	list[7] = "bleu screen ";
	MenuCL * menu = new MenuCL;
	int number = menu->GenMenu(list);
	switch (number)
	{
	case 1:

		menu->ProsteDzialania();
		break;
	default:
		exit(2);
	}

}

void MenuCL::clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

void MenuCL::ProsteDzialania()
{
	MenuCL * menu = new MenuCL;
	menu->clear();
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
