#pragma once
/*************************************************
string.h

DESCRIPTION OF WHAT THIS FILE DOES,
WHAT'S IN IT, AND HOW IT SHOULD WORK!
DUPLICATE THIS FOR THE SOURCE FILE.

Esmeralda Salamone, esmes@aie.edu.au, 9/23/2015
Modified: Michael Small, mbs923@comcast.net, 10/13/2015

All rights reserved.
***************************************************/
#include <iosfwd>

namespace sfw
{
	class string
	{
	private:
		char *m_data;	
		size_t m_size;	

	public:	
		string(void); 

		string(size_t size); 
		string(const char *a, size_t size);
						
		
		~string(); 

		string(const char *a);		
		string(const string &a);	
		string(string &&a);			

		string &operator=(const string &a); 
		string &operator=(string &&a);		
		string &operator=(const char *a);	

		string &operator+=(const string &a);
		string &operator+=(const char *a);
		string &operator+=(char a);

		char &operator[](size_t index);				
		const char &operator[](size_t index) const; 

		size_t length() const;	
		size_t size() const;	

		void resize(size_t size);	
		void clear();				
		bool empty() const;			

		const char *cstring() const;	
	};

	bool operator<(const string &a, const string &b);
	bool operator<(const string &a, const char *b); 
	bool operator<(const char *a, const string &b);

	bool operator<=(const string &a, const string &b);
	bool operator<=(const string &a, const char *b);
	bool operator<=(const char *a, const string &b);
		
	bool operator>(const string &a, const string &b);
	bool operator>(const string &a, const char *b);
	bool operator>(const char *a, const string &b);

	bool operator>=(const string &a, const string &b);
	bool operator>=(const string &a, const char *b);
	bool operator>=(const char *a, const string &b);

	bool operator!=(const string &a, const string &b);
	bool operator!=(const string &a, const char *b);
	bool operator!=(const char *a, const string &b);

	bool operator==(const string &a, const string &b);
	bool operator==(const string &a, const char *b);
	bool operator==(const char *a, const string &b);

	string operator+(const string &a, const string &b);
	string operator+(const string &a, const char *b);
	string operator+(const char *a, const string &b);

	string operator+(const string &a, char b);
	string operator+(char a, const string &b);

	inline namespace literals {
		const string operator""_sfw(const char *a, size_t len); }

	std::ostream &operator<<(std::ostream &os, const string& p); 
	std::istream &operator>>(std::istream &is, string& p); 

}