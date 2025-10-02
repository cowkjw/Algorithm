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


using ll = long long;

class RecommenderSystem
{
private:
	struct Problem
	{
		int id;
		int level;
		bool operator<(const Problem& other) const
		{
			if (level == other.level)
				return id < other.id; // 난이도가 같으면 id가 큰 순서
			return level < other.level; // 난이도가 높은 순서
		}

		bool operator>(const Problem& other) const
		{
			if (level == other.level)
				return id > other.id; // 난이도가 같으면 id가 작은 순서
			return level > other.level; // 난이도가 낮은 순서
		}
	};

public:
	void Solved(int id)
	{
		problemMap.erase(id);
	}

	void Add(int id, int level)
	{
		problemMap[id] = level;
		maxHeap.push({ id, level });
		minHeap.push({ id, level });
	}

	int Recommend(int x)
	{
		if (x == 1)
		{ // 어려운 문제
			while (!maxHeap.empty())
			{
				auto cur = maxHeap.top();
				if (problemMap.find(cur.id) != problemMap.end() &&
					problemMap[cur.id] == cur.level)
					return cur.id;
				maxHeap.pop(); // 유효하지 않으면 버림
			}
		}
		else 
		{    // 쉬운 문제
			while (!minHeap.empty()) 
			{
				auto cur = minHeap.top();
				if (problemMap.find(cur.id) != problemMap.end() &&
					problemMap[cur.id] == cur.level)
					return cur.id;
				minHeap.pop();
			}
		}
		return 0;
	}
	

private:
	priority_queue<Problem> maxHeap; // 어려운 문제 우선
	priority_queue<Problem, vector<Problem>, greater<Problem>> minHeap; // 쉬운 문제 우선
	unordered_map<int, int> problemMap; // id -> level
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	RecommenderSystem rs;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int id, level;
		cin >> id >> level;
		rs.Add(id, level);
	}
	int req;
	cin >> req;
	for (int i = 0; i < req; i++)
	{
		string command;
		cin >> command;
		if (command == "add")
		{
			int id, level;
			cin >> id >> level;
			rs.Add(id, level);
		}
		else if (command == "solved")
		{
			int id;
			cin >> id;
			rs.Solved(id);
		}
		else if (command == "recommend")
		{
			int x;
			cin >> x;
			cout << rs.Recommend(x) << "\n";
		}
	}


    return 0;
}