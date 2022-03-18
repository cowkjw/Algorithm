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

			if (impoQ.top() > docImportance) // 우선순위 큐에 아직 자신보다 높은 우선순위가 있다면
			{
				Q.push(Q.front());  // 빼서 다시 뒤로 넣는다
				Q.pop();
			}
			else
			{
				Q.pop(); // 아니라면 큐를 pop하고 우선순위 큐에도 pop을 한다
				impoQ.pop();
				cnt++; 

				if (docIndex == index) // 해당 인덱스인지 판단
				{
					cout << cnt << "\n";
					break;
				}

				
			}

		}

	}

}





