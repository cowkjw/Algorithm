#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>>  b)
{

	if (a.second.first == b.second.first) // �������� ������?
	{
		if (a.second.second.first == b.second.second.first) // ���� ���� ������?
			if (a.second.second.second == b.second.second.second) // �������� ������?
				return a.first < b.first; // ���ĺ� ��
			else
				return a.second.second.second > b.second.second.second; // ���� ���� ���� ��

		return a.second.second.first < b.second.second.first; // ���� ������ ���� ��
	}

	return a.second.first > b.second.first; // ���� ������ ���Ҽ�
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> ans;
	vector<pair<string,pair<int, pair<int, int>>>>input;
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		string name;
		cin >> name>>a>>b>>c;
		input.push_back(make_pair(name,(make_pair(a, make_pair(b, c)))));
	}

	sort(input.begin(), input.end(), cmp);

	for (auto i : input)
		cout << i.first<<"\n";

	return 0;

}

