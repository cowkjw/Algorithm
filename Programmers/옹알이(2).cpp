#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;
	vector<string> vec{ "ayaaya", "yeye", "woowoo", "mama" }; // ���ӵ� ���
	vector<string> vec2{ "aya", "ye", "woo", "ma" };
	for (auto& babb : babbling)
	{
		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (babb.find(vec[i]) != string::npos) //������ ��� ó��
			{
				flag = true;
				break;
			}

		}

		if (flag) continue; // �����̿��ٸ� ��������
		for (int j = 0; j < 4; j++)
		{

			while ((babb.find(vec2[j]) != string::npos))
			{
				babb.replace(babb.find(vec2[j]), vec2[j].size(), " "); // ã�Ƽ� " "�� ��ü
			}
		}

		while ((babb.find(" ") != string::npos))
		{
			babb.replace(babb.find(" "), 1, ""); // " " �� ã�Ƽ� ""�� ��ȯ (myea ���� ��� ""�� �ٲ�ٸ� ma�� �Ǿ� �˾��� ó��)
		}

		if (babb.size() == 0) // ""�� �Ǿ��ִ� ���ڿ��̶��
		{
			answer++;
		}

	}
	return answer;

}

