#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
	}

	vector<pair<int,int>> image;
	for (int i = 0; i < k; i++)
	{
		if (image.size() < n)
		{
			auto it = find_if(image.begin(), image.end(), [&](pair<int, int> a)
				{
					return (a.first == v[i]);
				});
			if (it != image.end())
			{
				(*it).second += 1;
			}
			else image.push_back({ v[i],1});
		}
		else
		{
			auto it = find_if(image.begin(), image.end(), [&](pair<int, int> a)
				{
					return (a.first == v[i]);
				});
			if (it != image.end())
			{
				(*it).second += 1;
			}
			else
			{
				int idx = 0;
				int min = INF;
				for (int i = 0; i < image.size(); i++)
				{
					if (image[i].second < min)
					{
						idx = i;
						min = image[i].second;
					}
				}
				image.erase(image.begin() + idx);
				image.push_back({ v[i],1 });
			}
		}
	}

	sort(image.begin(), image.end());
	for (const auto& i : image) cout << i.first << " ";

	return 0;
}
