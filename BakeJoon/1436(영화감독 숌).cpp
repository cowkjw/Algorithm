#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int cnt = 0;
	cin >> N;
	int six = 665;
	string str;
	while (++six) // 계속 브루트포스로 six를 올려줌
	{
		str = to_string(six); // 문자열로 변환

		if (str.find("666") != str.npos)  // 문자열에 666이 있다면 숌 영화로 count함
			cnt++;
		if (cnt == N) // N번째 영화와 count가 같다면 해당 영화제목 출력
		{
			cout << six;
			break;
		}

	}


	return 0;

}

