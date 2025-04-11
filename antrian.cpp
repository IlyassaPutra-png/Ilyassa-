// antrian.h
#ifndef ANTRIAN_H
#define ANTRIAN_H

#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void tambahAntrian(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    cout << nama << " berhasil masuk antrian!" << endl;
}

void lihatAntrian() {
    if (head == NULL) {
        cout << "Antrian kosong." << endl;
        return;
    }

    Node* current = head;
    int i = 1;
    cout << "\n--- Daftar Antrian ---" << endl;
    while (current != NULL) {
        cout << i++ << ". " << current->nama << endl;
        current = current->next;
    }
}

void hapusAntrian() {
    if (head == NULL) {
        cout << "Tidak ada antrian yang bisa dihapus." << endl;
        return;
    }

    string target;
    cout << "Masukkan nama yang ingin dihapus dari antrian: ";
    cin.ignore();
    getline(cin, target);

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->nama == target) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            delete current;
            cout << "Antrian atas nama " << target << " berhasil dihapus." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Data tidak ditemukan dalam antrian." << endl;
}

#endif