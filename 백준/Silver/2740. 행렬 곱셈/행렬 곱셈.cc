#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;

	cin >> a >> b;
    vector<vector<int>> matrixN(a, vector<int>(b));

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> matrixN[i][j];
        }
    }

    int c, d;
    cin >> c >> d;
    vector<vector<int>> matrixM(c, vector<int>(d));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> matrixM[i][j];
        }
    }

    vector<vector<int>> result(a, vector<int>(d, 0));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int k = 0; k < b; k++)
            {
                result[i][j] += matrixN[i][k] * matrixM[k][j]; 
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }



	return 0;
}