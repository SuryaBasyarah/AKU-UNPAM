#include <iostream>
#include <string>
using namespace std;

struct Student {
    string nim;
    string name;
    float score;
    Student* next;
};

Student* head = nullptr;

void insertStudent() {
    Student* newStudent = new Student;

    cout << endl;
    cout << "=== INSERT STUDENT DATA ===" << endl;

    cout << "NIM   : ";
    cin >> newStudent->nim;

    cout << "Name  : ";
    getline(cin >> ws, newStudent->name);

    cout << "Score : ";
    cin >> newStudent->score;

    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    }

    else if (newStudent->score < head->score) {
        newStudent->next = head;
        head = newStudent;
    }

    else {
        Student* current = head;

        while (current->next != nullptr &&
               current->next->score <= newStudent->score) {
            current = current->next;
        }

        newStudent->next = current->next;
        current->next = newStudent;
    }

    cout << endl;
    cout << "Student data inserted successfully." << endl;
}

void displayScore90() {
    if (head == nullptr) {
        cout << endl;
        cout << "Student data is empty." << endl;
        return;
    }

    Student* current = head;
    bool found = false;

    cout << endl;
    cout << "=== STUDENTS WITH SCORE 90 ===" << endl;

    while (current != nullptr) {
        if (current->score == 90) {
            cout << "NIM   : " << current->nim << endl;
            cout << "Name  : " << current->name << endl;
            cout << "Score : " << current->score << endl;
            cout << "-----------------------------" << endl;

            found = true;
        }

        current = current->next;
    }

    if (!found) {
        cout << "No student with score 90 found." << endl;
    }
}

void displayAllStudents() {
    if (head == nullptr) {
        cout << endl;
        cout << "Student data is empty." << endl;
        return;
    }

    Student* current = head;
    int number = 1;

    cout << endl;
    cout << "=== ALL STUDENT DATA ===" << endl;

    while (current != nullptr) {
        cout << endl;
        cout << "Student " << number << endl;
        cout << "NIM   : " << current->nim << endl;
        cout << "Name  : " << current->name << endl;
        cout << "Score : " << current->score << endl;

        current = current->next;
        number++;
    }
}

void deleteStudent() {
    string targetNim = "2007140022";

    if (head == nullptr) {
        cout << endl;
        cout << "Student data is empty." << endl;
        return;
    }

    Student* current = head;
    Student* previous = nullptr;

    while (current != nullptr && current->nim != targetNim) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << endl;
        cout << "Student with NIM " << targetNim << " not found." << endl;
        return;
    }

    if (previous == nullptr) {
        head = head->next;
    }

    else {
        previous->next = current->next;
    }

    cout << endl;
    cout << "Deleted student:" << endl;
    cout << "NIM   : " << current->nim << endl;
    cout << "Name  : " << current->name << endl;
    cout << "Score : " << current->score << endl;

    delete current;

    cout << endl;
    cout << "Student data deleted successfully." << endl;
}


void calculateAverage() {
    if (head == nullptr) {
        cout << endl;
        cout << "Student data is empty." << endl;
        return;
    }

    Student* current = head;

    float totalScore = 0;
    int studentCount = 0;

    while (current != nullptr) {
        totalScore += current->score;
        studentCount++;

        current = current->next;
    }

    float average = totalScore / studentCount;

    cout << endl;
    cout << "=== CLASS AVERAGE ===" << endl;
    cout << "Total students : " << studentCount << endl;
    cout << "Total score    : " << totalScore << endl;
    cout << "Average score  : " << average << endl;
}


void clearList() {
    Student* current = head;

    while (current != nullptr) {
        Student* nodeToDelete = current;
        current = current->next;

        delete nodeToDelete;
    }

    head = nullptr;
}


int main() {
    int choice;

    do {
        cout << endl;
        cout << "==============================" << endl;
        cout << "      STUDENT LINKED LIST" << endl;
        cout << "==============================" << endl;
        cout << "1. Insert Student Data" << endl;
        cout << "2. Display Score 90" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Delete NIM 2007140022" << endl;
        cout << "5. Calculate Class Average" << endl;
        cout << "6. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertStudent();
                break;

            case 2:
                displayScore90();
                break;

            case 3:
                displayAllStudents();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                calculateAverage();
                break;

            case 6:
                cout << endl;
                cout << "Program finished." << endl;
                break;

            default:
                cout << endl;
                cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    clearList();

    return 0;
}