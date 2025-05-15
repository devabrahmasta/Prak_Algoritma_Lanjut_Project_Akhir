#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <iostream>
#include "Utilitas.hpp"
#include <iomanip>
#include <fstream>
using namespace std;

struct gudang
{
    string namaBarang[1001]; //gudang terbatas ehe
    string idBarang[1001];
};

struct client
{
    string nama;
    gudang namaBarang;
};

// deklarasi global
// char pilihMenu;


void menambahItems();
void mengambilItems();
void mencariItems();
void historiItems();
void menampilkanItems();
void errorInput();

#endif