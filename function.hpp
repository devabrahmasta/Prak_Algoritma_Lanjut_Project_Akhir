#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include "Utilitas.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct gudang
{
    string nama[1001]; //gudang terbatas ehe
    int id[1001];
};


struct client
{
    string nama;
    gudang barang;
};

// deklarasi global
// menu tambah:
// char pilihMenu;

void menambahItems();
void mengambilItems();
void mencariItems();
void historiItems();
void menampilkanItems();
void errorInput();

#endif