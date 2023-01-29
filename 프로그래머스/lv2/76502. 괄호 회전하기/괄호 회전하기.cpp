#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


	bool Check(const string& s)
	{
		stack<char> st;

		for (int i = 0; i < s.size(); i++)
		{
			if (st.empty())
			{
				st.push(s[i]);
                continue;
			}

			if (st.top() == '(' && s[i] == ')')
			{
				st.pop();
			}
			else if (st.top() == '[' && s[i] == ']')
			{
				st.pop();
			}
			else if (st.top() == '{' && s[i] == '}')
			{
				st.pop();
			}
            else
			{
				st.push(s[i]);
			}

		}
		return st.empty();
	}



int solution(string s) {
    int answer = 0;
    int size = s.size();
    
    for(int i = 0;i<size;i++)
    {
         rotate(s.begin(), s.begin() + 1, s.end());
        if(Check(s)) answer++;
    }
   
    return answer;
}