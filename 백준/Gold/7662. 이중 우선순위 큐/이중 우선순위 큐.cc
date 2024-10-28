#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        priority_queue<int> max_pq; // 최대 힙 (최댓값 우선)
        priority_queue<int, vector<int>, greater<int>> min_pq; // 최소 힙 (최솟값 우선)
        unordered_map<int, int> count_map; // 각 값의 존재 여부 및 횟수 관리

        while (n--) {
            string cmd;
            int num;
            cin >> cmd >> num;

            if (cmd == "I") 
            {
                max_pq.push(num);
                min_pq.push(num);
                count_map[num]++;
            }
            else if (cmd == "D") 
            {
                if (num == 1) 
                { // 최댓값 제거
                    while (!max_pq.empty() && count_map[max_pq.top()] == 0) 
                    {
                        max_pq.pop();
                    }
                    if (!max_pq.empty()) 
                    {
                        count_map[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                else if (num == -1) 
                { // 최솟값 제거
                    while (!min_pq.empty() && count_map[min_pq.top()] == 0) 
                    {
                        min_pq.pop();
                    }
                    if (!min_pq.empty())
                    {
                        count_map[min_pq.top()]--;
                        min_pq.pop();
                    }
                }
            }
        }

        while (!max_pq.empty() && count_map[max_pq.top()] == 0) 
        {
            max_pq.pop();
        }
        while (!min_pq.empty() && count_map[min_pq.top()] == 0) 
        {
            min_pq.pop();
        }

        if (max_pq.empty() || min_pq.empty())
        {
            cout << "EMPTY\n";
        }
        else 
        {
            cout << max_pq.top() <<" " << min_pq.top() << '\n'; // 최솟값
        }
    }

    return 0;
}
