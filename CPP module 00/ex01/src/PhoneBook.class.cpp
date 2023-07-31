
#include <iostream>
#include <iomanip>
#include <string>
#include "../includes/PhoneBook.class.hpp"
#include "../includes/Contact.class.hpp"

PhoneBook::PhoneBook() {
	for (int i = 0; i < 8; i++) {
		this->contact_list[i] = Contact();
	}
	this->current_index = 0;
	this->size = 0;
}

bool PhoneBook::addContact(std::string first, std::string last,
                 std::string nick, std::string phone,
                 std::string secret) {
	// Check for empty fields and invalid phone number
	if (first.empty() || last.empty() || nick.empty()
	|| phone.empty() || secret.empty() || phone.size() != 9) {
		return false;
	}
	// Check for invalid phone number
	for (size_t i = 0; i < phone.length(); i++) {
		if (!isdigit(phone[i])) {
			return false;
		}
	}
	// Check if contact list is full
	if (size >= 8) {
		this->current_index = 0;
	}
	// Add contact to list
	this->contact_list[this->current_index] = Contact(first, last, nick, phone, secret);
	this->current_index++;
	// Increment size if not full
	if (this->size < 8) {
		this->size++;
	}
	return true;
}

void PhoneBook::displayAllContacts(void) {
	// Header
    std::cout << std::right << std::setw(10) << "Index"
              << " | " << std::setw(10) << "First Name"
              << " | " << std::setw(10) << "Last Name"
              << " | " << std::setw(10) << "Nickname" << std::endl;
	// Display contact info truncated to 10 chars per column
    for (int i = 0; i < getSize(); ++i) {
        std::cout << std::right << std::setw(10) << i
                  << " | " << std::setw(10) << (contact_list[i].getFirstName().length() > 10 ? contact_list[i].getFirstName().substr(0, 9) + "." : contact_list[i].getFirstName())
                  << " | " << std::setw(10) << (contact_list[i].getLastName().length() > 10 ? contact_list[i].getLastName().substr(0, 9) + "." : contact_list[i].getLastName())
                  << " | " << std::setw(10) << (contact_list[i].getNickName().length() > 10 ? contact_list[i].getNickName().substr(0, 9) + "." : contact_list[i].getNickName())
                  << std::endl;
    }
}

void PhoneBook::displayContact(int index)
{
	if (index < 0 || index > 7 || index >= this->size) {
		return;
	}
	// Display contact info
	std::cout << "First name: " << this->contact_list[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contact_list[index].getLastName() << std::endl;
	std::cout << "Nick name: " << this->contact_list[index].getNickName() << std::endl;
	std::cout << "Phone number: " << this->contact_list[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contact_list[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getSize(void)
{
	return this->size;
}
