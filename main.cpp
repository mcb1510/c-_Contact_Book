#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string email;
	std::string phone_number;

public:
	void setFirstName(std::string name)
	{
		first_name = name;
	}
	std::string getFirstName() { return first_name; }

	void setLastName(std::string name)
	{
		last_name = name;
	}
	std::string getLastName() { return last_name; }

	void setEmail(std::string newEmail)
	{
		email = newEmail;
	}
	std::string getEmail() { return email; }

	void setPhone(std::string phone)
	{
		phone_number = phone;
	}
	std::string getPhone() { return phone_number; }
};

void addContact(std::vector<Contact> &contacts)
{
	Contact newContact;
	std::string first_name;
	std::string last_name;
	std::string email;
	std::string phone;

	std::cout << "Enter First Name: ";
	std::cin >> first_name;
	newContact.setFirstName(first_name);

	std::cout << "Enter Last Name: ";
	std::cin >> last_name;
	newContact.setLastName(last_name);

	std::cout << "Enter email: ";
	std::cin >> email;
	newContact.setEmail(email);

	std::cout << "Enter phone number: ";
	std::cin >> phone;
	newContact.setPhone(phone);

	contacts.push_back(newContact);
	std::cout << "Contact added." << std::endl;
}

void displayContacts(std::vector<Contact> &contacts)
{
	if (contacts.size() == 0)
	{
		std::cout << "No contacts to display" << std::endl;
	}
	else {

		for (auto& contact : contacts) {
			std::cout << std::endl;
			std::cout << "Name >> " << contact.getFirstName()
				<< " " << contact.getLastName() << std::endl;
			std::cout << "email >> " << contact.getEmail() << std::endl;
			std::cout << "Phone >> " << contact.getPhone() << std::endl;
		}
	}
	
}

void searchContact(std::vector<Contact>& contacts)
{
	std::string searchTerm;
	std::cout << "Enter name to search: ";
	std::cin >> searchTerm;

	bool found = false;
	for (auto& contact : contacts) {
		if (contact.getFirstName() == searchTerm)
		{
			std::cout << "Name >> " << contact.getFirstName()
				<< " " << contact.getLastName() << std::endl;
			std::cout << "email >> " << contact.getEmail() << std::endl;
			std::cout << "Phone >> " << contact.getPhone() << std::endl;
			found = true;
			break;
		}
		if (!found)
		{
			std::cout << "Contact not found." << std::endl;
		}
	}

}

void deleteContact(std::vector<Contact>& contacts)
{
	std::string nameToDelete;
	std::cout << "Enter name of contact to delete: ";
	std::cin >> nameToDelete;

	auto it = std::remove_if(contacts.begin(), contacts.end(), [&](Contact& contact)
		{return contact.getFirstName() == nameToDelete; });

	if (it != contacts.end())
	{
		contacts.erase(it, contacts.end());
		std::cout << "Contact deleted." << std::endl;
	}
	else
	{
		std::cout << "Contact not found" << std::endl;
	}
}

int main() 
{
	std::vector<Contact> contacts;
	int choice;
	do {
		std::cout << std::endl;
		std::cout << "1. Add Contact" << std::endl;
		std::cout << "2. Display Contacts" << std::endl;
		std::cout << "3. Search Contact" << std::endl;
		std::cout << "4. Delete Contact" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "Enter Choice >> ";
		std::cin >> choice;
		
		switch (choice)
		{
		case 1:
			addContact(contacts);
			break;
		case 2:
			displayContacts(contacts);
			break;
		case 3:
			searchContact(contacts);
			break;
		case 4:
			deleteContact(contacts);
			break;
		case 5:
			break;
		default:
			std::cout << "Invalid choice." << std::endl;
		}

	} while (choice != 5);
	return 0;
}
