#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321


using ll = long long;
int n, k;

struct Bucket
{
	int x;
	int g;
};
Bucket arr[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

  
    for (int i = 0; i < n; i++)
    {
        int g, x;
        cin >> g >> x;
        arr[i] = { x, g };

    }

    sort(arr, arr + n, [](const Bucket& a, const Bucket& b) {
        return a.x < b.x;
        });

    ll ans = 0, sum = 0;
    int l = 0; 
    for (int r = 0; r < n; r++) 
    {
        sum += arr[r].g;
        while (arr[r].x - arr[l].x > 2 * k) 
        {
            sum -= arr[l].g;
            l++;
        }
        ans = max(ans, sum);
    }

    cout << ans;


    return 0;
}