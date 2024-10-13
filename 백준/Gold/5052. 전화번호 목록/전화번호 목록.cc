#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int t,n;

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<string> vec;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			vec.push_back(str);
		}

		sort(vec.begin(), vec.end());

		bool flag = true;
		for (int i = 0; i < vec.size() - 1; i++)
		{
			int len = vec[i].size();

			if (vec[i] == vec[i+1].substr(0, len))
			{
				flag = false;
				break;
			}
		}

		if (!flag) cout << "NO\n";
		else cout << "YES\n";

	}

	return 0;
}