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
				answer.push_back(tolower(new_id[i])); // 소문자로 바꿔서 push
			}
			else
			{
				answer.push_back(new_id[i]);
			}


		}
		else
		{
			if (isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
				answer.push_back(new_id[i]); // 숫자이거나 허락한 문자일때만 push
		}

	}



	for (int i = 0; i < answer.size(); i++)
	{
		while (true) // . 치환 전까지 계속 돌리기
		{
			if (answer[i] == '.' && answer[i + 1] == '.')// 만약 내 뒤에도 .가 온다면 뒤에를 삭제
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


		if (answer.front() == '.') // 맨 앞에 .이 온다면 삭제
		{
			answer.erase(0, 1);
		}
		else if (answer.back() == '.')
		{
			answer.erase((answer.size() - 1), 1); // 맨 뒤에 .이 온다면 삭제

		}
		else if (answer.size() > 15)
		{
			answer.erase(15, answer.size() - 15); // 만약 문자열 길이가 15보다 크다면 삭제
		}
		else // 3가지 케이스가 아무것도 아니라면 멈추기
		{
			break;
		}


	}

	if (answer.size() <= 2 && !answer.empty()) // 만약 빈 문자열도 아니고 문자열 길이가 2자 이하라면
	{
		while (answer.size() < 3)
		{
			answer.push_back(answer.back());

		}

	}
	else if (answer.empty()) // 빈 문자열이라면 a를 push
	{
		for (int i = 0; i < 3; i++)
			answer.push_back('a');
	}




	return answer;
}