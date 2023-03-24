#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;
	vector<string> vec{ "ayaaya", "yeye", "woowoo", "mama" };
	vector<string> vec2{ "aya", "ye", "woo", "ma" };
	for (auto& babb : babbling)
	{
	bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (babb.find(vec[i]) != string::npos) //연속인 경우 처리
			{
				flag = true;
				break;
			}

		}

		if (flag) continue;
		for (int j = 0; j < 4; j++)
		{

			while ((babb.find(vec2[j]) != string::npos))
			{
				babb.replace(babb.find(vec2[j]), vec2[j].size(), " ");
			}
		}
        
        while ((babb.find(" ") != string::npos))
			{
				babb.replace(babb.find(" "), 1, "");
			}
        
		if (babb.size() == 0)
		{
			answer++;
		}

	}
	return answer;

}

