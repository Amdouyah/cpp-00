#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 1;
		while(i < ac)
		{
			std::string input(av[i]);
			int a = 0;
			while(input[a])
			{
				input[a] = std::toupper(input[a]);
				i++;
				a++;
			}
			std::cout << input;
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
