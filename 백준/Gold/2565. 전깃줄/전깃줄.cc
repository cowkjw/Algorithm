#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n,len,lis[501];
vector<pair<int,int>>v;
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        
        v.push_back({ s,e });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        auto lowerPos = lower_bound(lis, lis + len, v[i].second);
        if (*lowerPos == 0) len++;
        *lowerPos = v[i].second;
    }
    cout << n - len;
}


