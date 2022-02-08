
#include<iostream>
#include<fstream>
#include <string>

using namespace std;


//Klasa Bazowa-pojazd
class Pojazd
{

private:

	int rok_produkcji;
	string imie_wlasciciela, nazwisko_wlasciciela, marka, model;

public:

	Pojazd(string markapom, string modelpom, string imie, string nazwisko, int rok)
	{
		marka = markapom;
		model = modelpom;
		imie_wlasciciela = imie;
		nazwisko_wlasciciela = nazwisko;
		rok_produkcji = rok;
	}

	string get_marka()
	{
		return marka;
	}

	string get_model()
	{
		return model;
	}

	int get_rok_produkcji()
	{
		return rok_produkcji;
	}

	string get_imie()
	{
		return imie_wlasciciela;
	}

	string get_nazwisko()
	{
		return nazwisko_wlasciciela;
	}

	virtual void print() = 0;

	virtual string zapis() = 0;

};

//Klasa Pochodna-Osobowy
class Osobowy : public Pojazd
{
private:
	int liczba_miesc;

public:

	Osobowy(int liczba, string markapom, string modelpom, string imie, string nazwisko, int rok) : Pojazd(markapom, modelpom, imie, nazwisko, rok)
	{
		if (liczba <= 0)
		{
			throw - 1;
		}

		liczba_miesc = liczba;
	}


	int get_liczba_miejsc()
	{
		return liczba_miesc;
	}


	virtual void print() 
	{
		cout << "Samochod osobowy " << get_marka() << " " << get_model() << " z roku " << get_rok_produkcji() << " z liczba miejsc " <<  get_liczba_miejsc() << " Wlasciciel: " << get_imie() << " " << get_nazwisko() << endl;
	}

	string zapis() 
	{

		return ("Samochod osobowy " + get_marka() + " " + get_model() + " z roku " + to_string( get_rok_produkcji()) + " z liczba miejsc " + to_string( get_liczba_miejsc()) + " Wlasciciel: " + get_imie() + " " + get_nazwisko());

	}

};

//Klasa Pochodna-Motocykl
class Motocykl :public Pojazd
{

private:
	bool kosz;
	
public:

	Motocykl(bool koszpom, string markapom, string modelpom, string imie, string nazwisko, int rok) : Pojazd(markapom, modelpom, imie, nazwisko, rok)
	{
		kosz = koszpom;
	}

	bool get_kosz()
	{
		return kosz;
	}


	virtual void print()
	{
		if( get_kosz() == true) cout << "Motocykl " << get_marka() << " " << get_model() << " z roku " << get_rok_produkcji() << " z koszem" << " Wlasciciel: "<<get_imie()<< " "<< get_nazwisko() << endl;
		else					cout << "Motocykl " << get_marka() << " " << get_model() << " z roku " << get_rok_produkcji() << " bez kosza" <<" Wlasciciel: " << get_imie() << " " << get_nazwisko() << endl;
	}


	string zapis()
	{

		if(get_kosz() == true) return( "Motocykl " + get_marka() + " " + get_model() + " z roku " + to_string(get_rok_produkcji()) + " z koszem Wlasciciel: " + get_imie() + " " + get_nazwisko());
		else                   return( "Motocykl " + get_marka() + " " + get_model() + " z roku " + to_string(get_rok_produkcji()) + " bez kosza Wlasciciel: " + get_imie() + " " + get_nazwisko());

	}

};