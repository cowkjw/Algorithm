#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
	vector<int> answer;
	for (int idx = 0; idx < query.size(); idx++)
	{
		if (idx % 2 == 0)
		{
			arr.assign(arr.begin(), arr.begin() + query[idx]+1);
		}
		else
		{
			arr.assign(arr.begin() + query[idx], arr.end());
		}
	}
	return arr;
}