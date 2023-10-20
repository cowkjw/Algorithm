#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
vector<int> result;
void johab(vector<int> numbers,vector<int> v,int idx){
    if(v.size()==2){
        result.push_back(v[0]+v[1]);
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
    johab(numbers,v,0);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}