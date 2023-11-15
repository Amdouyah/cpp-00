#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact conta[8];
	public:
		void set_contact_info(int i, t_all *all);
		t_all	print_all_contacts(int i);
};

#endif