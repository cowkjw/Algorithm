#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer =1;
    int n = arr[0].size();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]!=arr[j][i])
                return 0;
        }
    }
    return answer;
}