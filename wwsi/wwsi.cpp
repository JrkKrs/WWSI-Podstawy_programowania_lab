#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include <conio.h>
#include <vector>
#include <list>
#include <math.h>

using namespace std;


class MathCL
{
protected:
	string m_imie;
	string m_nazwisko;
	string m_mail;
	string m_grupa;
	HistoryCL * m_nastepnaOsoba;
public:
	float ProsteDzialaniaTrojkat(float wysykosc, float podstawa);
	float ProsteDzialaniaProstokat(float a, float b);
	float ProsteDzialaniaKolo(float promien);
	float ProsteDzialaniaKwardrat(float a);
	unsigned long long SilniaCacl(int i);
	unsigned long long fib(int n);


};

float MathCL::ProsteDzialaniaTrojkat(float wysykosc, float podstawa)
{
	float result = 0.5 * podstawa * wysykosc;
	return  result;
}

float MathCL::ProsteDzialaniaProstokat(float a, float b)
{
	float result = a * b;
	return  result;
}

float MathCL::ProsteDzialaniaKolo(float promien)
{
	float result = M_PI * promien * promien;
	return  result;
}

float MathCL::ProsteDzialaniaKwardrat(float a)
{
	float result = a * a;
	return  result;
}

unsigned long long  MathCL::SilniaCacl(int i)
{
	if (i < 2)
	{
		return i;
	}
	else
	{
		return i * SilniaCacl(i - 1);
	}
}

unsigned long long MathCL::fib(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}



class MenuCL
{
private:
	int Check_isset_menu(int lenght_menu, int select_int);
	//int GenMenu(string * list);
public:
	void main();
	void clear();
	void GoToMainManu();

	void FiguryPlaskie();
	void ProsteDzialaniaTrojkat();
	void ProsteDzialaniaProstokat();
	void ProsteDzialaniaKolo();
	void ProsteDzialaniaKwardrat();
	//void FiguryPrzestrzenne();
	void Silnia();
	void CiagFibonacciego();
	void Potega();
	void Konw_10_2();
	void BleuScreen();
	void ProsteDzialania();
	void ProsteDzialaniaPlik();
	void ProsteDzialaniaCLI();
	void BackToMainMenu();
};



int MenuCL::Check_isset_menu(int lenght_menu, int select_int)
{
	vector<int> menu_numbers;
	for (int i = 1; i <= lenght_menu; i++)
	{
		menu_numbers.push_back(i);
	}
	if (std::find(menu_numbers.begin(), menu_numbers.end(), select_int) != menu_numbers.end())
		return 0;
	else
		return 1;
}


void MenuCL::FiguryPlaskie()
{
	clear();
	string list[5];
	list[0] = "Oblicz pole powierzchni trojkata";
	list[1] = "Oblicz pole powierzchni prostokatu";
	list[2] = "Oblicz pole powierzchni kola";
	list[3] = "Oblicz pole powierzchni kwadratu";
	list[4] = "powrot do menu glownego";

	int count = 1;
	for (auto in : list)
	{
		printf("%.0d. %s\n", count, in.c_str());
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
	} while (Check_isset_menu(size(list), number) || force_break > 100);


	switch (number)
	{
	case 1:

		ProsteDzialaniaTrojkat();
		break;
	case 2:

		ProsteDzialaniaProstokat();
		break;
	case 3:

		ProsteDzialaniaKolo();
		break;
	case 4:

		ProsteDzialaniaKwardrat();
		break;
	case 5:

		main();
		break;
	default:
		exit(2);
	}
}

void MenuCL::ProsteDzialaniaTrojkat()
{
	clear();
	printf("Obliczanie pola trojkata\n");

	float a, h;
	do
	{
		printf("Podaj dlugosc podstawy\n");
		cin >> a;
		if (a < 0)
		{
			printf("Dlugosc podstawy nie moze byc mniesza od zera, wprowadz wartosc jeszcze raz\n");

		}
	} while (a < 0);

	do
	{
		printf("Podaj dlugosc wysokosci\n");
		cin >> h;
		if (h < 0)
		{
			printf("Dlugosc wysokosci nie moze byc mniesza od zera, wprowadz wartosc jeszcze raz\n");

		}
	} while (h < 0);

	float result;
	MathCL * math_cl = new MathCL;
	result = math_cl->ProsteDzialaniaTrojkat(h, a);
	printf("Pole powierzchni trojkata wynosi: %0.2f\n", result);

	GoToMainManu();

}

void MenuCL::ProsteDzialaniaProstokat()
{
	clear();
	printf("Obliczanie pola prostokata\n");

	float a, h;
	do
	{
		printf("Podaj dlugosc podstawy\n");
		cin >> a;
		if (a < 0)
		{
			printf("Dlugosc podstawy nie moze byc mniesza od zera, wprowadz wartosc jeszcze raz\n");

		}
	} while (a < 0);

	do
	{
		printf("Podaj dlugosc wysokosci\n");
		cin >> h;
		if (h < 0)
		{
			printf("Dlugosc wysokosci nie moze byc mniesza od zera, wprowadz wartosc jeszcze raz\n");

		}
	} while (h < 0);

	float result;
	MathCL * math_cl = new MathCL;
	result = math_cl->ProsteDzialaniaProstokat(a, h);
	printf("Pole powierzchni prostokata wynosi: %0.2f\n", result);

	GoToMainManu();

}

void MenuCL::ProsteDzialaniaKolo()
{
	clear();
	printf("Obliczanie pola kola\n");

	float a;
	do
	{
		printf("Podaj dlugosc promienia kola\n");
		cin >> a;
		if (a < 0)
		{
			printf("Dlugosc promienia nie moze byc mniesza od zera, wprowadz wartosc jeszcze raz\n");

		}
	} while (a < 0);


	float result;
	MathCL * math_cl = new MathCL;
	result = math_cl->ProsteDzialaniaKolo(a);
	printf("Pole powierzchni prostokata wynosi: %0.2f\n", result);

	GoToMainManu();

}

void MenuCL::ProsteDzialaniaKwardrat()
{
	clear();
	printf("Obliczanie pola kwadratu\n");

	float a;
	do
	{
		printf("Podaj dlugosc boku kwadratu\n");
		cin >> a;
		if (a < 0)
		{
			printf("Dlugosc boku nie moze byc mniesza od zera, wprowadz wartosc jeszcze raz\n");

		}
	} while (a < 0);


	float result;
	MathCL * math_cl = new MathCL;
	result = math_cl->ProsteDzialaniaKwardrat(a);
	printf("Pole powierzchni kwadratu wynosi: %0.2f\n", result);

	GoToMainManu();
}

//void MenuCL::FiguryPrzestrzenne()
//{
//}

void MenuCL::Silnia()
{
	clear();
	printf("Obliczanie Silni\n");
	MathCL * math_cl = new	MathCL;
	int s;
	unsigned long long result;
	do
	{
		cout << "Podaj X! ";
		cin >> s;
		if (s >= 0 && s <= 20)
		{
			result = math_cl->SilniaCacl(s);
			std::string _str = std::to_string(result);
			printf("Silnia z liczby %i wynosi: %s\n", s, _str.c_str());
		}
		else
		{
			cout << "Podany ciag znakow nie jest liczba albo nie spelnia warunku x>=0 i x<20, Podaj prosze jeszcze raz liczbe\n";
		}

	} while (s < 0 || s > 20);

	GoToMainManu();


}

void MenuCL::CiagFibonacciego()
{
	clear();
	printf("Obliczanie n-tego wyrazu ciagu Fibonacciego\n");
	MathCL * math_cl = new	MathCL;
	int s;
	unsigned long long result;
	do
	{
		cout << "Podaj n ";
		cin >> s;
		if (s >= 0 && s <= 40)
		{
			result = math_cl->fib(s);
			std::string _str = std::to_string(result);
			printf("%i element ciagu Fibonacciego wynosi: %s\n", s, _str.c_str());
		}
		else
		{
			cout << "Podany ciag znakow nie jest liczba albo nie spelnia warunku n>=0 i n<40, Podaj prosze jeszcze raz liczbe\n";
		}

	} while (s < 0 || s > 20);

	GoToMainManu();
}

void MenuCL::Potega()
{

}

void MenuCL::Konw_10_2()
{
	clear();
	printf("Konwersja licz naturalnych dziesietnych na zapis binarny\n");
	MathCL * math_cl = new	MathCL;
	int s;
	unsigned long long result;
	do
	{
		cout << "Podaj liczbę dziesietna \n ";
		cin >> s;
		if (s >= 0 && s <= 40)
		{
			int i = 0, tab[31];

			while (s) //dopóki liczba będzie różna od zera
			{
				tab[i++] = s % 2;
				s /= 2;
			}

			for (int j = i - 1; j >= 0; j--)
				cout << tab[j];
			//result = math_cl->fib(s);
			//std::string _str = std::to_string(result);
			//printf("%i element ciagu Fibonacciego wynosi: %s\n", s, _str.c_str());
		}
		else
		{
			cout << "Podany ciag znakow nie jest liczba albo nie spelnia warunku n>=0 i n<40, Podaj prosze jeszcze raz liczbe\n";
		}

	} while (s < 0 || s > 20);

	GoToMainManu();
}


void MenuCL::BleuScreen()
{
}

void MenuCL::main()
{
	clear();

	string list[6];
	list[0] = "Proste dzialania ( + - )";
	list[1] = "Figury plaskie ";
	//list[2] = "Figury przestrzenne ";
	list[2] = "Oblicz silnie";
	list[3] = "Oblicz n-ty element ciągu Fibonacciego ";
	list[4] = "Oblicz potege ";
	list[5] = "Konwerter liczb dziesietnych na binarne ";
	//list[7] = "bleu screen ";
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
		menu->Silnia();
		break;
	case 4:
		menu->CiagFibonacciego();
		break;
	case 5:
		menu->Potega();
		break;
	case 6:
		menu->Konw_10_2();
		break;

	default:
		exit(2);
	}

}

void MenuCL::clear()
{
	std::cout << "\x1B[2J\x1B[H";;
	printf("\033c");
	system("CLS");
}

void MenuCL::GoToMainManu()
{
	char tZnak;
	cout << "Czy chcesz wczytać program od nowa? (T/N) ";
	do
	{
		tZnak = _getch();
	} while ((tZnak != 'n') && (tZnak != 'N') && (tZnak != 't') && (tZnak != 'T'));

	cout << tZnak << endl;
	if ((tZnak == 't') || (tZnak == 'T'))
		main();
}

void MenuCL::ProsteDzialania()
{
	cout << "1. Wczytaj z pliku zadania do wykonania \n";
	cout << "2. Wpisz działanie \n";
	cout << "Wybierz opcje \n";
}

	switch (number)
	{
	case 1:

		ProsteDzialaniaTrojkat();
		break;
	case 2:

		ProsteDzialaniaProstokat();
		break;
	case 3:

		ProsteDzialaniaKolo();
		break;
	case 4:

		ProsteDzialaniaKwardrat();
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
