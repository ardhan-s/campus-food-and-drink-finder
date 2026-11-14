#include <iostream>
#include <iomanip>
#include "searching.hpp"
#include "menu.hpp"
using namespace std;
bool mengandung(const string teks, const string kata) {
    int n = teks.length();
    int m = kata.length();
    if (m == 0) return true;
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && teks[i + j] == kata[j]) {
            j++;
        }
        if (j == m) return true;
    }
    return false;
}
void searchByID(const Menu daftar[], int jumlahData, int targetID){
    for ( int i = 0; i < jumlahData; i++ ) {
        if ( daftar[i].id == targetID ) {
            cout << "\n\033[1;36m-- MENU DITEMUKAN --------------------------------------\033[0m\n";
            cout << left << setw(10) << "ID" << ": " << daftar[i].id << endl;
            cout << left << setw(10) << "Nama" << ": " << daftar[i].nama << endl;
            cout << left << setw(10) << "Kategori" << ": " << daftar[i].kategori << endl;
            cout << left << setw(10) << "Harga" << ": Rp" << daftar[i].harga << endl;
            cout << left << setw(10) << "Rating" << ": " << daftar[i].rating << endl;
            return;
        }
    }
    cout << "\033[33mMenu tidak ditemukan.\033[0m\n";
}

void searchByNama(const Menu daftar[], int jumlahData, string keyword){
    bool found = false;
    for ( int i = 0; i < jumlahData; i++ ) {
        if (mengandung(daftar[i].nama, keyword)) {
            if (!found) {
                cout << "\n\033[1;36m-- MENU DITEMUKAN --------------------------------------\033[0m\n";
            }
            cout << left << setw(10) << "ID" << ": " << daftar[i].id << endl;
            cout << left << setw(10) << "Nama" << ": " << daftar[i].nama << endl;
            cout << left << setw(10) << "Kategori" << ": " << daftar[i].kategori << endl;
            cout << left << setw(10) << "Harga" << ": Rp" << daftar[i].harga << endl;
            cout << left << setw(10) << "Rating" << ": " << daftar[i].rating << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\033[33mMenu tidak ditemukan.\033[0m\n";
    }
}

void searchByKategori(const Menu daftar[], int jumlahData, string kategori) {
    if (jumlahData == 0) {
        cout << "\033[33mBelum ada data.\033[0m\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < jumlahData; i++) {
        if (daftar[i].kategori == kategori) {
            if (!found) {
                cout << "\n\033[1;36m-- MENU DITEMUKAN --------------------------------------\033[0m\n";
                cout << "\033[1;33m" << left << setw(6) << "ID" << setw(24) << "Nama Menu" << setw(12) << "Kategori" << setw(12) << "Harga" << setw(9) << "Rating" << "Label\033[0m\n";
                cout << "\033[90m----------------------------------------------------------------------\033[0m\n";
            }

            string label = getPriceLabel(daftar[i].harga);
            string warnaLabel = "\033[32m";
            if (label == "Medium") {
                warnaLabel = "\033[33m";
            } else if (label == "Premium") {
                warnaLabel = "\033[31m";
            }

            cout << left << setw(6) << daftar[i].id << setw(24) << daftar[i].nama << setw(12) << daftar[i].kategori << "Rp" << setw(10) << daftar[i].harga << setw(9) << daftar[i].rating << warnaLabel << label << "\033[0m\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\033[33mMenu tidak ditemukan.\033[0m\n";
    }
}

void searchByBudget(const Menu daftar[], int jumlahData, int maxBudget){
    bool found = false;
    for ( int i = 0; i < jumlahData; i++ ) {
        if ( daftar[i].harga <= maxBudget ) {
            if (!found) {
                cout << "\033[1;33m" << left << setw(6) << "ID" << setw(24) << "Nama Menu" << setw(12) << "Kategori" << setw(12) << "Harga" << setw(9) << "Rating" << "Label\033[0m\n";
                cout << "\033[90m----------------------------------------------------------------------\033[0m\n";
            }
            string label = getPriceLabel(daftar[i].harga);
            string warnaLabel = "\033[32m";
            if (label == "Medium") {
                warnaLabel = "\033[33m";
            } else if (label == "Premium") {
                warnaLabel = "\033[31m";
            }

            cout << left << setw(6) << daftar[i].id << setw(24) << daftar[i].nama << setw(12) << daftar[i].kategori << "Rp" << setw(10) << daftar[i].harga << setw(9) << daftar[i].rating << warnaLabel << label << "\033[0m\n";
            found = true;
        }
    }
    if (!found) {
        cout << "\033[33Tidak ada menu yang sesuai dengan budget yang ditentukan.\033[0m" << endl;
    }
}