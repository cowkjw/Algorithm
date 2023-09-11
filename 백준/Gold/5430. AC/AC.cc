#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m, t;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--)
	{
		string p, arr;
		cin >> p;
		cin >> n;
		cin >> arr;
		deque<int> dq;
		int x = 0;
		for (auto ch : arr)
		{
			if (isdigit(ch)) x = x * 10 + atoi(&ch);
			else { if (x > 0)dq.push_back(x); x = 0; }
		}
		if (x > 0) dq.push_back(x);

		bool er = false, rev = false;

		for (auto i : p)
		{
			if (i == 'R') rev = !rev;
			else
			{
				if (dq.empty())
				{
					er = true;
					break;
				}

				if (rev) dq.pop_back();
				else dq.pop_front();
			}
		}

		if (er)
		{
			cout << "error\n";
		}
		else
		{
		cout << "[";
			if (rev)
			{
				reverse(dq.begin(), dq.end());
			}

			for (int i = 0; i < dq.size(); i++)
			{
				cout << dq[i];
				if (i < dq.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}
	return 0;
}