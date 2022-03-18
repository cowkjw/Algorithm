#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);




	int T, num, index;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		priority_queue<int> impoQ;
		queue<pair<int, int>> Q;

		int cnt = 0;
		cin >> num >> index;

		for (int i = 0; i < num; i++)
		{
			int importance;
			cin >> importance;

			Q.push(make_pair(i, importance));
			impoQ.push(importance);
		}

		while (!Q.empty())
		{
			int docIndex = Q.front().first;
			int docImportance = Q.front().second;

			if (impoQ.top() > docImportance) // �켱���� ť�� ���� �ڽź��� ���� �켱������ �ִٸ�
			{
				Q.push(Q.front());  // ���� �ٽ� �ڷ� �ִ´�
				Q.pop();
			}
			else
			{
				Q.pop(); // �ƴ϶�� ť�� pop�ϰ� �켱���� ť���� pop�� �Ѵ�
				impoQ.pop();
				cnt++; 

				if (docIndex == index) // �ش� �ε������� �Ǵ�
				{
					cout << cnt << "\n";
					break;
				}

				
			}

		}

	}

}





