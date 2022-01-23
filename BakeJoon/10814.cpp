#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> people1, pair<int, string> people2)
{
	return people1.first < people2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	vector<pair<int, string>> people;
	int age;
	string name;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		people.push_back(pair<int, string>(age, name));
	}
	stable_sort(people.begin(), people.end(), compare); // 입력 순서 유지위해서

	for (int i = 0; i < people.size(); i++)
	{
		cout << people[i].first << " " << people[i].second << "\n";
	}



}