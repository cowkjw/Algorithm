#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<int>v;
	int l_size = lost.size();
	int r_size = reserve.size();
	answer += (n - l_size);
	list<int> li;

	sort(lost.begin(), lost.end());

	for (int i = 0; i < r_size; i++)
		li.push_back(reserve[i]);

	for (int i = 0; i < l_size; i++) //여분은 있지만 도둑맞은 거 제거
	{
		auto is_me = find(li.begin(), li.end(), lost[i]);
		if (is_me != li.end())
		{
			li.erase(is_me);
			answer++;
			v.push_back(lost[i]);
		}
	}
	for (int i = 0; i < l_size; i++)
	{
		auto used = find(v.begin(), v.end(), lost[i]);
		auto front_it = find(li.begin(), li.end(), lost[i] - 1);
		auto back_it = find(li.begin(), li.end(), lost[i] + 1);

		if (front_it != li.end() && used == v.end())
		{
			li.erase(front_it);
			answer++;
			continue;
		}
		else if (back_it != li.end() && used == v.end())
		{
			li.erase(back_it);
			answer++;
			continue;
		}

	}


	return answer;
}