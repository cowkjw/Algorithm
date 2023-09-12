#include <string>
#include <vector>

using namespace std;

int arr[10000001];
int vis[8];
int answer;
    
bool check(int num)
{
    
    if(num <=1) return false;
    if(num == 2) return true;
    for(int i = 2;i*i<=num;i++)
    {
        if(num%i==0) return false;
    }
    
    return true;
}
void go(string num,int size,string numbers)
{
    if(check(stoi(num)))
    {
        if(!arr[stoi(num)])
        {
          answer++;
        }
    }
    arr[stoi(num)] = 1;
    for(int i = 0;i<size;i++)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        go(num+numbers[i],size,numbers);
        vis[i] = 0;
    }
    
    
    return;
}
int solution(string numbers) {

    for(int i =0;i<numbers.size();i++)
    {
        string num;
        num+=numbers[i];
        vis[i] = 1;
        go(num,numbers.size(),numbers);
        vis[i] = 0;
    }
    return answer;
}