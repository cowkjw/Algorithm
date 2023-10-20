#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
set<int> result;
void johab(vector<int> numbers,vector<int> v,int idx){
    if(v.size()==2){
        result.insert(v[0]+v[1]);
        return;
    }
    for(int i=idx;i<numbers.size();i++)
    {
        v.push_back(numbers[i]);
        johab(numbers,v,i+1);
        v.pop_back();
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> v;
    vector<int> answer;
    johab(numbers,v,0);
    answer.assign(result.begin(), result.end());
    return answer;
}