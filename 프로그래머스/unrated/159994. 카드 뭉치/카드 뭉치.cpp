#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q1;
    queue<string> q2;

    for(const auto& str : cards1)
    {
        q1.push(str);
    }
    for(const auto& str : cards2)
    {
        q2.push(str);
    }
    
    for(const auto& str : goal)
    {
        if(q1.front()==str)
        {
            q1.pop();
        }
        else if(q2.front()==str)
        {
            q2.pop();
        }
        else
        {
            return "No";
        }
    }
    
    return "Yes";

}