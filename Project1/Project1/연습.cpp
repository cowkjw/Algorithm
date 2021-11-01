#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>


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
	void same_string(const string &s);
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

void string::same_string(const string &s)
{
	char *_str = s.str;

	
	if (strcmp(str, _str) == 0)
	{
		std::cout << "���ڿ��� �����ϴ�" << std::endl;
	}
	else
	{
		std::cout << "���ڿ��� �ٸ��ϴ�" << std::endl;
	}
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

	//delete[] str;
	str = _str;
	len = total_len;
}

void string::copy_string(const string &s)
{
	char *_str = new char[s.len+1];
	
	strcpy(_str, s.str);
	//delete[] str;

	str = _str;

	std::cout << "ī��" << str << std::endl;
	
	
}

int string::strlen()
{
	return len;
}
string::~string()
{
	std::cout << "�Ҹ���" << std::endl;
	if(str!=NULL) delete[] str;
}

void string::check_str()
{
	std::cout << "üũ " << str<< std::endl;
}
int main(void)
{
	
	string s1('w', 4);
	string s2('a',4);
	string s3(s2);


	s2.check_str();
	s2.copy_string(s1);

	s2.add_string(s2);

	s2.check_str();

	s1.check_str();

	s1.copy_string(s2);
	s1.check_str();
	

	


	std::cout << "����: " << s1.strlen() << std::endl;

	
	
	return 0;
}
//class Marine {
//static int total_marine_num;
//const static int i = 0;
//
//int hp;                // ���� ü��
//int coord_x, coord_y;  // ���� ��ġ
//bool is_dead;
//
//const int default_damage;  // �⺻ ���ݷ�
//
// public:
//	 Marine();              // �⺻ ������
//	 Marine(int x, int y);  // x, y ��ǥ�� ���� ����
//	 Marine(int x, int y, int default_damage);
//
//	 int attack() const;                    // �������� �����Ѵ�.
//	 Marine& be_attacked(int damage_earn);  // �Դ� ������
//	 void move(int x, int y);               // ���ο� ��ġ
//
//	 void show_status();  // ���¸� �����ش�.
//	 static void show_total_marine();
//	 ~Marine() { total_marine_num--; }
//};
//int Marine::total_marine_num = 0;
//void Marine::show_total_marine() {
//	std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
//}
//Marine::Marine()
//	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
//	total_marine_num++;
//}
//
//Marine::Marine(int x, int y)
//	: coord_x(x),
//	coord_y(y),
//	hp(50),
//
//	default_damage(5),
//	is_dead(false) {
//	total_marine_num++;
//}
//
//Marine::Marine(int x, int y, int default_damage)
//	: coord_x(x),
//	coord_y(y),
//	hp(50),
//	default_damage(default_damage),
//	is_dead(false) {
//	total_marine_num++;
//}
//
//void Marine::move(int x, int y) {
//	coord_x = x;
//	coord_y = y;
//}
//int Marine::attack() const { return default_damage; }
//Marine& Marine::be_attacked(int damage_earn) {
//	hp -= damage_earn;
//	if (hp <= 0) is_dead = true;
//
//	return *this;
//}
//void Marine::show_status() {
//	std::cout << " *** Marine *** " << std::endl;
//	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
//		<< std::endl;
//	std::cout << " HP : " << hp << std::endl;
//	std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
//}
//
//int main() {
//	Marine marine1(2, 3, 5);
//	marine1.show_status();
//
//	Marine marine2(3, 5, 10);
//	marine2.show_status();
//
//	std::cout << std::endl << "���� 1 �� ���� 2 �� �� �� ����! " << std::endl;
//	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
//
//	marine1.show_status();
//	marine2.show_status();
//}

//#include <iostream>
//
//class A {
//	int x;
//
//public:
//	A(int c) : x(c) {}
//	A(const A& a) {
//		x = a.x;
//		std::cout << "���� ����" << std::endl;
//	}
//};
//
//class B {
//	A a;
//
//public:
//	B(int c) : a(c) {}
//	B(const B& b) : a(b.a) {}
//	A get_A() {
//		A temp(a);
//		return temp;
//	}
//};
//
//int main() {
//	B b(10);
//
//	std::cout << "---------" << std::endl;
//	A a1 = b.get_A();
//}