#pragma once

#include <string>
#include "struct.hpp"

void searchByID(const Menu daftar[], int jumlahData, int targetID);
void searchByNama(const Menu daftar[], int jumlahData, string keyword);
void searchByKategori(const Menu daftar[], int jumlahData, string kategori);
void filterByBudget(const Menu daftar[], int jumlahData, int maxBudget);
bool mengandung(const string& teks, const string& kata) {
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