#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(auto& ch : str)
    {
        if(ch>='a')
        {
            ch = toupper(ch);
        }
        else
        {
            ch = tolower(ch);
        }
    }
    cout<<str;
    return 0;
}