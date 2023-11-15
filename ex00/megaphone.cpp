#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if(ac != 1)
	{
		int i = 1;
		while(i < ac)
		{
			std::string str = av[i];
			int a = 0;
			while (str[a])
			{
				str[a] = std::toupper(str[a]);
				a++;
			}
			std::cout << str;
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
