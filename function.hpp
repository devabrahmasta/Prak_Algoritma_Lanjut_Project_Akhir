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
    string nama; 
    int id;
    int harga;
    string status; 
};


struct client
{
    string nama;
    gudang barang;
};


void sortInsertion();
void menambahItems();
void mengambilItems();
void mencariItems();
void historiItems();
void menampilkanItems();
void errorInput();
int totalKeuntunganRekursif(ifstream &file, int total);
int hitungTotalKeuntungan();
void bacaIDTerakhir(int *idTerakhir);
string gantiUnderscore(string nama);
string gantiSpasi(string nama);
extern void menuPage();

#endif