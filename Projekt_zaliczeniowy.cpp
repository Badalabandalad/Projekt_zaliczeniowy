
#include <iostream>
#include "Program.hpp"

using namespace std;


int main()
{

	Program program;
	program.initialize();
	
	
	while (program.get_stan() == true)
	{
		program.akcja();
	}

	cout << "Koniec" << endl;

	return 0;
}
