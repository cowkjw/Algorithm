#include <iostream>


int main(void)
{
	int A, B, C;
	
	std::cin>> A >> B >> C;

	if (B >= C)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		// A/(C-B)+1=X
		std::cout << A/(C-B)+1 << std::endl;
	}
}
