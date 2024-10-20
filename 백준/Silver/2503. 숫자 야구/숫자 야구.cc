#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <iterator> 
using namespace std;


int n,ans;
vector<vector<int>> numbers;
bool Check(int idx, int num)
{
	string number = to_string(num);
	string hint = to_string(numbers[idx][0]);
	int strike = 0;
	int ball = 0;

	if (number.find('0') != string::npos) return false;
if (number[0] == number[1] || number[0] == number[2] || number[1] == number[2]) return false;

	for (int i = 0; i < 3; i++)
	{
		if (hint[i] == number[i]) strike++;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != j && hint[i] == number[j])
			{
				ball++;
			}
		}
	}
	return (numbers[idx][1] == strike && numbers[idx][2] == ball);
}


void Recur(int hint, int num)
{

	if (num == 1000)
		return;
	if (numbers.size() == hint)
	{
		ans++;
		Recur(0, num + 1);
		return;
	}

	if (Check(hint, num))
	{
		Recur(hint + 1,num);
	}
	else
	{
		Recur(0, num + 1);
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		numbers.push_back({a,b,c});
	}
	Recur(0, 100);
	cout << ans;


	return 0;
}