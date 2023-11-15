#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string getdata(std::string str)
{
	std::string line;
	while(1)
	{
		std::cout << str;
		if (!(getline(std::cin, line)))
			exit(0);
		if (!line.empty())
			break;
	}
	return(line);
}

void	get_info(PhoneBook *cla, int i)
{
	t_all info;

	info.first_name = getdata("First Name : ");
	info.last_name = getdata("Last Name : ");
	info.phone_number = getdata("Phone Number : ");
	info.darkest_secret = getdata("Darkest Secret : ");
	info.nick_name = getdata("Nick Name : ");
	cla->set_contact_info(i, &info);
}

void    print_10in_SEARCH(std::string str)
{
    int    i;
    int len = str.length();

    i = 0;
    std::cout <<"|";
    if (str.length() < 10)
    {
        while (i < 10 - len)
        {
            std::cout<< " ";
            i++;
        }
    }
    i = 0;
    while (str[i] && i < 9)
        std::cout << str[i++];
    if (str.length() > 10)
        std::cout<< ".";
    else
        std::cout << str[i++];
}
int	check_index(int a)
{
	if (a >= 0 && a < 8)
		return 1;
	return 0;
	
}

void	SEARCH(PhoneBook *cla)
{
	int i = 0;
	t_all all;
	bool contactExists = false;

	while (i < 8)
    {
        all = cla->print_all_contacts(i);
        if (!all.first_name.empty())
        {
			if (i == 0)
			{
				std::cout << "********************************************"<< std::endl;
				std::cout << "|  index   | firstname| lastname | nickname |" << std::endl;
				std::cout << "********************************************"<< std::endl;
			}
            contactExists = true;
            std::cout << "|" << std::setw(10) << i;
			print_10in_SEARCH(all.first_name);
			print_10in_SEARCH(all.last_name);
			print_10in_SEARCH(all.nick_name);
            std::cout << "|" << std::endl;
			std::cout << "********************************************"<< std::endl;
        }
        i++;
    }
	if (!contactExists)
    {
        std::cout << "No contacts found." << std::endl;
		return;
    }
    std::cout << "Enter an index: ";
	std::string s;
	int inputIndex = 0;
	if(!(getline(std::cin, s)))
		exit(0);
	if (s.length() != 1)
	{
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
		return ;
	}
	else
  		inputIndex = s[0] - 48;

	if (check_index(inputIndex) == 1)
    {
        t_all selectedContact = cla->print_all_contacts(inputIndex);
        std::cout << "Contact information:" << std::endl;
        std::cout << "First Name: " << selectedContact.first_name << std::endl;
        std::cout << "Last Name: "<< selectedContact.last_name << std::endl;
        std::cout << "Nickname: " << selectedContact.nick_name << std::endl;
		std::cout << "Phone Number: " << selectedContact.phone_number << std::endl;
		std::cout << "Dark Secret: " << selectedContact.darkest_secret << std::endl;

    }
    else
    {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
}

int main()
{
	std:: string line;
	PhoneBook	cla;
	int i = 0;
	while (1)
	{
		std::cout << "Entre command : ";
		if (!(std::getline(std::cin, line)))
			return 0;
		if (line == "ADD")
		{
			get_info(&cla, i);
			i++;
			if (i == 8)
				i = 0; 
		}
		else if (line == "SEARCH")
			SEARCH(&cla);
		else if (line == "EXIT")
			break;
		
	}
}
