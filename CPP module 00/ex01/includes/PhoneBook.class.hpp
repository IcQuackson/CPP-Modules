#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
//# include "phonebook.hpp"
//class Contact;


class PhoneBook {

private:
	Contact contact_list[8];
	int current_index;
	int	size;
public:
	PhoneBook(void);

	bool addContact(std::string first, std::string last,
                 std::string nick, std::string phone,
                 std::string secret);
	void displayAllContacts(void);
	void displayContact(int index);
	int	 getSize(void);
};

#endif