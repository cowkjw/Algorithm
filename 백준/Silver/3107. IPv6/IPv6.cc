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

    string str;
    cin >> str;
	vector<string> vec = split(str, ":");

	int countEmpty = count(vec.begin(), vec.end(), "");
	if (countEmpty > 1)
	{
		auto it = find(vec.begin(), vec.end(), "");
		vec.erase(it);
	}
    int need = 9 - vec.size(); // 채워야 할 그룹 수

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == "")
        {
            for (int j = 0; j < need; j++)
            {
                cout << "0000";
                if (!(i == vec.size() - 1 && j == need - 1)) // 끝이 아니면
                    cout << ":";
            }
        }
        else
        {
            string seg = vec[i];
            while (seg.size() < 4)
                seg = '0' + seg;
            cout << seg;
            if (i != vec.size() - 1)  // 여기도 끝이 아니면 : 을 붙임
                cout << ":";
        }
    }
    cout << "\n";

	return 0;
}