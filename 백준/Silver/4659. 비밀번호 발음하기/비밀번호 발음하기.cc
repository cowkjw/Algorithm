#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> vowel{"a", "e", "o", "u", "i"};
    while (true) {
        string str;
        cin >> str;
        if (str == "end") break;
        
        bool flag = false;
        for (const string& ch : vowel) 
        {
            if (str.find(ch) != string::npos) 
            {
                flag = true;
                break;
            }
        }
        
        if (!flag) 
        {
            cout << "<" + str + "> is not acceptable.\n";
            continue;
        }

        bool flag2 = true;
        int cntVowel = 0, cntConsonant = 0;
        char prevCh = '\0'; 
        for (char ch : str) 
        {
            if (ch == prevCh && ch != 'e' && ch != 'o') 
            {
                cout << "<" + str + "> is not acceptable.\n";
                flag2 = false;
                break;
            }
            
            if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i') 
            {
                cntVowel++;
                cntConsonant = 0;
            } else {
                cntVowel = 0;
                cntConsonant++;
            }
            
            if (cntVowel == 3 || cntConsonant == 3) 
            {
                cout << "<" + str + "> is not acceptable.\n";
                flag2 = false;
                break;
            }
            
            prevCh = ch;
        }
        
        if (flag2) 
        {
            cout << "<" + str + "> is acceptable.\n";
        }
    }

    return 0;
}