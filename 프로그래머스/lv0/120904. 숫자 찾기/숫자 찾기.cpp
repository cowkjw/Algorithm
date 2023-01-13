#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int num, int k) {
    string str = to_string(num);
    return str.find(k+'0')!=string::npos? str.find(k+'0')+1:-1;
}