#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>


class string {


	char *str;
	int len;



public:

	string(char c, int n);
	string(const char*s);
	string(const string &s);
	~string();

	void add_string(const string &s);
	void copy_string(const string &s);
	int strlen();

	void check_str();
};

string::string(char c, int n)
{
	len = n;

	str = new char [n+1];

	for (int i = 0; i < n; i++)
	{
		str[i] = c;
	}
	str[n] = NULL;
}

string::string(const char *s)
{
	
}

string::string(const string &s)
{
	char * _str = s.str;


}

void string::add_string(const string &s)
{
	

	int total_len = len + s.len;

	char *_str = new char[total_len+1];


	for (int i = 0; i <len; i++)
	{
		_str[i] = str[i];
	}
	for (int j = 0; j < total_len; j++)
	{
		_str[(len)+j] = s.str[j];
	}

	delete[] str;
	str = _str;
	len = total_len;
}

void string::copy_string(const string &s)
{
	char *_str = new char[len];
	
	strcpy(str, _str);
	delete s.str;
	//s.str = _str;
}

int string::strlen()
{
	return len;
}
string::~string()
{
	std::cout << "소멸함" << std::endl;
	if(str!=NULL) delete[] str;
}

void string::check_str()
{
	std::cout << "복사 후 " << str<< std::endl;
}
int main(void)
{
	
	string s1('o', 4);
	string s2('a',3);
	string s3(s2);

	s1.check_str();
	s1.add_string(s2);

	s2.copy_string(s1);

	s2.check_str();

	


	std::cout << "길이: " << s1.strlen() << std::endl;

	s1.check_str();
	
	
	return 0;
}