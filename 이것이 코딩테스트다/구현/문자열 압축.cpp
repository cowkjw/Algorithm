#include <string>
#include <vector>

using namespace std;

int solution(string s) {

	int answer = 10001;
	int size = s.size();

	for (int i = 1; i <= size; i++) // 1~size��ŭ �ڸ���
	{
		int cnt = 1;
		string ansStr;
		vector<string> v;
		for (int j = 0; j < size; j += i)
		{
			v.push_back(s.substr(j, i)); // i��ŭ �ڸ� ���ڿ� ���Ϳ� ����
		}
		int k;
		for (k = 0; k < v.size() - 1; k++)
		{
			if (v[k] == v[k + 1]) // �ش� ���ڿ��� ���ؼ� ���ٸ�
			{
				cnt++; // ī��Ʈ
			}
			else // ���ڿ� �������� ���� �ʴٸ� �������� ������ŭ ����
			{
				if (cnt > 1) // 1������ ������
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
		if (cnt > 1) // ������ �� ���ڵ� �ֱ� ����
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