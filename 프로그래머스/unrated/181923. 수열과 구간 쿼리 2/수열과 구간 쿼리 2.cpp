#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(const auto query : queries)
    {
        vector<int> v(arr.begin()+query[0],arr.begin()+query[1]+1);
        int minNum = 1000001;
        for(const auto num : v)
        {
            if(query[2]<num)
            {
                minNum = min(num,minNum);
            }
        }
        answer.push_back((minNum == 1000001 ? -1 : minNum));
    }
    return answer;
}