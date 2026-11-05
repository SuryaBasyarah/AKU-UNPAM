
 // Surya Basyrah Putra
 // 251011402227
 // Struktur Data 03TPLE011

#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    string name;
    string nim;
    string gender;
    float grade;
    Student* prev;
    Student* next;
};

Student* head = nullptr;
Student* tail = nullptr;

void showMenu();
void insertData();
void deleteData();
void printData();
void printList();
void clearData();

int main() {
    int choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            if (cin.eof()) {
                clearData();
                return 0;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pilihan tidak valid!" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                insertData();
                break;

            case 2:
                deleteData();
                break;

            case 3:
                printData();
                break;

            case 4:
                clearData();
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (choice != 4);

    return 0;
}

void printList() {
    Student* current = head;

    cout << endl;
    cout << "NULL";

    while (current != nullptr) {
        cout << " <-> [" << current->nim << "]";
        current = current->next;
    }

    cout << " <-> NULL" << endl;
}


void insertData() {
    Student* newNode = new Student;

    cout << endl;
    cout << "Nama   : ";
    getline(cin >> ws, newNode->name);

    cout << "NIM    : ";
    cin >> newNode->nim;

    // (err) jika bukan angka
    if (newNode->nim.find_first_not_of("0123456789") != string::npos) {
        cout << "NIM harus berupa angka!" << endl;
        delete newNode;
        return;
    }

    // (err) jika NIM sudah terdaftar
    Student* current = head;

    while (current != nullptr) {
        if (current->nim == newNode->nim) {
            cout << "NIM sudah terdaftar!" << endl;
            delete newNode;
            return;
        }

        current = current->next;
    }

    cout << "Gender : ";
    getline(cin >> ws, newNode->gender);

    cout << "Nilai  : ";
    cin >> newNode->grade;

    newNode->prev = nullptr;
    newNode->next = nullptr;

    // cari posisi berdasarkan urutan NIM
    current = head;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else if (current == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (current == nullptr) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else {
        newNode->next = current;
        newNode->prev = current->prev;

        current->prev->next = newNode;
        current->prev = newNode;
    }

    cout << "Data berhasil ditambahkan!" << endl;
    printList();
}


void deleteData() {
    if (head == nullptr) {
        cout << "Data masih kosong!" << endl;
        return;
    }

    string nim;

    cout << endl;
    cout << "Masukkan NIM yang dihapus: ";
    cin >> nim;

    Student* current = head;

    while (current != nullptr && current->nim != nim) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }

    delete current;

    cout << "Data berhasil dihapus!" << endl;
    printList();
}

void printData() {
    if (head == nullptr) {
        cout << "Data masih kosong!" << endl;
        return;
    }

    Student* current = head;
    int number = 1;

    cout << endl;
    cout << "DAFTAR MAHASISWA" << endl;
    cout << "==============================" << endl;

    while (current != nullptr) {
        cout << "Data ke-" << number << endl;
        cout << "Nama   : " << current->name << endl;
        cout << "NIM    : " << current->nim << endl;
        cout << "Gender : " << current->gender << endl;
        cout << "Nilai  : " << current->grade << endl;
        cout << "==============================" << endl;

        current = current->next;
        number++;
    }

    printList();
}

void clearData() {
    Student* current = head;

    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}

void showMenu() {
    cout << endl;
    cout << "     DOUBLY LINKED LIST" << endl;
    cout << "==============================" << endl;
    cout << "1. INSERT DATA" << endl;
    cout << "2. HAPUS DATA" << endl;
    cout << "3. CETAK DATA" << endl;
    cout << "4. EXIT" << endl;
    cout << "Pilihan : ";
}
