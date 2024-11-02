#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//collections
#include <map>
#include <vector>

using namespace std;


// Function to calculate the average grade
double calculateAverage(const vector<int>& grades) {
	if (grades.empty()) return 0.0;// .empty() returns true if the vector is empty
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
	double average = (grades.size() != 0) ? sum / (grades.size() * 1.0) : 0;// .size() returns the number of elements in the vector
    return average;
}

// Function to check if a student exists
bool isStudentExist(const map<string, vector<int>>& studentGrades, string name) {
    if (studentGrades.find(name) == studentGrades.end()) {
        return 1;
    }
    else return 0;
}

//function to add grades to a student by name
void addGradesByName(map<string, vector<int>>& studentGrades, string name) {


    if (isStudentExist(studentGrades, name)) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter grades (separated by space, 1-12): ";
    vector<int> grades;
    string line;
    int grade;
    cin.ignore(); // clear the input buffer
    getline(cin, line);
    istringstream iss(line);
    while (iss >> grade) {
        if (grade > 0 && grade <= 12) {
			grades.push_back(grade);
		}
		else {
			cout << "Invalid grade: " << grade << ". Grade must be between 1 and 12.\n";
        }
    }

    studentGrades[name] = grades;
}

// Function to add grades to a student
void addGrades(map<string, vector<int>>& studentGrades) {
    string name;
    cout << "Enter student's name: ";
    cin >> name;

	addGradesByName(studentGrades, name);
}

// Function to add a student
void addStudent(map<string, vector<int>>& studentGrades) {
    string name;
    cout << "Enter student's name: ";
    cin >> name;
	bool isStudent =  isStudentExist(studentGrades,name);
    if (isStudent) {
        studentGrades[name] = vector<int>();
		cout << "Student added.\n";
	}
	else cout << "Student already exists.\n";

    // add grades after adding a student
    addGradesByName(studentGrades, name);

}

// Function to print all students and their average grades
void printAllStudents(const map<string, vector<int>>& studentGrades) {
    cout << "\nResults:\n";
    for (const auto& student : studentGrades) {
        double average = calculateAverage(student.second);
        cout << student.first << ": average grade = " << average << endl;
    }
}

// Function to print a single student and their average grade
void printStudent(const map<string, vector<int>>& studentGrades) {
    string name;
    cout << "Enter student's name: ";
    cin >> name;

    if (isStudentExist(studentGrades, name)) {
        cout << "Student not found.\n";
        return;
    }

    double average = calculateAverage(studentGrades.at(name));
    cout << name << ": average grade = " << average << endl;
}

int main() {
    map<string, vector<int>> studentGrades;
    int choice;

    do {
		system("cls");
        cout << "Menu:\n";
        cout << "1. Add student\n";
        cout << "2. Add grades\n";
        cout << "3. Print all students and averages\n";
        cout << "4. Print one student and average\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(studentGrades);
                break;
            case 2:
                addGrades(studentGrades);
                break;
            case 3:
                printAllStudents(studentGrades);
                break;
            case 4:
                printStudent(studentGrades);
                break;
            case 5:
                cout << "Exiting...\n";
				exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
		system("pause");
    } while (choice != 5);

    return 0;
}
