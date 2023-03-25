#include <string>
#include <vector>
#include <bitset>

using namespace std;

string solution(string bin1, string bin2) {
	string answer = "";
	bitset<10>bit1(bin1);
	bitset<10>bit2(bin2);
	int n1 = bit1.to_ulong();	
	int n2 = bit2.to_ulong();	
	int num = n1 + n2;
	bitset<11>bit3(num);
	answer = bit3.to_string();
    for(int i = 0;i<answer.size();i++)
    {
        if(answer[i]=='0'&&answer[i+1]=='1')
        {
            answer = answer.substr(i+1);
            break;
        }
    }
	if(answer[0]=='0')
        return "0";
	return answer;
}