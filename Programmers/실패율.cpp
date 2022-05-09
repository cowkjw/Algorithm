#include <bits/stdc++.h>
using namespace std;


vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	multimap<double, int, greater<double>> m;

	double fail;
	int challenger;
	int size = stages.size();
	double failPer;

	for (int i = 1; i <= N; i++)
	{
		fail = 0;
		for (auto stage : stages)
		{

			if (stage == i)
				fail += 1;
		}
		challenger = size;
		size -= fail;

		failPer = fail / challenger;

		m.insert(make_pair(failPer, i));
	}


	for (auto iter = m.begin(); iter != m.end(); ++iter)
		answer.push_back(iter->second);

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	solution(4, { 4, 4, 4, 4, 4 });



}







