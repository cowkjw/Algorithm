#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

int main()
{
    int n, t, p;
    cin >> n;
    vector<int> vec(6, 0);
    int ans1 = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> vec[i];
    }

    cin >> t >> p;
    for (int num : vec)
    {
        if (num > t) // 나누어지면 최소 필요한 거 반올림
        {
            ans1 += (num + t - 1) / t; // 올림 처리
        }
        else // t보다 작으면 일단 1묶음만 있어도 된다 (필요 없는 경우는 0으로)
        {
            ans1 += num == 0 ? 0 : 1;
        }

    }

    cout << ans1 << '\n';
    cout << n / p << " " << n % p;

    return 0;
}
