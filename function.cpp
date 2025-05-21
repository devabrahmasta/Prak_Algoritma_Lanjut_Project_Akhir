#include "function.hpp"

client daftarClient[1001];

bool ulangMenu(char ulang){    
    if(ulang == 'Y' || ulang == 'y')
        return true;
    else if(ulang == 'N' || ulang == 'n')
        return false;
    return false;
}

string gantiSpasi(string nama){
    string temp = nama;
    for (int i = 0; i < nama.length(); i++){
        if(temp[i] == ' '){
            temp[i] = '_';
        }
    }
    return temp;
}

void InputData(string nama, string barang, int idBarang, int hargaBarang){
    ofstream Database("dataGudang.txt", ios::app);
    if(Database.is_open()){
        Database << gantiSpasi(nama) << " " << barang << " " << idBarang << " " << hargaBarang << endl;
        Database.close();
    }else{
        cout << "ERROR" << endl;
    }
}

void menambahItems(){
    int idBarang, hargaBarang;
    char ulang;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menambah Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    do {
        cout << "Nama Pelanggan : ";
        cin.ignore();
        getline(cin, daftarClient[0].nama); // soon: gimana caranya 0 itu jadi nambah terus tanpa ada kesalahan 
        cout << "Nama Barang    : ";
        getline(cin, daftarClient[0].barang.nama[0]);
        cout << "ID Barang      : ";
        cin >> daftarClient[0].barang.id[0];
        cout << "Harga Barang   : ";
        cin >> hargaBarang;
        cout << "Tanggal        : (belum digunakan)" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        do{
            cout << "Ingin menambah lagi (y/n): ";
            cin >> ulang;
        }while((ulang != 'Y' && ulang != 'y') && (ulang != 'N' && ulang != 'n'));

        InputData(daftarClient[0].nama, daftarClient[0].barang.nama[0], daftarClient[0].barang.id[0], hargaBarang);
    }while (ulangMenu(ulang) == true);
}

void mengambilItems(){
    //MencariItems()
    string namaCari;
    cout << "Masukkan nama client yang mengambil barang: ";
    cin.ignore();
    getline(cin, namaCari);
    //Print Data yang diambil
    cout << "[INFO] Barang milik " << namaCari << " telah diambil. (Simulasi)" << endl;
    //Hapus data yang diambil -> belum diimplementasi
    //UpdateHistori
    ofstream histori("histori.txt", ios::app);
    if(histori.is_open()){
        histori << gantiSpasi(namaCari) << " contohBarang 1234 100000" << endl; // Dummy data
        histori.close();
    }
}

void mencariItems(){
    //Admin memasukkan nama Client 
    string namaClient;
    cout << "Masukkan nama client: ";
    cin.ignore();
    getline(cin, namaClient);
    //Untuk mengetahui barang apa saja yang disimpan
    cout << "Barang milik " << namaClient << ":" << endl;
    cout << "- Barang A" << endl;
    cout << "- Barang B" << endl;
    //Memunculkan semua data yang ditunjuk
}

void historiItems(){
    //menampilkan seluruh riwayat
    ifstream histori("histori.txt");
    string nama, barang;
    int id, harga;
    int total = 0;
    if(histori.is_open()){
        while(histori >> nama >> barang >> id >> harga){
            cout << "Nama: " << nama << ", Barang: " << barang << ", ID: " << id << ", Harga: Rp" << harga << endl;
            total += harga;
        }
        cout << "Total Keuntungan: Rp" << total << endl;
        histori.close();
    } else {
        cout << "Gagal membuka file histori." << endl;
    }
    // sorting ascending -> belum
    // search barang tertentu [opsional] -> belum
}

void menampilkanItems(){
    //pencarian file secara default
    ifstream data("dataGudang.txt");
    string nama, barang;
    int id, harga;
    if(data.is_open()){
        while(data >> nama >> barang >> id >> harga){
            cout << "Nama: " << nama << ", Barang: " << barang << ", ID: " << id << ", Harga: Rp" << harga << endl;
        }
        data.close();
    } else {
        cout << "File tidak ditemukan." << endl;
    }
}

int totalKeuntunganRekursif(ifstream &file, int total = 0) {
    string nama, barang;
    int id, harga;
    if (file >> nama >> barang >> id >> harga) {
        return totalKeuntunganRekursif(file, total + harga);
    } else {
        return total;
    }
}

int hitungTotalKeuntungan() {
    ifstream file("histori.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file histori!" << endl;
        return 0;
    }
    return totalKeuntunganRekursif(file);
}

void errorInput(){
    cout << "Input tidak valid, silakan coba lagi." << endl;
}
