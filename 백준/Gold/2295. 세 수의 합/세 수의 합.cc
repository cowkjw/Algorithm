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



int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    unordered_set<long long> sumXY;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            sumXY.insert(v[i] + v[j]);
        }
    }


    for (int k = n - 1; k >= 0; k--) 
    { 
        for (int z = 0; z < n; z++) 
        {
            if (sumXY.count(v[k] - v[z]))
            {
                cout << v[k] << "\n";
                return 0;
            }
        }
    }
    
    return 0;
}