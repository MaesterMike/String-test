#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>

sfw::string::string(void)
{
	m_data = new  char[m_size = 1]{ '\0' };
}

sfw::string::~string()
{
	delete[]m_data;
}

size_t sfw::string::length() const
{
	return strlen(m_data);
}

sfw::string::string(size_t size)
{
	m_data = new  char[m_size = size + 1]{ '\0' };
}

sfw::string::string(const char * a, size_t size)
{
	m_data = new  char[m_size = size] { '\0' };
	strncpy_s(m_data, size, a, _TRUNCATE);
	m_data[m_size - 1] = '\0';
}

sfw::string::string(const char * a)
{
	if (a != nullptr)
	{
		m_data = new  char[m_size = strlen(a) + 1]{ '\0' };
		strcpy_s(m_data, m_size, a);
		m_data[m_size - 1] = '\0';
	}
	else
	{
		m_data = nullptr;
		*this = string();
	}
}

sfw::string::string(const string & a)
{
	m_data = new  char[m_size = a.m_size]{ '\0' };
	strcpy_s(m_data, a.m_size, a.m_data);
	m_data[m_size - 1] = '\0';
}

sfw::string::string(string && a)
{
	m_data = a.m_data;
	m_size = a.m_size;

	a.m_data = new  char[a.m_size = 1]{ '\0' };
}

sfw::string & sfw::string::operator=(const string & a)
{
	if (this != &a)
	{
		if (m_size < strlen(a.m_data) + 1)
		{
			delete m_data;
			m_size = strlen(a.m_data) + 1;
			m_data = new  char[m_size];
			m_data[0] = '\0';
		}
		strcpy_s(m_data, m_size, a.m_data);
	}
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	// if we have data, get rid of it
	if (m_data != nullptr)
	{
		delete m_data;
	}

	// steal the data
	m_data = a.m_data;
	m_size = a.m_size;

	// reset the object we stole from
	a.m_data = new  char[a.m_size = 1]{ '\0' };

	return *this;
}

sfw::string & sfw::string::operator=(const char * a)
{
	delete[] m_data;
	if (a != nullptr)
	{
		m_size = strlen(a) + 1;
		m_data = new  char[m_size];
		m_data[0] = '\0';
		strcpy_s(m_data, m_size, a);
	}
	return *this;
}

sfw::string & sfw::string::operator+=(const string & a)
{
	resize(length() + a.length() + 1);
	strcat_s(m_data, m_size, a.m_data);
	return *this;
}

sfw::string & sfw::string::operator+=(const char * a)
{
	if (a != nullptr)
	{
		resize(length() + strlen(a) + 1);
		strcat_s(m_data, m_size, a);
	}
	return *this;
}

sfw::string & sfw::string::operator+=(char a)
{
	resize(length() + 2);
	m_data[m_size - 2] = a;
	m_data[m_size - 1] = '\0';
	return *this;
}

char & sfw::string::operator[](size_t index)
{
	return this->m_data[index];
}

const char & sfw::string::operator[](size_t index) const
{
	return this->m_data[index];
}

size_t sfw::string::size() const
{
	return size_t(m_size - 1);
}

void sfw::string::resize(size_t size)
{
	char * something = new  char[size];
	m_size = size;
	if(m_data != nullptr) 
	{
		strncpy_s(something, size, m_data, m_size);
		delete[] m_data;
	}
	m_data = something;
	m_data[m_size - 1] = '\0';
}

void sfw::string::clear()
{
	m_data[0] = '\0';
}

bool sfw::string::empty() const
{
	if(m_data[0] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

const char * sfw::string::cstring() const
{
	return m_data;
}

bool sfw::operator<(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) == -1) { return true; }
	else { return false; }
}

bool sfw::operator<(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == -1) { return true; }
	else { return false; }
}

bool sfw::operator<(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) == -1) { return true; }
	else { return false; }
}

bool sfw::operator<=(const string & a, const string & b)
{
	if (a < b || a == b) { return true; }
	else { return false; }
}

bool sfw::operator<=(const string & a, const char * b)
{
	if (a < b || a == b) { return true; }
	else { return false; }
}

bool sfw::operator<=(const char * a, const string & b)
{
	if (a < b || a == b) { return true; }
	else { return false; }
}

bool sfw::operator>(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) == 1) { return true; }
	else { return false; }
}

bool sfw::operator>(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == 1) { return true; }
	else { return false; }
}

bool sfw::operator>(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) == 1) { return true; }
	else { return false; }
}

bool sfw::operator>=(const string & a, const string & b)
{
	if (a > b || a == b) { return true; }
	else { return false; }
}

bool sfw::operator>=(const string & a, const char * b)
{
	if (a > b || a == b) { return true; }
	else { return false; }
}

bool sfw::operator>=(const char * a, const string & b)
{
	if (a > b || a == b) { return true; }
	else { return false; }
}

bool sfw::operator!=(const string & a, const string & b)
{
	if (!(a == b)) { return true; }
	else { return false; }
}

bool sfw::operator!=(const string & a, const char * b)
{
	if (!(a == b)) { return true; }
	else { return false; }
}

bool sfw::operator!=(const char * a, const string & b)
{
	if (!(a == b)) { return true; }
	else { return false; }
}

bool sfw::operator==(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) == 0) { return true; }
	else { return false; }
}

bool sfw::operator==(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == 0) { return true; }
	else { return false; }
}

bool sfw::operator==(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) == 0) { return true; }
	else { return false; }
}

sfw::string sfw::operator+(const string & a, const string & b)
{
	sfw::string temp(a);
	temp += b;
	return temp;
}

sfw::string sfw::operator+(const string & a, const char * b)
{
	sfw::string temp(a);
	temp += b;
	return temp;
}

sfw::string sfw::operator+(const char * a, const string & b)
{
	sfw::string temp(a);
	temp += b;
	return temp;
}

sfw::string sfw::operator+(const string & a, char b)
{
	sfw::string temp(a);
	temp += b;
	return temp;
}

sfw::string sfw::operator+(char a, const string & b)
{
	sfw::string temp(2);
	temp[0] = a;
	temp[1] = '\0';
	temp += b;
	return temp;
}

std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	os << p.cstring();
	return os;
}

std::istream & sfw::operator>>(std::istream & is, string & p)
{
	char temp[100000];
	is >> temp;
	p = temp;
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	return string(a, len + 1);
}
