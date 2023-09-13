#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int arr[100001];
int n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int s = 0;
	int e = n - 1;
	int pre = abs(arr[s]+arr[e]);
	vector<int> answer(2);
	while (s < e)
	{
		int sum = arr[s] + arr[e];
		if (pre >= abs(sum))
		{
			pre = abs(sum);
			answer[0] = arr[s];
			answer[1] = arr[e];
		}
		if (sum < 0)
		{
			s++;
		}
		else
		{
			e--;
		}
	}
	cout << answer[0]<<" "<<answer[1];

	return 0;
}