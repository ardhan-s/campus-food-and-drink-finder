#pragma once

#include <string>
using namespace std;

struct Menu {
    int id;
    string nama;
    string kategori; // Meal, Snack, Drink, Coffee, Other
    int harga;
    double rating;   // 1.0 - 5.0
};
