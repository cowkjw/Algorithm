#include<iostream>
#include<vector>
using namespace std;



int main()
{

	vector<pair<int, int>> P;
	vector<int> rank;

	int N, w, h;

	cin >> N;
	rank.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> w >> h;
		P.push_back(pair<int, int>(w, h));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i!=j&&(P[i].first < P[j].first && P[i].second < P[j].second))
			{
				rank[i]++; // 작으면 계속 플러스 
			}
			
		}


	}

	for (int i = 0; i < N; i++)
	{
		cout << ++(rank[i]) << " ";
	}


	return 0;
}