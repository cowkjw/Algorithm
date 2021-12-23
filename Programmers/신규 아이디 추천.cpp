#include<iostream>
#include <string>


using namespace std;

string solution(string new_id) {

	string answer = "";

	for (int i = 0; i < new_id.size(); i++)
	{
		if (isalpha(new_id[i]))
		{
			if ('A' <= new_id[i] && new_id[i] <= 'Z')
			{
				answer.push_back(tolower(new_id[i])); // �ҹ��ڷ� �ٲ㼭 push
			}
			else
			{
				answer.push_back(new_id[i]);
			}


		}
		else
		{
			if (isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
				answer.push_back(new_id[i]); // �����̰ų� ����� �����϶��� push
		}

	}



	for (int i = 0; i < answer.size(); i++)
	{
		while (true) // . ġȯ ������ ��� ������
		{
			if (answer[i] == '.' && answer[i + 1] == '.')// ���� �� �ڿ��� .�� �´ٸ� �ڿ��� ����
			{
				answer.erase(i + 1, 1);
			}
			else
			{
				break;
			}
		}


	}



	while (true)
	{


		if (answer.front() == '.') // �� �տ� .�� �´ٸ� ����
		{
			answer.erase(0, 1);
		}
		else if (answer.back() == '.')
		{
			answer.erase((answer.size() - 1), 1); // �� �ڿ� .�� �´ٸ� ����

		}
		else if (answer.size() > 15)
		{
			answer.erase(15, answer.size() - 15); // ���� ���ڿ� ���̰� 15���� ũ�ٸ� ����
		}
		else // 3���� ���̽��� �ƹ��͵� �ƴ϶�� ���߱�
		{
			break;
		}


	}

	if (answer.size() <= 2 && !answer.empty()) // ���� �� ���ڿ��� �ƴϰ� ���ڿ� ���̰� 2�� ���϶��
	{
		while (answer.size() < 3)
		{
			answer.push_back(answer.back());

		}

	}
	else if (answer.empty()) // �� ���ڿ��̶�� a�� push
	{
		for (int i = 0; i < 3; i++)
			answer.push_back('a');
	}




	return answer;
}