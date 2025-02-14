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
using namespace std;
unordered_map<string, string> parent;
unordered_map<string, int> cnt;

string& Find(const string& str)
{
	if (parent[str] != str) // 자기 자신이 부모가 아니라면 유니온 되어있다는 뜻
	{
		parent[str] = Find(parent[str]); // str의 부모는 타고 가면서 찾아야함 경로 압축
	}
	return parent[str]; // 찾아서 리턴
}

void Union(string& str, string& str2)
{
	str = Find(str);
	str2 = Find(str2);

	if (str != str2) // 서로의 부모가 다르다면
	{
		// 더 작은 집합을 큰 집합에 합치기 위함
		if (cnt[str] < cnt[str2])
			swap(str, str2); // 더 작은 집합을 큰 집합에 합침

		// str2를 str의 자식으로 설정하여 합침
		parent[str2] = str;

		// str2의 크기를 str에 더함 (두 집합을 합쳤으므로, 합친 크기 업데이트)
		cnt[str] += cnt[str2];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		parent.clear();
		cnt.clear();
		for (int i = 0; i < n; i++)
		{
			string f, f1;
			cin >> f >> f1;

			if (parent.find(f) == parent.end()) // 아직 넣지 않았다면
			{
				parent[f] = f;
				cnt[f] = 1;
			}
			if (parent.find(f1) == parent.end()) 
			{
				parent[f1] = f1;
				cnt[f1] = 1;
			}

			Union(f, f1);

			cout << cnt[f] << '\n';
		}
	}
	return 0;
}