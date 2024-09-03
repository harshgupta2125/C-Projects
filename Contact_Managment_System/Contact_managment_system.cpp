#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Define a struct for Contact
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string email;
};

// Function to add a contact
void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, newContact.phoneNumber);
    std::cout << "Enter email: ";
    std::getline(std::cin, newContact.email);
    contacts.push_back(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}

// Function to delete a contact
void deleteContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter name of contact to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Contact not found!" << std::endl;
}

// Function to search a contact by name
void searchContact(const std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter name of contact to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            return;
        }
    }
    std::cout << "Contact not found!" << std::endl;
}

// Function to display all contacts
void displayContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts available!" << std::endl;
        return;
    }
    std::cout << "Contacts:" << std::endl;
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Contact> contacts;
    int choice;
    while (true) {
        std::cout << "Contact Management System" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Delete Contact" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Display Contacts" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                deleteContact(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                displayContacts(contacts);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}