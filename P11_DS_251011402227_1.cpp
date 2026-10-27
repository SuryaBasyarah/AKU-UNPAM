#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string studentId;
    string gender;
    float score;
};

struct Node {
    Student data;
    Node* next;
};

class StudentStack {
private:
    Node* head;

public:
    StudentStack() {
        head = new Node;
        head->next = nullptr;
    }

    void push() {
        Node* newNode = new Node;

        cout << endl;
        cout << "=== INSERT DATA MAHASISWA ===" << endl;

        cout << "Nama   : ";
        getline(cin >> ws, newNode->data.name);

        cout << "NIM    : ";
        getline(cin, newNode->data.studentId);

        cout << "Gender : ";
        getline(cin, newNode->data.gender);

        cout << "Nilai Struktur Data : ";
        cin >> newNode->data.score;

        newNode->next = head->next;
        head->next = newNode;

        cout << endl;
        cout << "Data berhasil dimasukkan ke Stack." << endl;
    }

    void pop() {
        if (head->next == nullptr) {
            cout << endl;
            cout << "Stack kosong. Tidak ada data yang dapat dihapus." << endl;
            return;
        }

        Node* removedNode = head->next;

        cout << endl;
        cout << "=== DATA YANG DIHAPUS ===" << endl;
        cout << "Nama   : " << removedNode->data.name << endl;
        cout << "NIM    : " << removedNode->data.studentId << endl;
        cout << "Gender : " << removedNode->data.gender << endl;
        cout << "Nilai  : " << removedNode->data.score << endl;

        head->next = removedNode->next;
        delete removedNode;

        cout << endl;
        cout << "Data berhasil dihapus dari Stack." << endl;
    }

    void printData() {
        if (head->next == nullptr) {
            cout << endl;
            cout << "Stack kosong." << endl;
            return;
        }

        Node* current = head->next;
        int number = 1;

        cout << endl;
        cout << "============================================" << endl;
        cout << "            DATA STACK MAHASISWA" << endl;
        cout << "============================================" << endl;

        while (current != nullptr) {
            cout << endl;
            cout << "Data ke-" << number << endl;
            cout << "Nama   : " << current->data.name << endl;
            cout << "NIM    : " << current->data.studentId << endl;
            cout << "Gender : " << current->data.gender << endl;
            cout << "Nilai Struktur Data : "
                 << current->data.score << endl;

            current = current->next;
            number++;
        }

        cout << endl;
    }

    // destructor
    ~StudentStack() {
        Node* current = head;

        while (current != nullptr) {
            Node* nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
    }
};

int main() {
    StudentStack stack;
    int choice;

    do {
        cout << endl;
        cout << "=================================" << endl;
        cout << "        STACK MAHASISWA" << endl;
        cout << "=================================" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "=================================" << endl;
        cout << "Pilihan : ";
        cin >> choice;

        switch (choice) {
            case 1:
                stack.push();
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.printData();
                break;

            case 4:
                cout << endl << "Program selesai." << endl;
                break;

            default:
                cout << endl << "Pilihan tidak tersedia." << endl;
        }

    } while (choice != 4);

    return 0;
}
