#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, people;
	cin >> N;

	vector<int>v(N+1);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	cin >> people;

	for (int i = 0; i < people; i++)
	{
		int gender;
		cin >> gender;
		if (gender == 1)
		{
			int Pos;
			cin >> Pos;
			int temp = Pos;
			while (Pos <= N)
			{
				v[Pos] = !v[Pos];
				Pos += temp;
			}
		}
		else
		{
			int Pos;
			cin >> Pos;
			int left = Pos - 1;
			int right = Pos + 1;
			v[Pos] = !v[Pos];
			while (left >= 1 && right <= N)
			{
				if (v[left] != v[right])
					break;
				v[left] = !v[left];
				v[right] = !v[right];
				left--;
				right++;
			}

		}
	}

	for (int i = 1; i <= v.size()-1; i++)
	{
		cout << v[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}


	return 0;
}




