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



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
    stack<char> s;   // 괄호 스택
    stack<int> s2;   // 값 스택

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
            s2.push(-1); // 괄호 시작 지점 표시
        }
        else 
        { // 닫는 괄호
            if (s.empty())
            { 
                cout << 0; 
                return 0; 
            }
            char c = s.top();
            s.pop();

            int mul = (str[i] == ')') ? 2 : 3;
			if ((str[i] == ')' && c != '(') || (str[i] == ']' && c != '[')) // 괄호 짝 안 맞음
            {
                cout << 0;
                return 0;
            }

            int sum = 0;
			while (!s2.empty() && s2.top() != -1)  // 시작 괄호 전까지 값 더하기
            {
                sum += s2.top();
                s2.pop();
            }
            s2.pop(); // -1 제거

			if (sum == 0)  // 이전에 여는 괄호가 없었으면
                s2.push(mul);
            else   // 여는 괄호가 있어서 올바른 괄호처리로 곱하기
                s2.push(sum * mul);
        }
    }


    int ans = 0;
    while (!s2.empty()) 
    {
        if (s2.top() == -1)
        { 
            cout << 0;
            return 0;
        }
        ans += s2.top();
        s2.pop();
    }

    cout << ans << "\n";
    return 0;
}