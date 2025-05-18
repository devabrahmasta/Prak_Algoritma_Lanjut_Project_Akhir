#include "function.hpp"

client daftarClient[1001];

bool ulangMenu(char ulang){    
    if(ulang == 'Y' || ulang == 'y')
        return true;
    else if(ulang == 'N' || ulang == 'n')
        return false;

}

string gantiSpasi(string nama){
    string temp = nama;
    for (int i = 0; i < nama.length(); i++){
        if(temp[i] == ' '){
            temp.replace(i,1,1,'_');
        }
    }
    
}
void InputData(string nama, string barang, int idBarang){
    ofstream Database("dataGudang.txt", ios::app);
    if(Database.is_open()){
        Database << gantiSpasi(nama) << barang << idBarang;
        Database.close();
    }else{
        cout << "EROR" << endl;
    }
}


void menambahItems(){
    int start;
    char ulang;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menambah Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;\
    do
    {
        cout << "Nama Pelanggan : ";
        getline(cin, daftarClient[0].nama); // soon: gimana caranya 0 itu jadi nambah terus tanpa ada kesalahan 
        cin.ignore();
        cout << "Nama Barang    : ";
        getline(cin, daftarClient[0].barang.nama[0]);
        cout << "ID Barang      : ";
        cout << "Tanggal        : ";
        cout << setfill('=') << setw(40) << "=" << endl;
        do{
            cout << "Ingin menambah lagi (y/n): ";
            cin >> ulang;
        }while((ulang != 'Y' || ulang != 'y' )&&(ulang != 'N' || ulang != 'n' ));
        InputData(daftarClient[0].nama, daftarClient[0].barang.nama[0], daftarClient[0].barang.id[0]);
    }while (ulangMenu(ulang) == true);
    
    
}
void mengambilItems(){

}
void mencariItems(){

}
void historiItems(){

}

void menampilkanItems(){

}

void errorInput(){
    
}