#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
	long long num;
	cin >> num;
	vector<long long>ans;
	
	long long tmp = num;
	for (long long i = 2; i <= sqrt(num); i++)
	{
		while (tmp % i == 0)
		{
			ans.push_back(i);
			tmp /= i;
		}
	}
	if (tmp <=1 == false) ans.push_back(tmp);
	if (ans.size() == 0)
	{
		cout << 1 << endl;
		cout << num;
		return 0;
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (const auto i : ans)
	{
		cout << i << " ";
	}
	return 0;
}