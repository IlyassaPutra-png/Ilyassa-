// login.cpp
#include <iostream>
#include "login.h"
using namespace std;

akun user;

void registerAkun() {
    cout << "Masukkan NIK: ";
    cin >> user.NIK;
    cout << "Masukkan Nama: ";
    cin >> user.nama;
    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> user.jenisKelamin;
    cout << "Masukkan Umur: ";
    cin >> user.umur;
    cout << "Masukkan Password: ";
    cin >> user.password;

    cout << "\nData berhasil disimpan!" << endl;
}

string login() {
    system("CLS");
    string NIK;
    string password;
    cout << "=== LOGIN ===" << endl;
    cout << "Masukkan NIK untuk login: ";
    cin >> NIK;
    cout << "Masukkan Password: ";
    cin >> password;

    if(NIK == "admin" && password == "admin") {
        return "admin";
    }

    if (user.NIK == NIK && user.password == password) {
        cout << "\nLogin berhasil!" << endl;
        return user.nama;
    } else {
        cout << "\nLogin gagal! NIK atau password salah." << endl;
        return "null";
    }
}

string menuLogin() {
    while(true) {
        system("CLS");
        cout << "=== MENU LOGIN ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        string user;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                user = login();
                if(user != "null") {
                    return user;
                } else {
                    continue;
                }
            case 2:
                registerAkun();
                break;
            case 3:
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
}
