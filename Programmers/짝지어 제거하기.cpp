int solution(string s)
{
	stack<char>ans;

	for (int i = 0; i < s.size(); i++)
	{
		if (ans.empty())
			ans.push(s[i]);

		if (ans.top() == s[i])
			ans.pop();
		else
			ans.push(s[i]);
	}

	if (ans.empty())
		return 1;

	return 0;

}