#include <string>
#include <vector>
#include <stack>
#include<queue>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	queue<int> seq;
	stack<int> sub;
	for (auto i : order)
	{
		seq.push(i);
	}
	int box = 1;
	while (!seq.empty())
	{
		int first = seq.front();

		if (box == first)
		{
			seq.pop();
			box++;
			answer++;
			continue;
		}
		else
		{
			for (; box < first; box++)
			{
				sub.push(box);
			}
		}
		if (!sub.empty())
		{
			if (sub.top() == first)
			{
				seq.pop();
				sub.pop();
				answer++;
			}
			else if (box == first)
			{
				seq.pop();
				answer++;
				box++;
			}
			else
			{
				return answer;
			}
		}

	}


	return answer;
}