#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int solution(vector<int> food_times, long long k) {

	long long sum = 0; // ȿ����

	for (const auto& time : food_times)
	{
		sum += time;
	}

	if (sum <= k) // ������ k�� ���ų� �۴ٸ� ���� ������ ����
		return -1;
	sum = 0;
	priority_queue <pair<int, int>>food;
	for (int i = 0; i < food_times.size(); i++)
		food.push({ -food_times[i],i + 1 });

	int n = food.size();
	long long prevEat = 0;

	while ((-food.top().first - prevEat) * n <= k) // ���� ���ĵ��� ���� ���� k���� �۰ų� ���ƾ���
	{
		auto curEat = -food.top().first;
		food.pop();
		// ���� ������ ���� �ð��� ���� �ð��� �� * ���� ���� ��
		k -= (curEat - prevEat) * n;
		n--;
		prevEat = curEat;// ���� �ð� ����
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