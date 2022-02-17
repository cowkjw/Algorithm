#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int isZero = 0;
    int winners = 0;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            isZero++;
            continue;
        }
        else
        {
            for (int j = 0; j < win_nums.size(); j++)
            {
                if (lottos[i] == win_nums[j])
                {
                    winners++;
                }
            }
        }

    }


    if (winners == 0 && isZero > 0)
    {
        answer.push_back(7 - (winners + isZero));
        answer.push_back(6 - winners);
    }
    else if (isZero == 0 && winners == 0)
    {
        answer.push_back(6);
        answer.push_back(6);
    }
    else
    {
        answer.push_back(7 - (winners + isZero));
        answer.push_back(7 - winners);
    }

    return answer;
}