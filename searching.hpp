#pragma once

#include <string>
#include "struct.hpp"

void searchByID(const Menu daftar[], int jumlahData, int targetID);
void searchByNama(const Menu daftar[], int jumlahData, string keyword);
void searchByKategori(const Menu daftar[], int jumlahData, string kategori);
void filterByBudget(const Menu daftar[], int jumlahData, int maxBudget);