#include <iostream>

using namespace std;

int main()
{

	int T, a, n;  // T > ÄÉÀÌ½º ¼ö  kÃþ nÈ£ kÃþ¿¡ nÈ£¿¡´Â (k-1)ÃþºÎÅÍ 
	int sum;
	int* People = new int[15]{ 0 };
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		sum = 0;
		cin >> a; // Ãþ¼ö
		cin >> n;

	


		for (int k = 0; k <= a; k++)
		{
			for (int m = 1; m <= n; m++)
			{
				if (k == 0)
				{
					People[m] = m;
				}
				else
				{
					People[m] = People[m - 1] + People[m];
				}
			}
		}
		cout << People[n] << "\n";
		
	}
	
	delete[] People;


	return 0;

}