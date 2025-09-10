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

vector<string> split(string input, string del)
{
	vector<string> retStr;

	long long pos = 0;
	string token = "";
	while ((pos = input.find(del)) != -1)
	{
		token = input.substr(0, pos);
		retStr.push_back(token);
		input.erase(0, pos + del.size());
	}
	retStr.push_back(input);
	return retStr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
    int prevS = 0;
    int prevL = 0;
    bool scriptBroken = false;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;

        // 스크립트가 꼬져있으면 더 이상 기술이 발동되지 않음
        if (scriptBroken) {
            continue;
        }

        if (a == 'K')
        {
            if (prevS) 
            {
                ans++; // 연계 기술 성공 - K만 카운트
                prevS--;
            }
            else 
            {
                // K를 S 없이 사용 -> 스크립트가 꼬임
                scriptBroken = true;
            }
        }
        else if (a == 'R')
        {
            if (prevL)
            {
                ans++; // 연계 기술 성공 - R만 카운트
                prevL--;
            }
            else
            {
                // R을 L 없이 사용 -> 스크립트가 꼬임
                scriptBroken = true;
            }
        }
        else if (a == 'S') 
        {

         
                prevS++; 
        }
        else if (a == 'L')
        {

                prevL++; // 사전 기술은 발동되지 않음, 단지 상태만 설정
        }
        else
        {
       
            ans++;
        }
    }

    cout << ans;
    return 0;
}