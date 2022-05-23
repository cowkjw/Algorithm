#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string>> temp;

    for (int i = 0; i < record.size(); i++)
    {
        string command;
        string id;
        string name;

        stringstream s(record[i]); // 공백 자르기

        s >> command >> id >> name; // 잘라서 저장

        temp.push_back(make_pair(command, id)); // 명령어와 유저 아이디 저장

        if (command != "Leave") // Leave 는 뒤에 유저 이름이 없기때문에 건너 뜀
            m[id] = name;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].first == "Enter")
            answer.push_back(m[temp[i].second] + "님이 들어왔습니다.");
        else if (temp[i].first == "Leave")
            answer.push_back(m[temp[i].second] + "님이 나갔습니다.");
    }

    return answer;
}