#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

float go(string c)
{
	if (c == "A+") return 4.5f;
	else if (c == "A0") return 4.0f;
	else if (c == "B+") return 3.5f;
	else if (c == "B0") return 3.0f;
	else if (c == "C+") return 2.5f;
	else if (c == "C0") return 2.0f;
	else if (c == "D+") return 1.5f;
	else if (c == "D0") return 1.0f;
	else return 0.0f;

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 20;
	float  total = 0;
	float sum = 0;
	while (n--)
	{
		string a, b, c;
		cin >> a >> b >> c;
		if (c == "P") continue;
		total += stof(b);
		sum+=stof(b)* go(c);
	}
	cout << (sum / total);
	return 0;
}