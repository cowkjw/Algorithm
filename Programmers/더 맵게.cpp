#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int first;
	int second;
	int size = scoville.size() - 1;
	priority_queue <int, vector<int>, greater<int> > minheap;

	for (auto i : scoville)
		minheap.push(i);


	while (size--)
	{
		first = minheap.top();
		if (!minheap.empty())
			minheap.pop();
		second = minheap.top();
		if (!minheap.empty())
			minheap.pop();


		minheap.push(first + (second * 2));
		answer++;
		if (K <= minheap.top())
			return answer;
	}

	return -1;


}