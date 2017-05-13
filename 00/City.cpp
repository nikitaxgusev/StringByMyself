#include "City.h"
#include <iostream>
#include <fstream>
#include "String.h"
#include <io.h>

City::City() : Name("NoName"), Ppl(0), Area(0.0), Birth(0), Schools(0)
{}
City::~City()
{}

void City::showInfo() {
	std::cout << "Name\t\t" << "People\t\t" << "Area\t\t" << "Birth\t\t" << "Schools\t\t" << END;
	std::cout <<Name<<"\t\t" << Ppl << "\t\t" << Area << "\t\t" << Birth << "\t\t" << Schools << END;
}
void City::getData()
{
	std::cout << "Enter a name of the city:   ";
	std::cin >> Name;
	std::cout << "Enter quanity of people in the city:   ";
	std::cin >> Ppl;
	std::cout << "Enter area of the city:   ";
	std::cin >> Area;
	std::cout << "Enter a year of foundation of the city:   ";
	std::cin >> Birth;
	std::cout << "Enter quanity of schools in the city:   ";
	std::cin >> Schools;
}

void City::write_data(char* t, char *filename)
{
	int n = atoi(t);
	City c;
	std::ofstream wRecord;
	wRecord.open(filename, std::ios::binary | std::ios::app);
	for (int i = 0; i < n; i++) {
		c.getData();
		wRecord.write((char*)&c, sizeof(c));
	}
	wRecord.close();
}

void City::Display(int n, char *filename) {
	City c;
	std::ifstream rRead;
	rRead.open(filename, std::ios::binary);
	if (_access(filename, 0) != 0) {
		std::cout << "Error:FILE NOT FOUND" << std::endl;
		exit(1);
	}
	else {
		rRead.seekg(n * sizeof(c));
		rRead.read((char*)&c, sizeof(c));
		c.showInfo();
		rRead.close();
	}
}

int City::count(char *filename)
{
	City c;
	std::ifstream infile;
	infile.open(filename, std::ios::binary);
	infile.seekg(0, std::ios::end);
	return (int)infile.tellg() / sizeof(c);
}

void City::Rread(char* t, char* filename)
{
	City c;
	int n = City::count(filename);
	int n1 = atoi(t);
	if (n1 > n) {
		std::cout << "Error: recordings [" << n << "] available!" << std::endl;
		std::cout << "You entered [" << n1 << "] recordings!" << std::endl;
		std::cout << "Try one more time with correct number" << std::endl;
		std::cout << "Closed.." << std::endl;
		exit(1);
	}
	for (int j = 0; j < n1; j++)
	{
		c.Display(j, filename);

	}
}

void City::Wwork(int argc, char* arv, char * n, char* filename)
{
	String help("-h");
	String help1("--help");
	String  read("-r");
	String  create("-c");

	City c;
	if (argc > 4 || argc < 1)
		c.Help();
	if (arv == create)
		c.write_data(n, filename);
	
	if (arv == read)
		c.Rread(n, filename);
}
void City::Help()
{
	std::cout << "Help note: " << END;
	std::cout << "if you would like to run the program in creating an electronic mode. You should ENTER: -c[N][file_name]" << END;
	std::cout << "[N]-number of records" << END;
	std::cout << "[file_name]-name of a text file" << END;
	std::cout << END;
	std::cout << "if you would like to run the program in read mode content text file.You should ENTER: -r[N][file_name]" << END;
	std::cout << "[N]-number of records" << END;
	std::cout << "[file_name]-name of a text file" << END;
	exit(1);
}