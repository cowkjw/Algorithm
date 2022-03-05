#include <string>
#include <vector>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<pair<int, int>> v = {
  {3, 1}, {0, 0}, {0, 1}, {0, 2},
  {1, 0}, {1, 1}, {1, 2},
  {2, 0}, {2, 1}, {2, 2},
  {3, 0}, {3, 2}
    };

    int setL = 10;
    int setR = 11;

    for (auto i : numbers)
    {
        if (i == 1 || i == 4 || i == 7)
        {
            answer += "L";
            setL = i;
        }
        else if (i == 3 || i == 6 || i == 9)
        {
            answer += "R";
            setR = i;
        }
        else
        {
            int disL =
                abs(v[i].first - v[setL].first) + abs(v[i].second - v[setL].second);
            int disR =
                abs(v[i].first - v[setR].first) + abs(v[i].second - v[setR].second);

            if (disL == disR)
            {
                if (hand == "left")
                {
                    answer += "L";
                    setL = i;
                }
                else
                {
                    answer += "R";
                    setR = i;
                }
            }
            else if (disL < disR)
            {
                answer += "L";
                setL = i;
            }
            else
            {
                answer += "R";
                setR = i;
            }
        }
    }


    return answer;
}