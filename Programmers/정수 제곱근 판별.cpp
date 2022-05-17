#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;

	if (n == 1)
		answer = 4;
	else
	{
		for (long long i = 1; i <= n / 2; i++)
		{
			if (i * i == n)
			{
				answer = (i + 1) * (i + 1);
				break;
			}
			else
				answer = -1;
		}
	}


	return answer;
}