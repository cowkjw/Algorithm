#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string A, string B) {

	for (int i = 0; i < A.size(); i++)
	{
		if (A == B) // 같다면 
			return i; // 리턴
		rotate(A.begin(), A.end() - 1, A.end()); // 오른쪽으로 한칸씩

	}
	return -1;
}