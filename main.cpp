// main.cpp
#include <iostream>
#include <string>
#include "login.h"
#include "login.h"
#include "antrian.h"


using namespace std;

void userMenu(string userName) {
    system("CLS");
    cout << "=== MENU USER ===" << endl;
    cout << "1. Tampilan antrian" << endl;
    cout << "2. Ambil antrian" << endl;
    cout << "3. Menerima sembako" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            lihatAntrian();
            system("pause");
            break;
        case 2:
            tambahAntrian (userName);
            system("pause");
            break;
        case 3:
            cout << "Menerima sembako" << endl;
            break;
        case 0:
            cout << "Keluar dari program" << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
}

void adminMenu() {
    system("CLS"); 
    cout << "=== MENU ADMIN ===" << endl;
    cout << "1. Lihat antrian" << endl;
    cout << "2. Hapus antrian" << endl;
    cout << "3. Cari data warga" << endl;
    cout << "4. Riwayat distribusi" << endl;
    cout << "5. Lihat dan edit stock" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            lihatAntrian();
            system("pause");
            break;
        case 2:
            hapusAntrian();
            system("pause");
            break;
        case 3:
            cout << "Cari data warga" << endl;
            break;
        case 4:
            cout << "Riwayat distribusi" << endl;
            break;
        case 5:
            cout << "Edit stock" << endl;
            break;
        case 0:
            cout << "Keluar dari program" << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
}

int main() {
    string user;
    while (true) {
        user = menuLogin();
        if (user == "admin") {
            adminMenu();
        } else if (user != "null") {
            userMenu(user);
        }
    }
    return 0;
}

