//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;


class Deque
{

public:
	Deque()
	{

	}
	~Deque()
	{

	}



	void empty()
	{
		if (v.empty())
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	void front()
	{
		if (!v.empty())
			cout << v.front() << "\n";
		else
			cout << -1 << "\n";

	}

	void back()
	{
		if (!v.empty())
			cout << v.back() << "\n";
		else
			cout << -1 << "\n";
	}

	void push_back(int data)
	{
		v.push_back(data);
		_size++;

	}
	void push_front(int data)
	{
		vector<int> temp;

		temp.push_back(data);

		for (int i = 0; i < v.size(); i++)
		{
			temp.push_back(v[i]);
		}
		swap(v, temp);
		_size++;
	}
	void pop_front()
	{
		vector<int> temp;
		if (v.empty())
			cout << -1 << "\n";
		else
		{
			cout << v.front() << "\n";

			for (int i = 1; i < v.size(); i++)
			{
				temp.push_back(v[i]);
			}
			swap(v, temp);
			_size--;
		}
	}
	void pop_back()
	{

		if (v.empty())
			cout << -1 << "\n";
		else
		{
			int temp = v.back();

			v.pop_back();
			cout << temp << "\n";
			_size--;
		}
	}

	void size() { cout<<_size << "\n";}
public:
	int _size = 0;
	vector<int> v;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Deque dp;
	int N;

	cin >> N;

	while (N--)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			int data;
			cin >> data;
			dp.push_front(data);

		}
		else if (str == "push_back")
		{
			int data;
			cin >> data;
			dp.push_back(data);
		}
		else if (str == "pop_front")
		{
			dp.pop_front();
		}
		else if (str == "pop_back")
		{
			dp.pop_back();
		}
		else if (str == "size")
		{
			dp.size();
		}
		else if (str == "empty")
		{
			dp.empty();
		}
		else if (str == "front")
		{
			dp.front();
		}
		else if (str == "back")
		{
			dp.back();
		}
	}

}

