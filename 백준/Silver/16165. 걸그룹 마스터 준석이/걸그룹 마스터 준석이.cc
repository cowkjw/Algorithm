#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321

vector<int> graph[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, string> m; // 이름, 속한 걸그룹
	map<string, vector<string>> m2; // 속한 걸그룹, 이름들

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		string group_name;
		cin >> group_name;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			string name;
			cin >> name;
			m[name] = group_name; // 이름, 속한 걸그룹
			m2[group_name].push_back(name); // 속한 걸그룹, 이름들
		}
		sort(m2[group_name].begin(), m2[group_name].end()); // 이름 정렬
	}

	for (int i = 0; i < b; i++)
	{
		string name;
		cin >> name;
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << m[name] << "\n"; // 이름에 해당하는 걸그룹 출력
		}
		else
		{
			for (const auto& [group_name, names] : m2) // 걸그룹에 속한 이름들 출력
			{
				if (group_name == name)
				{
					for (const auto& n : names)
					{
						cout << n << "\n"; // 이름들 출력
					}
					break;
				}
			}
		}
	}

	return 0;
}