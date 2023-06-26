#include <string>
#include <vector>

using namespace std;

vector<int> SliceNumList(const vector<int>& vec,int a,int b,int c)
{
    vector<int> temp;
    for(int i = a;i<=b;i+=c)
    {
        temp.push_back(vec[i]);
    }
    return temp;
}


vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int a = slicer[0];
    int b = slicer[1];
    int c = slicer[2];
    switch(n)
    {
        case 1:
            answer.assign(num_list.begin(),num_list.begin()+b+1);
            break;
        case 2:
            answer.assign(num_list.begin()+a,num_list.end());
            break;
        case 3:
            answer.assign(num_list.begin()+a,num_list.begin()+b+1);
            break;
        case 4: 
            answer = SliceNumList(num_list,a,b,c);
            break;
    }
    return answer;
}