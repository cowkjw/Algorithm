#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> um;
    
    for(int i = 0;i<name.size();i++)
    {
        um[name[i]] = yearning[i];
    }
    
    for(const auto& arr : photo)
    {
        int sum = 0;
        for(const auto& item : arr )
        {
            sum+=um[item]; 
        }
        answer.push_back(sum);
    }
    
    
    return answer;
}