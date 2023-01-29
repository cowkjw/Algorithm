#include <string>
#include <vector>

using namespace std;

int GCD(int a,int b)
{
    return b? GCD(b,a%b) : a;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int lcm = denom1*denom2/GCD(denom1,denom2); // 최소 공배수
    int temp1 = (lcm/denom1)*numer1;
    int temp2 = (lcm/denom2)*numer2;
    
    int gcd = GCD(lcm,temp1+temp2);

    answer.push_back((temp1+temp2)/gcd);
    answer.push_back(lcm/gcd);
    
    
    // 2 4 // 1/3   //6+4/12 10 / 12 10/
    return answer;
}