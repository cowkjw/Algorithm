#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> s1;
	vector<string> s2;
	vector<string> s3;
	vector<string> su; 

	string temp;

	for (int i = 0; i < str1.size() - 1; i++)
	{
		if (isalpha(str1[i]))
		{
			temp += tolower(str1[i]);
			while (true)
			{
				if (isalpha(str1[++i]))
				{
					temp += tolower(str1[i--]);
					break;
				}
				else
					break;


			}
			if (temp.size() == 2)
				s1.push_back(temp);
			temp = "";
		}

	}

	for (int i = 0; i < str2.size() - 1; i++)
	{

		if (isalpha(str2[i]))
		{
			temp += tolower(str2[i]);
			while (true)
			{
				if (isalpha(str2[++i]))
				{
					temp += tolower(str2[i--]);
					break;
				}
				else
					break;

			}
			if (temp.size() == 2)
				s2.push_back(temp);

			temp = "";
		}
	}

	sort(s1.begin(), s1.end()); // 정렬시에만 교집합 합집합 메소드 쓸 수 있기때문에 정렬
	sort(s2.begin(), s2.end());

	su.resize(s1.size() + s2.size()); // 미리 집합의 크기를 설정
	auto it = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), su.begin()); // 합집합
	su.erase(it, su.end());

	s3.resize(s1.size() + s2.size());
	it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin()); // 교집합
	s3.erase(it, s3.end());
	if (s3.size() != 0 || su.size() != 0) // 합집합과 교집합이 공집합이 아닐경우만 
		answer = ((double)s3.size() / (double)su.size()) * 65536;
	else
		return 65536;


	return answer;
}