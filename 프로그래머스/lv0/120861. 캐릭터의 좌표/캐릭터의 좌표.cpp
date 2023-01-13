#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer{0,0};
    
    for(const auto& cmd : keyinput)
    {
        if(cmd=="left")
        {
            if(board[0]/2>=abs(answer[0]+-1))
            answer[0]+=-1;
        }
        else if(cmd=="right")
        {
            if(board[0]/2>=abs(answer[0]+1))
            answer[0]+=1;
        }
        else if(cmd == "up")
        {if(board[1]/2>=abs(answer[1]+1))
            answer[1]+=1;
        }
        else if(cmd=="down")
        {
            if(board[1]/2>=abs(answer[1]+-1))
                answer[1]+=-1;
        }
    }
    
    
    return answer;
}