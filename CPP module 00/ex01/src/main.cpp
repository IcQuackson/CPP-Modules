#include <iostream>
#include <string>
#include "../includes/Contact.class.hpp"
#include "../includes/PhoneBook.class.hpp"

void addContact(PhoneBook& phone_book) {
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nick name: ";
	std::getline(std::cin, nick_name);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);

	if (!phone_book.addContact(first_name, last_name, nick_name, phone_number, darkest_secret)) {
		std::cout << "Fields can't be empty and phone number must have 9 digits" << std::endl;
	}
}

void searchContact(PhoneBook& phone_book) {
	phone_book.displayAllContacts();

	std::string index;
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	if (index.length() != 1 || index[0] < '0' || index[0] > '7') {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	int i = index[0] - '0';
	if (i >= phone_book.getSize()) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	phone_book.displayContact(i);
}


int main() {
	PhoneBook phone_book;

	while (1) {
		std::string input;
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			break;
		}
		else if (input == "ADD") {
			addContact(phone_book);
		}
		else if (input == "SEARCH") {
			searchContact(phone_book);
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
}
