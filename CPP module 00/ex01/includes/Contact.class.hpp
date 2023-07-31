#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

//# include "PhoneBook.class.hpp"
# include <string>

class Contact {

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact(void);
	Contact(std::string first, std::string last,
                 std::string nick, std::string phone,
                 std::string secret);

	// Getters
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickName(void);
	std::string getPhoneNumber(void);
	std::string getDarkestSecret(void);
};

#endif