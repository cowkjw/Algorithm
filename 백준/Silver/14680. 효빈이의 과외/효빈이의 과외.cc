#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
struct Matrix
{
	int row, col;
	Matrix(int row, int col) : row(row), col(col), adj(vector<vector<ll>>(row+1, vector<ll>(col+1))) {}
	Matrix(const Matrix& other)
		: row(other.row), col(other.col), adj(other.adj) {
	}
	vector<vector<ll>> adj ;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<Matrix> matrices;

	for (int i = 0; i < n; i++)
	{
		int row, col;
		cin >> row >> col;

		matrices.push_back(Matrix(row, col));
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				cin>>matrices.back().adj[i][j];
			}
		}
	}
	Matrix matrix(matrices.front());

	int curCol = matrices.front().col;

	for (int idx = 1; idx< n; idx++)
	{
		Matrix B = matrices[idx];

		if (curCol != B.row)
		{
			cout << -1;
			return 0;
		}

		Matrix C(matrix.row, B.col); // 새 결과 행렬

		for (int i = 1; i <= matrix.row; i++)
		{
			for (int j = 1; j <= B.col; j++)
			{
				ll sum = 0;

				for (int k = 1; k <= curCol; k++) // curCol = A.col = B.row
				{
					sum = (sum + (1LL * matrix.adj[i][k] * B.adj[k][j]) % 1000000007) % 1000000007;
				}

				C.adj[i][j] = sum % 1000000007;
			}
		}
		curCol = B.col;
		matrix = C;    

	}
	ll ans = 0;
	for (int i = 1; i <= matrix.row; i++)
	{
		for (int j = 1; j <= matrix.col; j++)
		{
			ans = (ans + matrix.adj[i][j]) % 1000000007;
		}
	}
	cout << ans % 1000000007;
	return 0;
}
