#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.rbegin(), score.rend());

    int cnt = 0;
    int minScore = 10;
    for (int i = 0; i < score.size(); i++)
    {

        cnt++;
        minScore = min(minScore, score[i]);
        if (cnt == m)
        {
            answer += (minScore * m);
            cnt = 0;
            minScore = 10;
        }
    }

    return answer;
}