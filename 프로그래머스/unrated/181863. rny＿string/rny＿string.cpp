#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    int idx = 0;
    while((idx = rny_string.find("m"))!=-1)
    {
        rny_string.replace(idx,1,"rn");
    }
    return rny_string;
}