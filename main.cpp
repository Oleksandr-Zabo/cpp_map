#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Function to add a new book
void addBook(map<string, vector<string>>& library) {
    string title;
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, title);

    vector<string> authors;
    string author;
    cin.ignore();
    cout << "Enter authors (separated by commas): ";
    getline(cin, author);
    cin.ignore();

    size_t pos = 0;
    while ((pos = author.find(',')) != string::npos) {
		authors.push_back(author.substr(0, pos));// .substr() returns a substring of the string
		author.erase(0, pos + 1);//.erase() removes characters from the string
    }
    authors.push_back(author);

    library[title] = authors;
}

// Function to find authors by book title
void findAuthors(const map<string, vector<string>>& library) {
    string title;
    cin.ignore();
    cout << "Enter book title to search for authors: ";
    getline(cin, title);
    cin.ignore();

    auto it = library.find(title);
    if (it != library.end()) {
        cout << "Authors of \"" << title << "\": ";
        for (const string& author : it->second) {
            cout << author << " ";
        }
        cout << endl;
    }
    else {
        cout << "Book not found." << endl;
    }
}

// Function to print all books and their authors
void printLibrary(const map<string, vector<string>>& library) {
    cout << "\nLibrary contents:\n";
    for (const auto& entry : library) {
        cout << entry.first << " - ";
        for (const string& author : entry.second) {
            cout << author << " ";
        }
        cout << endl;
    }
}

int main() {
    map<string, vector<string>> library = 
    {
        {"Adventures of Sherlock Holmes", {"Arthur Conan Doyle"}},

        {"Pride and Prejudice", {"Jane Austen"}},

        {"1984", {"George Orwell"}}
    };

    int choice;

    do {
		system("cls");
        cout << "Library Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Find authors by book title\n";
        cout << "3. Print all books and their authors\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(library);
            break;
        case 2:
            findAuthors(library);
            break;
        case 3:
            printLibrary(library);
            break;
        case 4:
            cout << "Exiting the program.\n";
			exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
		
		system("pause");
    } while (choice != 4);

    return 0;
}
