#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string,int> um; // 이름 등수
    
    for(int i = 0;i<players.size();i++)
    {
        um[players[i]] = i;
    }
    
    for(const auto& calling : callings)
    {
        swap(players[um[calling]], players[um[calling] - 1]); // 등수 변경
		um[players[um[calling]]] += 1; // 앞의 등수를 뒤의 등수로 변경
		um[calling] -= 1; // 현재 등수를 앞의 등수로
    }
    
    
    
    return players;
}