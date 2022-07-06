#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>>  b)
{

	if (a.second.first == b.second.first) // 국어점수 같은가?
	{
		if (a.second.second.first == b.second.second.first) // 영어 점수 같은가?
			if (a.second.second.second == b.second.second.second) // 수학점수 같은가?
				return a.first < b.first; // 알파벳 순
			else
				return a.second.second.second > b.second.second.second; // 수학 점수 감소 순

		return a.second.second.first < b.second.second.first; // 영어 점수가 증가 순
	}

	return a.second.first > b.second.first; // 국어 점수가 감소순
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

