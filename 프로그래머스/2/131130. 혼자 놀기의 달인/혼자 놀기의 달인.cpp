#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int vis[101];
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> an;
    for (int i = 0; i < cards.size(); i++)
    {
        int cnt = 0;
        int idx = i;
        while (1)
        {
            if (vis[idx])
            {
                if (cnt != 0)
                {
                    an.push_back(cnt);
                }
                break;
            }
            cnt++;
            vis[idx] = 1;
            idx = cards[idx] - 1;
        }
    }
    sort(an.begin(), an.end());
    answer = an[an.size() - 1] * an[an.size() - 2];
    return answer;
}