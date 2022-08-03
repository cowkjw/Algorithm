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
        while (j > 0 && str[i] != str[j]) // j�� ù��° �ε����� �ƴϰ� i�͵� ���� �ʴٸ� j�� ���� �ε����� ����
        {
            j = table[j - 1];
        }
        if (str[i] == str[j])// ���ٸ� �������� ���λ�� ���̻簡 ��ġ�ϴ� ���� ����
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