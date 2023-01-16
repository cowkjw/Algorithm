#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	priority_queue<int> pq;
	int deleteCnt = 0;

	for (auto& str : operations)
	{
		if (str.front() == 'I')
		{
			pq.push(stoi(str.substr(2)));
		}
		else if (str.front() == 'D')
		{
			if (str.substr(2) == "1")
			{
				if(!pq.empty())
				{
					if(deleteCnt!=pq.size())
					pq.pop();
				}
			}
			else
			{if(!pq.empty())
				deleteCnt++;
			}
		}
	}
	while (!pq.empty())
	{
		answer.push_back(pq.top());
		pq.pop();
	}
	for (int i = 0; i < deleteCnt; i++)
	{
       
		answer.pop_back();
	}
		return answer.empty() ? vector<int>{0, 0} : vector<int>{*max_element(answer.begin(),answer.end()), *min_element(answer.begin(),answer.end()) };
}