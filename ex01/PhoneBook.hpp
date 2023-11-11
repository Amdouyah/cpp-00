#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact conta[8];
		// int i;
	public:
		void set_contact_info(int i, t_all *all);
		// Contact print_all_contacts(int i);
		t_all	print_all_contacts(int i);
};

#endif