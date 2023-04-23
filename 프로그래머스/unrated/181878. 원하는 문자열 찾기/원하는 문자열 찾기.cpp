#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(),myString.end(),myString.begin(),::tolower);
    transform(pat.begin(),pat.end(),pat.begin(),::tolower);
    
    return myString.find(pat)!=-1;
}