#include "String.h"
#include <vector>
#include <string.h>


String::String() : TCharArray::TCharArray(0)
{}

String::String( char *s) : TCharArray::TCharArray(0)
{
	insert(s);
	
}

String::String(const String& s) : TCharArray::TCharArray(0)
{
	insert(s.getString());
	
}

String::~String()
{}


bool operator!=(const String& lhs, const String& rhs)
{
	return !(strcmp(lhs.arr, rhs.arr));
}

String& String::operator=(const String s)
{
	insert(s.getString());
	return *this;
}


String& String::operator=(const char *s)
{
	insert(s);
	return *this;
}
std::ostream& operator<<(std::ostream &os, String &s)
{
	os << s.getString();
	return os;
}

std::istream& operator >> (std::istream &is, String &s)
{

	char buffer[254];
	is.getline(buffer, 254);
	s.insert(buffer);
	return is;
}

const String operator+(const String& left, const String& right)
{
	String temp = String(left);
	temp.append(right.getString());

	return temp;
}

const String operator+( char *left, const String& right)
{
	String temp = String(left);
	temp.append(right.getString());

	return temp;
}

const String operator+(const String& left, const char *right)
{
	String temp = String(left);
	temp.append(right);

	return temp;
}


bool operator<(const String& left, const String& right)
{
	return strcmp(left.getString(), right.getString()) < 0;
}

bool operator>(const String& left, const String& right)
{
	return strcmp(left.getString(), right.getString()) > 0;
}

bool operator==(const String& left, const String& right)
{
	return strcmp(left.getString(), right.getString()) == 0;
}

bool operator==(const String &left, const char *right)
{
	return strcmp(left.getString(), right) == 0;
}


