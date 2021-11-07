#include <iostream>


int main(void)
{
	int N;
	int Num;
	int count = 0;
	int Prime;

	std::cin >> N; // 5 

	

	for (int i = 0; i < N; i++)
	{
		std::cin >> Num;  // 1 2 3 4 5

		if (Num == 1) continue;

		else
		{
			if (Num == 2)
			{
				count++;
			}

			else
			{
				for (int j = 2; j <=Num/2; j++)
				{
					if (Num%j == 0)
					{
						Prime = 0;
						break;
					}
					else
					{
						Prime = 1;
					}
				}
				if (Prime == 1)
				{
					count++;
				}
			}
		}
		
	}
	std::cout << count << std::endl;
}
