#include <iostream>
#include <vector>
#include <list>
#include <conio.h>
#include <iterator>
#include <exception>
#include <fstream>
#include <sstream>  
#include <cstring>  
#include "klasy.hpp"

using namespace std;


class Katalog
{
private:

	list <unique_ptr<Pojazd>> pojazdy;
	int n_pojazdow=0;


public:

	Katalog()
	{
		pojazdy.push_back(make_unique<Osobowy>(4, "Audi", "A4", "Przemek", "Bus", 2003));
		n_pojazdow++ ;
	}

	void listuj_pojazdy()
	{
		for (auto &Pojazd : pojazdy)
		{
			Pojazd->print();
		};

	}


	int get_ilosc_pojazdow()
	{
		return pojazdy.size();
	}

	void dodaj_pojazd(unique_ptr<Pojazd> p)
	{
		n_pojazdow++;
		pojazdy.push_back(move(p));
	}

	//usuwanie wiersza
	void delate(int i)
	{
		list <unique_ptr<Pojazd>>::iterator it = pojazdy.begin();
		advance(it, (i-1));
		pojazdy.erase(it);
		n_pojazdow--;
	}

	//zapis do pliku
	void zapisz()
	{
		fstream myfile("C:/Users/przem/Desktop/zapis.txt");

		for (auto& Pojazd : pojazdy)
		{
			myfile << Pojazd->zapis() << endl;
		};
		myfile.close();
	}

	//metoda wczytywania z pliku
	void wczytaj()
	{
		string line;
		string arr[15];
		int i = 0;
		fstream myfile;
		myfile.open("C:/Users/przem/Desktop/zapis.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				stringstream pom(line);
				while (pom.good() && i < 15)
				{
				pom >> arr[i];
				++i;
				}
				
				if (arr[0] == "Samochod")
				{
					pojazdy.push_back(make_unique<Osobowy>(stoi(arr[10]), arr[2], arr[3], arr[12], arr[13], stoi(arr[6])));
					n_pojazdow++;
				}
				else if (arr[6] == "z")
				{
					pojazdy.push_back(make_unique<Motocykl>(true, arr[1], arr[2], arr[9], arr[10], stoi(arr[5])));
					n_pojazdow++;
				}
				else if (arr[6] == "bez")
				{
					pojazdy.push_back(make_unique<Motocykl>(false, arr[1], arr[2], arr[9], arr[10], stoi(arr[5])));
					n_pojazdow++;
				}
				else cout << "Blad wczytywania" << endl;

				i = 0;
			}
			myfile.close();
		}
		else cout << "Blad otwierania pliku" << endl;
	}

};
