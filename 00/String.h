#pragma once
#include "TCharArray.h"
#include <iostream>
class String : public TCharArray
{

public:
	
	String();
	String( char* s);
	String(const String& s);
	~String();

	String& operator= (const String s);
	String& operator= (const char* s);

	friend std::ostream& operator<< (std::ostream& os, String& s);
	friend std::istream& operator >> (std::istream& is, String& s);

	friend const String operator+ (const String& left, const String& right);
	friend const String operator+ ( char *left,const String& right);
	friend const String operator+ (const String& left, const char *right);
	friend bool operator!=(const String&, const String&);


	friend bool operator< (const String& left, const String& right);
	friend bool operator> (const String& left, const String& right);
	friend bool operator== (const String& left, const String& right);
	friend bool operator== (const String& left, const char* right);

	
};

