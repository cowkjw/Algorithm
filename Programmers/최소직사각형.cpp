#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width_max = 0;
    int height_max = 0;

    for (auto index : sizes)
    {
        if (index[0] < index[1])
        {
            int temp;
            temp = index[0];
            index[0] = index[1];
            index[1] = temp;
        }

        width_max = max(width_max, index[0]);
        height_max = max(height_max, index[1]);
    }

    answer = width_max * height_max;

    return answer;
}