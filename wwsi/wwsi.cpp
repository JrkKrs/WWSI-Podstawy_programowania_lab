#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include <conio.h>
#include <vector>
#include <list>

using namespace std;


class MathCL
{
public:
	float ProsteDzialaniaTrojkat(float wysykosc, float podstawa);
	float ProsteDzialaniaProstokat(float a, float b);
	float ProsteDzialaniaKolo(float promien);
	float ProsteDzialaniaKwardrat(float a);
};

class MenuCL
{
private:
	int Check_isset_menu(int lenght_menu, int select_int);
	//int GenMenu(string * list);
public:
	void FiguryPlaskie();
	void FiguryPrzestrzenne();
	long long SilniaCacl(int i);
	void Silnia();
	void CiagFibonacciego();
	void Potega();
	void Konw_10_2();
	void BleuScreen();
	void main();
	void clear();
	void ProsteDzialania();
	void ProsteDzialaniaPlik();
	void ProsteDzialaniaCLI();
	void BackToMainMenu();
};

long long  MenuCL::SilniaCacl(int i)
{
	if (i < 2)
	{
		return i;
	}
	else
	{
		return i * SilniaCacl(i-1);
	}
}

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

void MenuCL::ProsteDzialaniaTrojkat()
{
}

void MenuCL::ProsteDzialaniaProstokat()
{
}

void MenuCL::ProsteDzialaniaKolo()
{
}

void MenuCL::ProsteDzialaniaKwardrat()
{
}

void MenuCL::FiguryPlaskie()
{
	string list[5];
	list[0] = "Oblicz pole powierzchni trojkata";
	list[1] = "Oblicz pole powierzchni prostokatu";
	list[2] = "Oblicz pole powierzchni kola";
	list[3] = "Oblicz pole powierzchni kwadratu";
	list[4] = "powrot do menu glownego";
	MenuCL * menu = new MenuCL;

	int count = 1;
	for (auto in : list)
	{
		printf("%.0d. %s\n", count, in.c_str());
		count++;
	}
	char tZnak;
	int number;
	int force_break = 0;
	do
	{
		tZnak = _getch();
		number = (int)tZnak - 48;
		force_break++;
	} while (menu->Check_isset_menu(size(list), number) || force_break > 100);


	switch (number)
	{
	case 1:

		menu->ProsteDzialaniaTrojkat();
		break;
	case 2:

		menu->ProsteDzialaniaProstokat();
		break;
	case 3:

		menu->ProsteDzialaniaKolo();
		break;
	case 4:

		menu->ProsteDzialaniaKwardrat();
		break;
	default:
		exit(2);

	}
}

void MenuCL::FiguryPrzestrzenne()
{
}

void MenuCL::Silnia()
{
	int s;
	do
	{
		cout << "Podaj X! ";
		cin >> s;
		if (s>=0 && s<19)
		{
			cout << "Podany ciąg znaków nie jest liczbą albo nie spełnia warunku x>=0 i x<19, Podaj proszę jeszcze raz liczbę\n";

		}
		else
		{
			printf("Silnia z liczby %i wynosi: %d", s, SilniaCacl(s));
		}

	} while (s < 0 && s > 19);
	


}

void MenuCL::CiagFibonacciego()
{
}

void MenuCL::Potega()
{
}

void MenuCL::Konw_10_2()
{
}

//
//int MenuCL::GenMenu(string * list)
//{
//	
//	int count = 1;
//	for (auto in : *list)
//	{
//		//cout << in[0];
//		string temp = "" + in;
//		printf("%.0d. %s\n", count, in);
//		count++;
//	}
//	char tZnak;
//	MenuCL * menu = new MenuCL;
//	int number;
//	int force_break = 0;
//	do
//	{
//		tZnak = _getch();
//		number = (int)tZnak - 48;
//		force_break++;
//	} while (menu->Check_isset_menu(size(*list), number) || force_break > 100);
//	return number;
//	
//}

void MenuCL::BleuScreen()
{
}

void MenuCL::main()
{
	string list[8];
	list[0] = "Proste dzialania ( + - x / )";
	list[1] = "Figury plaskie ";
	list[2] = "Figury przestrzenne ";
	list[3] = "Silnia ";
	list[4] = "Ciag Fibonacciego ";
	list[5] = "Potega ";
	list[6] = "Konwerter liczb dziesietnych na binarne ";
	list[7] = "bleu screen ";
	MenuCL * menu = new MenuCL;

	int count = 1;
	for (auto in : list)
	{
		printf("%.0d. %s\n", count, in.c_str());
		count++;
	}
	char tZnak;
	int number;
	int force_break = 0;
	do
	{
		tZnak = _getch();
		number = (int)tZnak - 48;
		force_break++;
	} while (menu->Check_isset_menu(size(list), number) || force_break > 100);


	switch (number)
	{
	case 1:

		menu->ProsteDzialania();
		break;
	case 2:

		menu->FiguryPlaskie();
		break;
	case 3:

		menu->FiguryPrzestrzenne();
		break;
	case 4:

		menu->Silnia();
		break;
	case 5:

		menu->CiagFibonacciego();
		break;
	case 6:

		menu->Potega();
		break;
	case 7:

		menu->Konw_10_2();
		break;
	case 8:

		menu->BleuScreen();
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
	clear();
	cout << "1. Wczytaj z pliku zadania do wykonania \n";
	cout << "2. Wpisz dzialanie \n";
	cout << "Wybierz opcje \n";

	string list[3];
	list[0] = "Wczytaj z pliku zadania do wykonania";
	list[1] = "Wpisz dzialanie";
	list[2] = "powrot do menu glownego";

	int count = 1;
	for (auto in : list)
	{
		printf("%.0d. %s\n", count, in.c_str());
		count++;
	}
	char tZnak;
	int number;
	int force_break = 0;
	do
	{
		tZnak = _getch();
		number = (int)tZnak - 48;
		force_break++;
	} while (Check_isset_menu(size(list), number) || force_break > 100);

	MathCL * math = new MathCL;
	switch (number)
	{
	case 1:

		math->ProsteDzialaniaTrojkat();
		break;
	case 2:

		math->ProsteDzialaniaProstokat();
		break;
	case 3:

		math->ProsteDzialaniaKolo();
		break;
	case 4:

		math->ProsteDzialaniaKwardrat();
		break;
	default:
		exit(2);

	}
}

void MenuCL::ProsteDzialaniaPlik()
{
	cout << "podaj nazwę pliku \n";

}

void MenuCL::ProsteDzialaniaCLI()
{
}

void MenuCL::BackToMainMenu()
{
	clear();
}




int main()
{

	MenuCL * menu = new MenuCL;
	menu->main();

	exit(0);


	
}
