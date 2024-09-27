#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int minBill = min(bill[0],bill[1]);
    int maxBill = max(bill[0],bill[1]);
    int minWallet = min(wallet[0],wallet[1]);
    int maxWallet = max(wallet[0],wallet[1]);
    while(minWallet<minBill||maxWallet<maxBill)
    {
        if(bill[0]>bill[1]) bill[0]/=2;
        else bill[1]/=2;
        minBill = min(bill[0],bill[1]);
        maxBill = max(bill[0],bill[1]);
        answer++;
    }
    return answer;
}