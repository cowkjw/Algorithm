#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int solution(vector<int> food_times, long long k) {

	long long sum = 0; // 효율성

	for (const auto& time : food_times)
	{
		sum += time;
	}

	if (sum <= k) // 총합이 k와 같거나 작다면 먹을 음식이 없음
		return -1;
	sum = 0;
	priority_queue <pair<int, int>>food;
	for (int i = 0; i < food_times.size(); i++)
		food.push({ -food_times[i],i + 1 });

	int n = food.size();
	long long prevEat = 0;

	while ((-food.top().first - prevEat) * n <= k) // 먹은 음식들을 빼기 위해 k보다 작거나 같아야함
	{
		auto curEat = -food.top().first;
		food.pop();
		// 이전 음식의 먹은 시간과 지금 시간의 차 * 남은 음식 수
		k -= (curEat - prevEat) * n;
		n--;
		prevEat = curEat;// 이전 시간 갱신
	}

	vector<int> answer;

	for (int i = 0; i < n; i++)
	{
		answer.push_back(food.top().second);
		food.pop();
	}

	sort(answer.begin(), answer.end());

	return answer[k % n];

}