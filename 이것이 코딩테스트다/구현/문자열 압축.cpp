#include <string>
#include <vector>

using namespace std;

int solution(string s) {

	int answer = 10001;
	int size = s.size();

	for (int i = 1; i <= size; i++) // 1~size만큼 자르기
	{
		int cnt = 1;
		string ansStr;
		vector<string> v;
		for (int j = 0; j < size; j += i)
		{
			v.push_back(s.substr(j, i)); // i만큼 자른 문자열 벡터에 저장
		}
		int k;
		for (k = 0; k < v.size() - 1; k++)
		{
			if (v[k] == v[k + 1]) // 해당 문자열들 비교해서 같다면
			{
				cnt++; // 카운트
			}
			else // 문자열 비교했을때 같지 않다면 이전까지 개수만큼 압축
			{
				if (cnt > 1) // 1개보다 많으면
				{
					ansStr += to_string(cnt) + v[k];
				}
				else
				{
					ansStr += v[k];
				}
				cnt = 1;
			}
		}
		if (cnt > 1) // 마지막 비교 문자들 넣기 위함
		{
			ansStr += to_string(cnt) + v[k];
		}
		else
		{
			ansStr += v[k];
		}
		answer = min(static_cast<int>(ansStr.size()), answer);
	}
	return answer;
}