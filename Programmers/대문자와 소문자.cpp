#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    transform(my_string.begin(), my_string.end(), my_string.begin(),
        [&](unsigned char c) { return isupper(c) ? tolower(c) : toupper(c); });
    return my_string;
}