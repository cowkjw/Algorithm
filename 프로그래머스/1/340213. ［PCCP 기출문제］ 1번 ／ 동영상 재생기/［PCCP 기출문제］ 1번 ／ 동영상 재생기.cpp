#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Check_Start_Pos(const int& pos, const int& s, const int& e)
{
    if(s <= pos && pos <= e)
    {
        return e;
    }
    
    return pos;
}

string Convert_Time_To_String(int t, bool isMin)
{
    string tmpString("");
    if(isMin)
    {
        tmpString = to_string((t/60));
        while(tmpString.size()<2)
        {
            tmpString = "0" + tmpString;
        }
    }
    else
    {
        tmpString = to_string((t%60));
        while(tmpString.size()<2)
        {
            tmpString = "0" + tmpString;
        }
    }
    return tmpString; 
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int total_Video_Len = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,2));
    int start = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,2));
    int end = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,2));
    int iPos = stoi(pos.substr(0,2)) * 60 + stoi(pos.substr(3,2));
    int tmpTime = Check_Start_Pos(iPos,start,end);
   
    for(const auto& com : commands)
    {
        if(com == "next")
        {
            tmpTime +=10;
        }
        else
        {
            tmpTime -=10;
        }
    
        if(tmpTime <= 0) 
        {
            tmpTime = 0;
        }
        else if(tmpTime >= total_Video_Len) 
        {
            tmpTime = total_Video_Len;
        }
       
        if(start <= tmpTime && tmpTime <= end)
        {
            tmpTime = end;
        }
    }
    
   
    
    string minute = Convert_Time_To_String(tmpTime,true);
    string sec = Convert_Time_To_String(tmpTime,false);
    answer = minute + ":" + sec; 
    
    return answer;
}