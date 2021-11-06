#include <iostream>


int main(void)
{
	int a, b, c;


	while (std::cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)

		{
			break;
		}

		if ((c*c) == (a*a) + (b*b))
		{
			std::cout << "right" << std::endl;
		}

		else if ((b*b) == (a*a) + (c*c))
		{
			std::cout << "right" << std::endl;
		}

		else if ((a*a) == (c*c) + (b*b))
		{
			std::cout << "right" << std::endl;
		}
		else
		{
			std::cout << "wrong" << std::endl;
		}

	}

}
