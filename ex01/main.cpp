#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

std::string getdata(std::string str)
{
	std::string line;
	while(1)
	{
		std::cout << str;
		getline(std::cin, line);
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
            std::cout << "|" << std::setw(10) << all.first_name;
            std::cout << "|" << std::setw(10) << all.last_name;
            std::cout << "|" << std::setw(10) << all.nick_name;
            std::cout << "|" << std::endl;
			std::cout << "********************************************"<< std::endl;
			std::cout << "Enter an indix : ";
        }
        i++;
    }
	if (!contactExists)
    {
        std::cout << "No contacts found." << std::endl;
    }
	int inputIndex;
    std::cout << "Enter an index: ";
    std::cin >> inputIndex;
	if (inputIndex >= 0 && inputIndex < 8)
    {
        // Display the contact information
        t_all selectedContact = cla->print_all_contacts(inputIndex);
        std::cout << "Contact information:" << std::endl;
        std::cout << "First Name: " << selectedContact.first_name << std::endl;
        std::cout << "Last Name: " << selectedContact.last_name << std::endl;
        std::cout << "Nickname: " << selectedContact.nick_name << std::endl;
    }
    else
    {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
	// std::cout << "Enter index : " << std::endl;
	// std::cout << cla[i].set_contact_info(i, )
	// std::setw()
}

int main()
{
	std:: string line;
	PhoneBook	cla;
	int i = 0;
	while (1)
	{
		std::cout << "Entre command : ";
		std::getline(std::cin, line);
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
