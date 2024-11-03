#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Function to add empty group
string addEmptyGroup(map<string, vector<string>>& groups) {
	string group;
	cin.ignore();
	cout << "Enter group name: ";
	getline(cin, group);
	groups[group] = {};
	return group;
	
}
string addEmptyGroup(map<string, vector<string>>& groups, string group) {
	groups[group] = {};
	return group;

}

// Function to add a new student to a group
void addStudent(map<string, vector<string>>& groups, string group) {

	if (groups.find(group) == groups.end()) {// group does not exist
		cout << "Group does not exist. Do you want to create it? (y/n): ";
		char choice;
		cin >> choice;

		if (choice == 'y') {
			group = addEmptyGroup(groups, group);
		}

		else {
			return;
		}
    }

	string student;
	cin.ignore();
	cout << "Enter students (separated by semicolon without space (A B;D E) ): ";
	getline(cin, student);
	cin.ignore();

	size_t pos = 0;
	while ((pos = student.find(";")) != string::npos) {
		groups[group].push_back(student.substr(0, pos));
		student.erase(0, pos + 1);
	}
	groups[group].push_back(student);
}

// Function to add a new group
void addGroup(map<string, vector<string>>& groups) {
	string group = addEmptyGroup(groups);
	cout << "Do you want to add students to this group? (y/n): ";
	char choice;
	cin >> choice;

	if (choice == 'y') {
		addStudent(groups, group);
	}
	else

	groups[group] = {};
}

// Function to delete a student from a group
void deleteStudent(map<string, vector<string>>& groups) {
	string group;
	cin.ignore();
	cout << "Enter group name: ";
	getline(cin, group);

	auto it = groups.find(group);
	if (it != groups.end()) {
		string student;
		cin.ignore();
		cout << "Enter student to delete: ";
		getline(cin, student);

		auto it2 = find(it->second.begin(), it->second.end(), student);
		if (it2 != it->second.end()) {
			it->second.erase(it2);
			cout << student << " has been deleted from " << group << endl;
		}
		else {
			cout << student << " is not in " << group << endl;
		}
	}
	else {
		cout << group << " not found\n";
	}
}


// Function to print all groups and their students
void printGroups(const map<string, vector<string>>& groups) {
	cout << "\nGroups contents:\n";
	for (const auto& entry : groups) {
		cout << entry.first << ": ";

		if (entry.second.empty()) {
			cout << "empty group";
		} 
		
		else {
			for (size_t i = 0; i < entry.second.size(); ++i) {
				cout << entry.second[i];
				if (i < entry.second.size() - 1) {
					cout << ", ";
				}
				else {
					cout << ".";
				}
			}
		}
		cout << endl;
	}
}

int main() {
    map<string, vector<string>> groups;

    int choice;

    do {
        system("cls");
        cout << "Groups Management System\n";
        cout << "1. Add a new group\n";
        cout << "2. Add students to a group\n";
		cout << "3. Delete student from a group\n";
        cout << "4. Print all groups and their students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

		switch (choice) {
			case 1: {
				addGroup(groups);
				break;
			}
				
			case 2: {
				string group;
				cout << "Enter group name: ";
				cin >> group;
				addStudent(groups, group);
				break;
			}

			case 3:
			{
				deleteStudent(groups);
				break;
			}

			case 4:
			{
				printGroups(groups);
				break;
			}

			case 5:
			{
				cout << "Exiting the program.\n";
				exit(0);
				break;
			}

			default:
			{
				cout << "Invalid choice. Please try again.\n";
			}
		}

        system("pause");
    } while (choice != 5);

    return 0;
}
