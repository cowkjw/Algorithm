#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
int num[100001];
int ret;
int arr[4]{ 1,5,10,50 };
void go(int sum,int cnt,int index)
{
	if (cnt == n)
	{
		if(!num[sum])
		  ret++;
	num[sum]= 1;
		return;
	}

	for (int i = index; i < 4; i++)
	{
		go(sum + arr[i], cnt + 1,i);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;


	go(0, 0,0);

	cout << ret;
}