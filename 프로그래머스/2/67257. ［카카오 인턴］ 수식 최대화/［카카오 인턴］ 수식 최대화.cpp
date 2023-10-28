#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long calc(long long a, long long b, char op)
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}
long long solution(string expression) {
	vector<long long> nums;
	vector<char> ops;
	string num;
	for (char c : expression)
	{
		if (isdigit(c))
		{
			num += c;
		}
		else 
		{
			nums.push_back(stoll(num));
			num = "";
			ops.push_back(c);
		}
	}
	nums.push_back(stoll(num));

	vector<char> op_order{ '*', '+', '-' };
	long long answer = 0;
	do {
		vector<long long> tmp_nums = nums;
		vector<char> tmp_ops = ops;
		for (char op : op_order) 
		{
			for (int i = 0; i < tmp_ops.size(); ++i)
			{
				if (tmp_ops[i] == op) 
				{
					tmp_nums[i] = calc(tmp_nums[i], tmp_nums[i + 1], op);
					tmp_nums.erase(tmp_nums.begin() + i + 1);
					tmp_ops.erase(tmp_ops.begin() + i);
					--i;
				}
			}
		}
		answer = max(answer, abs(tmp_nums[0]));
	} while (next_permutation(op_order.begin(), op_order.end()));

	return answer;
}
