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

	sort(s1.begin(), s1.end()); // ���Ľÿ��� ������ ������ �޼ҵ� �� �� �ֱ⶧���� ����
	sort(s2.begin(), s2.end());

	su.resize(s1.size() + s2.size()); // �̸� ������ ũ�⸦ ����
	auto it = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), su.begin()); // ������
	su.erase(it, su.end());

	s3.resize(s1.size() + s2.size());
	it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin()); // ������
	s3.erase(it, s3.end());
	if (s3.size() != 0 || su.size() != 0) // �����հ� �������� �������� �ƴҰ�츸 
		answer = ((double)s3.size() / (double)su.size()) * 65536;
	else
		return 65536;


	return answer;
}