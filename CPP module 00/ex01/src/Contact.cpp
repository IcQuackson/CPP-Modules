
#include "../includes/Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string first, std::string last,
                 std::string nick, std::string phone,
                 std::string secret) : first_name(first),
									   last_name(last),
									   nick_name(nick),
									   phone_number(phone),
									   darkest_secret(secret) {
	
}

std::string Contact::getFirstName() {
    return this->first_name;
}

std::string Contact::getLastName() {
    return this->last_name;
}

std::string Contact::getNickName() {
    return this->nick_name;
}

std::string Contact::getPhoneNumber() {
    return this->phone_number;
}

std::string Contact::getDarkestSecret() {
    return this->darkest_secret;
}
