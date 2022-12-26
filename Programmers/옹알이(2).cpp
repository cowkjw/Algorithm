#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;
	vector<string> vec{ "ayaaya", "yeye", "woowoo", "mama" }; // 연속된 경우
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

		if (flag) continue; // 연속이였다면 다음으로
		for (int j = 0; j < 4; j++)
		{

			while ((babb.find(vec2[j]) != string::npos))
			{
				babb.replace(babb.find(vec2[j]), vec2[j].size(), " "); // 찾아서 " "로 대체
			}
		}

		while ((babb.find(" ") != string::npos))
		{
			babb.replace(babb.find(" "), 1, ""); // " " 를 찾아서 ""로 변환 (myea 같은 경우 ""로 바꿨다면 ma가 되어 옹알이 처리)
		}

		if (babb.size() == 0) // ""로 되어있는 문자열이라면
		{
			answer++;
		}

	}
	return answer;

}

