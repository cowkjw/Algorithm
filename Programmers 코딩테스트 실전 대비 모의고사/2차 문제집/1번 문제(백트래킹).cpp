#include <string>
#include <vector>
#include<iostream>

using namespace std;

int answer;
int sum;
bool isUsed[15];
vector<int> temp;
void func(int cnt, int x)
{
	if (sum == 0 && cnt == 3)
	{
		answer++;
		return;
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (isUsed[i] || x > i)
			continue;

		isUsed[i] = true;
		sum += temp[i];
		func(cnt + 1, i);
		isUsed[i] = false;
		sum -= temp[i];
	}
}

int solution(vector<int> number) {
	
	temp = number;
	func(0, 0);

	return answer;
}