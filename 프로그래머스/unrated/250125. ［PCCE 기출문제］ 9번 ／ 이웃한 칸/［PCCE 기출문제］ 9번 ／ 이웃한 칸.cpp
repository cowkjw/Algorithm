#include <string>
#include <vector>

using namespace std;

const int dh[]={0,1,-1,0};
const int dw[]={1,0,0,-1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int size = board.size();
    for(int i = 0;i<4;i++)
    {
        int nh = dh[i]+h;
        int nw = dw[i]+w;
        if(nh<0||nw<0||nh>=size||nw>=size) continue;
        if(board[h][w]==board[nh][nw]) answer++;
    }
    return answer;
}