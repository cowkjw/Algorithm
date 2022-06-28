#include <string>
#include <vector>
#include <cctype>
#include <algorithm>


using namespace std;

bool comp(pair<string, pair<string, int>> a, pair<string, pair<string, int>> b)
{

	transform(a.first.begin(), a.first.end(), a.first.begin(), ::tolower);
	transform(b.first.begin(), b.first.end(), b.first.begin(), ::tolower);
	if (a.first == b.first)
	{
		if (a.second.first == b.second.first)
			return a.second.second < b.second.second; //stable index
		return stoi(a.second.first) < stoi(b.second.first);
	}
	return a.first < b.first;
}


vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<pair<string, pair<string, int>>> hArr;
	bool isHead = true;

	for (int i = 0; i < files.size(); i++)
	{
		string HEAD, NUMBER;
		for (int j = 0; j < files[i].size(); j++)
		{

			if (isHead)
			{
				if (isdigit(files[i][j]))
				{
					isHead = false;
					NUMBER += files[i][j];
				}
				else
					HEAD += files[i][j];
			}
			else if (!isHead)
			{
				if (isdigit(files[i][j]))
					NUMBER += files[i][j];
				else
					break;
			}

		}
		hArr.push_back(make_pair(HEAD, make_pair(NUMBER, i)));  // 헤드, 넘버, 인덱스
		isHead = true;
	}

	stable_sort(hArr.begin(), hArr.end(), comp);
	for (auto i : hArr)
	{

		answer.push_back(files[i.second.second]);
	}
	return answer;

}