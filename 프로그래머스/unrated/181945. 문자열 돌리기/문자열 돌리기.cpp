#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(const auto& ch : str)
    {
        cout<<ch<<endl;
    }
    return 0;
}