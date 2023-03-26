#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;


pair<int, int>& Moving(pair<int, int>& pos, const vector<string>& park, char op, int n)
{
    auto h = park.size();
    auto w = park[0].size();

    switch (op)
    {
    case 'N':
		for (int i = 1; i <= n; i++)
		{
			if (pos.first - i < 0 || park[pos.first - i][pos.second] == 'X')
				return pos;
		}
		pos.first -= n;
        break;
    case 'S':
		for (int i = 1; i <= n; i++)
		{
			if (pos.first + i >= h || park[pos.first + i][pos.second] == 'X')
				return pos;
		}
		pos.first += n;
        break;
    case 'W':
		for (int i = 1; i <= n; i++)
		{
			if (pos.second - i <0 || park[pos.first][pos.second-i] == 'X')
				return pos;
		}
		pos.second -= n;
        break;
    case 'E':
		for (int i = 1; i <= n; i++)
		{
			if (pos.second + i >=w || park[pos.first][pos.second + i] == 'X')
				return pos;
		}
		pos.second += n;
        break;
    }

    return pos;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    auto h = park.size();
    auto w = park[0].size();
    pair<int,int> pos;
    
    for(int i = 0;i<h;i++)
    {
        for(int j = 0;j<w;j++)
        {
            if(park[i][j]=='S')
            {
                pos = {i,j};
                break;
            }
        }
    }
    
    for(const auto& route : routes)
    {
        char op = route.front();
        int n = route.back()-'0';// int로
        
        Moving(pos,park,op,n);
        
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    return answer;
}