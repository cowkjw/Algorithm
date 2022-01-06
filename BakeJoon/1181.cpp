#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(const string& s, const string& s2) // 참조가 값복사 속도가 더 빠르다
{
	if (s.length() == s2.length())
	{
		return s < s2;
	}
	else
	{
		return s.length() < s2.length();
	}

}



int main()
{
	int N;
	vector<string> s;
	string str;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		s.push_back(str);


	}

	sort(s.begin(), s.end(), compare);
	s.erase(unique(s.begin(), s.end()), s.end());


	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << (*it) << "\n";
	}

	return 0;
}