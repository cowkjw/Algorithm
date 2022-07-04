#include <bits/stdc++.h>
using namespace std;


class Set
{
public:
	Set()
	{
		v.resize(21);
	}
	~Set()
	{}


	void add(int N)
	{
		if (!v[N])
			v[N] = true;

	}
	void remove(int N)
	{
		if (v[N])
			v[N] = false;

	}
	void check(int N)
	{
		if (v[N])
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}

	}
	void toggle(int N)
	{
		if (v[N])
			v[N] = false;
		else
			v[N] = true;
	}
	void all()
	{
		for (int i = 1; i <= 20; i++)
			v[i] = true;
	}
	void empty()
	{
		vector<bool> temp(21);
		v = temp;
	}

private:
	vector<bool> v;
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	Set s;

	string str;

	while (N--)
	{
		cin >> str;
		if (str == "add")
		{
			int num;
			cin >> num;
			s.add(num);
		}
		else if (str == "remove")
		{
			int num;
			cin >> num;
			s.remove(num);
		}
		else if (str == "check")
		{
			int num;
			cin >> num;
			s.check(num);
		}
		else if (str == "toggle")
		{
			int num;
			cin >> num;
			s.toggle(num);
		}
		else if (str == "all")
		{
			s.all();
		}
		else if (str == "empty")
		{
			s.empty();
		}
	}


	return 0;

}

