#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> people;

	int N; // �赵 ���� ��� ��
	int M; // ���� ���� ����� ��
	int cnt = 0;

	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		string person;

		cin >> person;
		people.push_back(person);
	}

	sort(people.begin(), people.end());

	vector<string> check;
	for (int i = 0; i < people.size() - 1; i++)
	{
		if (people[i] == people[i + 1])
		{
			cnt++;
			check.push_back(people[i]);
		}
	}
	cout << cnt << "\n";
	for (auto it = check.begin(); it != check.end(); ++it)
		cout << (*it) << "\n";

}

