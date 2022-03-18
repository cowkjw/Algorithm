#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N;
	cin >> N;
	vector<pair<int,int>> v;

	for (int i = 0; i < N; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back(make_pair(num1, num2));
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i.first << " " << i.second << "\n";
	//for (int j = 0; j < N-1; j++)
	//{

	//	for (int i = j+1; i < N; i++)
	//	{

	//		if (v[j][0] > v[i][0])
	//		{
	//			int tempX = v[j][0];
	//			v[j][0] = v[i][0];
	//			v[i][0] = tempX;

	//			int tempY = v[j][1];
	//			v[j][1] = v[i][1];
	//			v[i][1] = tempY;
	//			
	//		}
	//		else if (v[j][0] == v[i][0])
	//		{
	//			if (v[j][1] > v[i][1])
	//			{

	//				int tempY = v[j][1];
	//				v[j][1] = v[i][1];
	//				v[i][1] = tempY;
	//			
	//			}
	//			else if (v[j][1] < v[i][1])
	//			{

	//				int tempY = v[i][1];
	//				v[i][1] = v[j][1];
	//				v[j][1] = tempY;
	//				
	//			}
	//		}
	//	}

	//}




}




