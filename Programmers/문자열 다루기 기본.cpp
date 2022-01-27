#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	bool answer = false;
	int size = s.size();
	if (size == 4 || size == 6)
	{
		for (auto i : s)
		{
			if (!isdigit(i))
			{
				answer = false;
				break;
			}
			else
				answer = true;
		}
	}

	return answer;
}