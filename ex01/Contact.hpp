#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

typedef	struct s_all{
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string nick_name;
	std::string darkest_secret;
}t_all;

class Contact{
	private:
		std::string first_name;
		std::string last_name;
		std::string phone_number;
		std::string nick_name;
		std::string darkest_secret;
	public:
		void set_all(t_all *info);
		t_all get_all();
};

#endif
