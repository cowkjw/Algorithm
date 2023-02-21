#include <string>
#include <vector>
#include <unordered_map>
#include<algorithm>


using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> m;

    for(const auto& item : tangerine)
    {
        m[item]++;
    }
  	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b)
		{return a.second > b.second; });
	int sum = 0;
	for (const auto& item : v)
	{
		answer++;
		sum += item.second;
		if (k <= sum) break; 
    }
    return answer;
}