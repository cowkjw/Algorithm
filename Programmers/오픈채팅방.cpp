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

        stringstream s(record[i]); // ���� �ڸ���

        s >> command >> id >> name; // �߶� ����

        temp.push_back(make_pair(command, id)); // ��ɾ�� ���� ���̵� ����

        if (command != "Leave") // Leave �� �ڿ� ���� �̸��� ���⶧���� �ǳ� ��
            m[id] = name;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].first == "Enter")
            answer.push_back(m[temp[i].second] + "���� ���Խ��ϴ�.");
        else if (temp[i].first == "Leave")
            answer.push_back(m[temp[i].second] + "���� �������ϴ�.");
    }

    return answer;
}