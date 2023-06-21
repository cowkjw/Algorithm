#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string binomial) {
    int answer = 0;
    stringstream ss(binomial);
    string first, second, third;
    ss >> first >> second >> third;
    int a = stoi(first);
    int b = stoi(third);
    switch(second[0])
    {
        case '+':
            answer = a + b;
            break;
        case '-':
            answer = a - b;
            break;
        case '*':
            answer = a * b;
            break;
    }
    return answer;
}