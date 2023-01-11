#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {

	for (const auto& c : before)
	{
		int idx = after.find(c);
		if (idx == string::npos)
		{
			return 0;
		}

		after.erase(after.begin() + idx);
	}

	return 1;
}