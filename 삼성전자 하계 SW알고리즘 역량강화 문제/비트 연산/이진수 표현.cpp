#include <bits/stdc++.h>
using namespace std;


int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		int N, M;
		cin >> N >> M;
		int bitCheck = (1 << N) - 1;  // 1111에서 1을 빼면 111이 됨
		if ((M&bitCheck)==bitCheck) // and연산자로 둘이 같으면 1을 반환
			cout << "ON" << '\n';
		else
			cout << "OFF"<<'\n';
	}



	return 0;

}

