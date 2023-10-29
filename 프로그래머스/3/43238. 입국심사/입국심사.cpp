#include <string>
#include <vector>

using namespace std;

long long hi, lo, mid;
bool check(int n, vector<int>& times, long long mid)
{
    long long num = 0;
    for (const auto& i : times)
    {
        num +=mid/i;
    }
    return n <= num;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    lo = 1, hi = 1e18;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(n, times, mid))
        {
            answer = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return answer;
}