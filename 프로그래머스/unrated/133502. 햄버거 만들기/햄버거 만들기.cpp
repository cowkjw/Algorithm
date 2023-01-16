#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	string str;

	for (const auto& item : ingredient)
	{
		str += to_string(item);

		if (str.size() >= 4)
		{
			if (str.substr(str.size() - 4) == "1231")
			{
				str = str.substr(0, str.size() - 4);
				answer++;
			}
		}
	}


	return answer;
}