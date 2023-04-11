#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	queue<int> q;
	stack<int> s;
	bool carry = false;
	for (int i = 1; i <= order.size(); i++)
	{
		q.push(i);
	}
	for (const auto& box : order)
	{

		while (!q.empty() || !s.empty()) // 컨테이너 벨트 보조벨트
		{

			if (!q.empty()&&box == q.front())
			{
				answer++;
				q.pop(); // 뺀다
				break;
			}
			else if (!s.empty() && s.top() == box)
			{
				answer++;
				s.pop();
				break;
			}
			else
			{
				if (!q.empty())
				{
					int front = q.front();
					q.pop(); // 뺀다
					s.push(front); // 보조에 넣음
				}
				else if (q.empty()&&!s.empty())
				{
					return answer;
				}

			}
		}
	}
	return answer;
}