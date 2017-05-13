#pragma once
#include <iostream>
#include <vector>
class TCharArray
{
protected:
	char* arr;
	size_t length;
public:
	TCharArray();
	TCharArray(size_t len);
	~TCharArray();
	char at(size_t index);
	char operator[](size_t index);
	size_t getLength();
	void reallocate(size_t newsize);
	char* getString() const;
	void append(const char *newline);
	void insert(const char *newline);
	void showConsole();
};

