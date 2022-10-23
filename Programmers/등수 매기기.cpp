#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;

    vector<float> avg;

    for (auto i : score)
    {
        avg.push_back((i[0] + i[1]) / (float)2);
    }

    for (int i = 0; i < avg.size(); i++)
    {
        int cnt = 1;
        for (int j = 0; j < avg.size(); j++)
        {
            if (i == j)
                continue;
            if (avg[i] < avg[j])
            {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}