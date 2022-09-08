#include<string>
#include <iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            char top = st.top();

            if (top == s[i])
            {
                st.push(s[i]);
            }
            else if (top == '(')
            {
                st.pop();
            }
        }
    }

    return st.empty();

}