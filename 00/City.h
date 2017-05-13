#pragma once
#include <iostream>
#include "String.h"
#define END std::endl


class City
{
private:
	char Name[20];
	int Ppl;
	double Area;
	int Birth;
	int Schools;
public:

	City();
	~City();
	void showInfo();
	void getData();
	void write_data(char* n, char *filename);
	void Display(int n,char *filename);
	static int count(char *filename);
	void Rread(char* n, char* filename);
	void Help();
	void Wwork(int argc,char* arv, char * n, char* filename);
};