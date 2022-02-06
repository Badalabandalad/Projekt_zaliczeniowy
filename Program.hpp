#include "Core.hpp"
#include<fstream>
using namespace std;



class Program
{
private:

	Katalog katalog;
	bool stan;

public:

	Program()
	{
		stan=true;
	}

	void akcja()
	{
		string wejscie, wejscie2;
		int wejscie3;
		bool check;


		for (;;)
		{
			system("cls");
			cout << "Ilosc pojazdow w bazie ==> " << katalog.get_ilosc_pojazdow() << endl;
			cout << "Wybierz jedna z ponizszych opcji:" << endl;
			cout << "	lp - wylistuj pojazdy (Marka i model)" << endl;
			cout << "	add - Dodaj pojazd\n";
			cout << "	delate - Usunl pojazd\n";
			cout << "	save - Zapisz liste do pliku\n";
			cout << "	read - Wczutaj liste pojazdow z pliku\n";
			cout << "	end - Zakoncz dzialanie\n";
			cin >> wejscie;

			check = false;

			if (wejscie == "lp")
			{
				system("cls");

				katalog.listuj_pojazdy();
				cout << "\n Press any key to continue...\n";
				_getch();
				system("cls");
				check = true;
			}
			if (wejscie == "add")
			{
				cout << "Chcesz dodac samochod osbowy czy motocykl? (sam/mot)" << endl;
				cin >> wejscie2;
				if (wejscie2 == "sam")
				{
					system("cls");
					string marka, model, imie, nazwisko;
					int rok, liczba;
					cout << "Dodajesz samochod!" << endl<<endl;
					cout << "Podaj marke" << endl;
					cin >> marka;
					cout << "Podaj model" << endl;
					cin >> model;
					cout << "Podaj imie wlasciciela" << endl;
					cin >> imie;
					cout << "Podaj nazwisko wlasciciela" << endl;
					cin >> nazwisko;
					cout << "Podaj rok produkcji" << endl;
					cin >> rok;
					cout << "Podaj liczbe miejsc siedzacych" << endl;
					cin >> liczba;
					katalog.dodaj_pojazd(make_unique<Osobowy>(liczba, marka, model, imie, nazwisko, rok));
				}
				else if (wejscie2 == "mot")
				{
					system("cls");
					string marka, model, imie, nazwisko, pom;
					int rok;
					bool kosz;
					cout << "Dodajesz motocykl!" << endl << endl;
					cout << "Podaj marke" << endl;
					cin >> marka;
					cout << "Podaj model" << endl;
					cin >> model;
					cout << "Podaj imie wlasciciela" << endl;
					cin >> imie;
					cout << "Podaj nazwisko wlasciciela" << endl;
					cin >> nazwisko;
					cout << "Podaj rok produkcji" << endl;
					cin >> rok;
					cout << "Czy ma kosz?(y/n)" << endl;
					cin >> pom;
					if (pom == "y") katalog.dodaj_pojazd(make_unique<Motocykl>(true, marka, model, imie, nazwisko, rok));
					else if (pom == "n") katalog.dodaj_pojazd(make_unique<Motocykl>(false, marka, model, imie, nazwisko, rok));
					else cout << "Bledna komenda!"<< endl;

				}
				else cout << "Nie ma takiej komendy!"<<endl;

				cout << "\n Press any key to continue...\n";
				_getch();
				system("cls"); 

				check = true;
			}
			if (wejscie == "delate") 
			{
				int i;
				cout << "Podaj ktory wiersz chcesz usunac?" << endl;
				cin >> i;
				katalog.delate(i);
				cout << "\n Press any key to continue...\n";
				_getch();
				system("cls");
				check = true;
			}
			if (wejscie == "save")
			{

				katalog.zapisz();
				cout << "\n Press any key to continue...\n";
				_getch();
				system("cls");
				check = true;
			}
			if (wejscie == "read") 
			{
				katalog.wczytaj();
				cout << "\n Press any key to continue...\n";
				_getch();
				system("cls");
				check = true;
			}
			if (wejscie == "end")
			{
				end();
				break;
				
			}

			if (check == false)
			{
				cout << "Nie ma takiej komendy\n";
				cout << "Press any key to continue...\n";
				_getch();
				system("cls");
			}


		}

	}

	void end()
	{
		string pom;
		cout << "Czy napewno chcesz zakonczyc dzialanie? (y/n)" << endl;
		cin >> pom;
		if (pom == "y") stan = false;
		else stan = true;

	}

	bool get_stan()
	{
		return stan;
	}

	void initialize()
	{
		cout << "Symulator przedsiebiorstwa na projekt polowkowy" << endl;
		cout << "\n";
		cout << "Press any key to continue..." << endl;
		_getch();
		system("cls");
	}
};