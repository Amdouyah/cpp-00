#include "Contact.hpp"

void Contact::set_all(t_all *info)
{
	this->first_name = info->first_name;
	this->last_name = info->last_name;
	this->phone_number = info->phone_number;
	this->darkest_secret = info->darkest_secret;
	this->nick_name = info->nick_name;
}

t_all Contact::get_all()
{
	t_all info;

	info.first_name = first_name;
	info.last_name = last_name;
	info.darkest_secret = darkest_secret;
	info.nick_name = nick_name;
	info.phone_number = phone_number;
	return info;
}
