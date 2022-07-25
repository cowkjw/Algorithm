#include <list>
#include<iostream>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;

	
	for(test_case = 1; test_case <= 10; ++test_case)
	{


		int n, cmdCnt;
		char cmd;
		list<int> li;

		cin >> n; //원본 암호문 길이

		for (int i = 0; i < n; i++) // 원본 암호문
		{
			int code;
			cin >> code;
			li.push_back(code);
		}
		cin >> cmdCnt;

		for (int i = 0; i < cmdCnt; i++)
		{
			int x, y, s;
			cin >> cmd;
			if (cmd == 'I')
			{
				cin >> x >> y;
				auto iter = li.begin();
				for (int i = 0; i < x; i++)
					iter++;
				for (int j = 0; j < y; j++)
				{
					cin >> s;
					li.insert(iter, s);
				}


			}
			else if (cmd == 'D')
			{
				cin >> x >> y;
				auto iter = li.begin();
				for (int i = 0; i < x; i++)
					iter++;

				for (int j = 0; j < y; j++)
					iter = li.erase(iter);
			}
			else if (cmd == 'A')
			{
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					cin >> s;
					li.push_back(s);
				}
			}

		}
    
		cout << "#" << test_case << " ";
		auto it = li.begin();
		for (int i = 0; i < 10; i++, it++)
		{
			cout << *it << " ";
		}
		cout << '\n';
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}