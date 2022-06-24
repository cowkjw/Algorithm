#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    list<string> li;

    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].size(); j++)
        {
            if ('A' >= cities[i][j] || cities[i][j] <= 'Z')
                cities[i][j] += 32;
        }



    for (int i = 0; i < cities.size(); i++)
    {
        if (cacheSize == 0)
        {
            answer += 5;
            continue;
        }
        if (li.size() == 0 && cacheSize != 0)
        {
            li.push_front(cities[i]);
            answer += 5;
        }

        else
        {
            auto it = find(li.begin(), li.end(), cities[i]);
            if (it == li.end())
            {
                if (li.size() >= cacheSize)
                {
                    li.pop_back();
                }
                li.push_front(cities[i]);
                answer += 5;
            }
            else
            {
                li.erase(it);
                li.push_front(cities[i]);
                answer++;
            }


        }

    }

    return answer;
}