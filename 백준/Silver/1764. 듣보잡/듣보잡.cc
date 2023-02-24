#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> people;

	int N; // 듣도 못한 사람 수
	int M; // 보도 못한 사람의 수
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
	for (int i = 0; i < people.size()-1;)
	{
		if (people[i] == people[i + 1])
		{
			cnt++;
			check.push_back(people[i]);
			i += 2;
		}
		else
			i++;
	}
	cout << cnt << "\n";
	
	for(auto i : check)
		cout << i << "\n";

}

