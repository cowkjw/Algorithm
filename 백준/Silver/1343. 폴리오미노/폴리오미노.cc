#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

string processX(string& tmp, string& ans) {
    int len = tmp.size();
    if (len % 2 != 0)
    {
        ans = "-1";
        return ans;
    }
    while (len >= 4)
    {
        ans += "AAAA";
        len -= 4;
    }
    while (len >= 2)
    {
        ans += "BB";
        len -= 2;
    }
    tmp = "";
    return ans;
}

int main(void)
{
    string str;
    cin >> str;
    string ans;
    string tmp;
    for (const auto& ch : str)
    {
        if (ch == 'X') tmp += ch;
        else
        {
            ans = processX(tmp, ans);
            if (ans == "-1") {
                cout << ans;
                return 0;
            }
            ans += ch;
        }
    }
    ans = processX(tmp, ans);
    if (ans == "-1") {
        cout << ans;
        return 0;
    }
    cout << ans;
    return 0;
}
