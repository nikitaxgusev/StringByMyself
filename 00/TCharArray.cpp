#include "TCharArray.h"



TCharArray::TCharArray() : length(0)
{
	arr = new char[length];
}
TCharArray::TCharArray(size_t len = 0) : length(len)
{
	arr = new char[length];
}

TCharArray::~TCharArray()
{
	delete[] arr;
}
void TCharArray::reallocate(size_t newsize)
{
	char* temp = NULL;
	temp = new char[newsize];
	for (size_t i = 0; i<length; i++) temp[i] = arr[i];
	delete[] arr;
	arr = temp;
	temp = NULL;
}
void TCharArray::showConsole()
{
	for (size_t i = 0; i<length; i++)
		std::cout << arr[i];
}
char* TCharArray::getString() const
{
	return arr;
}
char TCharArray::at(size_t index)
{
	if (index >= length)
	{
		std::cout << "Error! Invalid index" << std::endl; return '\0';
	}

	return arr[index];
}

char TCharArray::operator[](size_t index)
{
	return at(index);
}
size_t TCharArray::getLength()
{
	return length;
}
void TCharArray::insert(const char *newline)
{
	size_t len = -1;
	while (newline[++len] != '\0');
	length = len;
	reallocate(length+1);
	for (size_t i = 0; i<length; i++)
		arr[i] = newline[i];
	arr[length] = '\0';
}
void TCharArray::append(const char *newline)
{
	size_t len = -1;
	while (newline[++len] != '\0');

	reallocate(length + len);
	for (size_t i = length; i<length + len; i++)
		arr[i] = newline[i - length];
	length += len;
}
