#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string A, string B) {

	for (int i = 0; i < A.size(); i++)
	{
		if (A == B) // ���ٸ� 
			return i; // ����
		rotate(A.begin(), A.end() - 1, A.end()); // ���������� ��ĭ��

	}
	return -1;
}