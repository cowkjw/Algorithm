#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int ConvertTime(string str)
{
    int hour = stoi(str.substr(0,2))*60;
    int min = stoi(str.substr(3));
    return hour+min;
}
int solution(vector<vector<string>> book_time) {
    int answer = 1;
    vector<pair<int,int>> v;
    
    for(auto book : book_time)
    {
        int a = ConvertTime(book[0]);
        int b= ConvertTime(book[1]);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    priority_queue<int>pq;
    pq.push(-v[0].second-10);
    for(int i = 1;i<book_time.size();i++)
    {
        if(-pq.top()<=v[i].first)
        {
            pq.pop();
        }
        else
        {
            answer++;
        }
         pq.push(-v[i].second-10);
    }
    return answer;
}