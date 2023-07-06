#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool EqualVector(const vector<int>& temp, const vector<int>& arr)
{
    if(temp.size()==arr.size())
    {
        for(int i = 0;i<temp.size();i++)
        {
            if(temp[i] != arr[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
    
}

int solution(vector<int> arr) {
    int answer = 0;
    
    vector<int> temp = arr;
    
    while(true)
    {
        
        for(int& num : arr)
        {
            if(num%2==0 && num>=50)
            {
                num/=2;
            }
            else if(num%2!=0 && num<50)
            {
                num = num * 2 + 1;
            }
            
        }

        if(EqualVector(temp,arr))
        {
            return answer;
        }
        
        answer++;
        temp = arr;
    }
    
    return answer;
}