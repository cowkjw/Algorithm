#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    
  int i = sqrt(n);
    return i * i == n ? 1 : 2;
}