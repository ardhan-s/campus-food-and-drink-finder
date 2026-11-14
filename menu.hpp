#pragma once

#include "struct.hpp"

string getPriceLabel(int harga);
void addData(Menu daftar[], int &jumlahData);
void displayData(const Menu daftar[], int jumlahData);
void calculateSummary(const Menu daftar[], int jumlahData);
void saveData(const Menu daftar[], int jumlahData);
void loadData(Menu daftar[], int &jumlahData);