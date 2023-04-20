#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    string oper = ineq+eq;
    if(oper=="<=")
    {
        return n<=m;
    }
    else if(oper==">=")
    {
        return n>=m;
    }
    else if(oper=="<!")
    {
        return n<m;
    }
    else if(oper==">!")
    {
        return n>m;
    }
}