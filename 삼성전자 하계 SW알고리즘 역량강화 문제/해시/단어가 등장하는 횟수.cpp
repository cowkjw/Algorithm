#include<iostream>
#include<vector>
using namespace std;
int ans = 0;
vector<int> makeTable(string str)
{
    int size = str.size();
    vector<int> table(size);
    int j = 0;
    for (int i = 1; i < str.size(); i++)
    {
        while (j > 0 && str[i] != str[j]) // j가 첫번째 인덱스가 아니고 i와도 같지 않다면 j를 전의 인덱스로 돌림
        {
            j = table[j - 1];
        }
        if (str[i] == str[j])// 같다면 이전까지 접두사와 접미사가 일치하는 개수 저장
        {
            table[i] = ++j; 
        }
    }
    return table;
}

void KMP(string str, string find)
{
    vector<int> table = makeTable(find);
    int size = str.size();
    int findSize = find.size();
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        while (j > 0 && str[i] != find[j])
        {
            j = table[j - 1];
        }
        if (str[i] == find[j])
        {
            if (j == findSize - 1)
            {
                ans++;
                j = table[j];
            }
            else
            {
                j++;
            }
        }
    }

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
        string s, p;
        cin >> s;
        cin >> p;
        ans = 0;
        KMP(s, p);

	
		cout << "#" << test_case << " "<<ans<< '\n';
	}
	return 0;
}