#include "function.hpp"

client daftarClient[1001];
int harga;
int jmlh = 0;

void sortInsertion()
{
    client sorted[1000]; 
    int size = 0;

    ifstream data("dataGudang.txt");
    if (data.is_open()) {
        while (data >> daftarClient[size].nama >> daftarClient[size].barang.nama >> daftarClient[size].barang.id >> daftarClient[size].barang.harga) {
            size++;
        }
        data.close();
    } else {
        cout << "ERROR: File tidak ditemukan." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        sorted[i] = daftarClient[i];
    }

    for (int i = 1; i < size; i++) {
        client temp = sorted[i]; 
        int j = i - 1;
        while (j >= 0 && sorted[j].barang.harga > temp.barang.harga) {
            sorted[j + 1] = sorted[j]; 
            j--;
        }
        sorted[j + 1] = temp; 
    }

    cout << setfill('=') << setw(60) << "=" << endl;
    cout << setfill(' ')
         << setw(20) << left << "Nama"
         << setw(20) << left << "Barang"
         << setw(5) << left << "ID"
         << setw(10) << left << "Harga" << endl;
    cout << setfill('=') << setw(60) << "=" << endl;

    for (int i = 0; i < size; i++) {
        cout << setfill(' ')
             << setw(20) << left << gantiUnderscore(sorted[i].nama)
             << setw(20) << left << gantiUnderscore(sorted[i].barang.nama)
             << setw(5) << left << sorted[i].barang.id
             << "Rp" << sorted[i].barang.harga << endl;
    }

    cout << "\nData telah diurutkan berdasarkan harga termurah." << endl;

}

bool ulangMenu(char ulang)
{
    if (ulang == 'Y' || ulang == 'y')
        return true;
    else if (ulang == 'N' || ulang == 'n')
        return false;
    return false;
}

string gantiSpasi(string nama)
{
    string temp = nama;
    for (int i = 0; i < nama.length(); i++)
    {
        if (temp[i] == ' ')
        {
            temp[i] = '_';
        }
    }
    return temp;
}

string gantiUnderscore(string nama)
{
    string temp = nama;
    for (int i = 0; i < nama.length(); i++)
    {
        if (temp[i] == '_')
        {
            temp.replace(i, 1, 1, ' ');
        }
    }
    nama = temp;
    return nama;
}

void bacaIDTerakhir(int *idTerakhir)
{
    ifstream data("dataGudang.txt");
    string nama, barang;
    int id, harga;
    *idTerakhir = 0;
    if (data.is_open())
    {
        while (data >> nama >> barang >> id >> harga)
        {
            *idTerakhir = id;
        }
        data.close();
    }
    else
    {
        cout << "File tidak ditemukan" << endl;
    }
}

void InputData(string nama, string barang, int idBarang, int hargaBarang)
{
    ofstream data("dataGudang.txt", ios::app);
    if (data.is_open())
    {
        data << gantiSpasi(nama) << " " << gantiSpasi(barang) << " " << idBarang << " " << hargaBarang << endl;
        data.close();
    }
    else
    {
        cout << "File tidak ditemukan" << endl;
    }
}

void menambahItems()
{
    char ulang;
    int idBarang;

    clearScreen();
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menambah Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    do
    {
        cout << "Nama Pelanggan : ";
        cin.ignore();
        getline(cin, daftarClient[jmlh].nama);
        cout << "Nama Barang    : ";
        getline(cin, daftarClient[jmlh].barang.nama);
        bacaIDTerakhir(&idBarang);
        idBarang++;
        daftarClient[jmlh].barang.id = idBarang;
        cout << "ID Barang      : " << daftarClient[jmlh].barang.id << endl;
        cout << "Harga Barang   : ";
        cin >> daftarClient[jmlh].barang.harga;

        InputData(daftarClient[jmlh].nama,
                  daftarClient[jmlh].barang.nama,
                  daftarClient[jmlh].barang.id,
                  daftarClient[jmlh].barang.harga);
        jmlh++;

        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Ingin menambah barang lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'Y' || ulang == 'y');
}

void mengambilItems()
{
    int idBarang;

    clearScreen();
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mengambil Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    cout << "Masukkan ID barang yang diambil: ";
    cin >> idBarang;

    ifstream data("dataGudang.txt");
    string nama, barang;
    int id, harga;
    bool found = false;

    if (data.is_open())
    {
        while (data >> nama >> barang >> id >> harga)
        {
            if (id == idBarang)
            {
                char konfirmasi;
                cout << "Nama Pengguna  : " << gantiUnderscore(nama) << endl;
                cout << "Nama Barang    : " << gantiUnderscore(barang) << endl;
                cout << "ID Barang      : " << id << endl;
                cout << "Harga Barang   : Rp" << harga << endl;
                cout << "Apakah " << nama << "yakin ingin mengambil barang ini?(y/n) : " << endl;
                cin >> konfirmasi;
                if (konfirmasi == 'Y' || konfirmasi == 'y')
                {
                    // Masukin ke TambahItem
                    cout << "Barang milik " << nama << " dengan ID " << idBarang << " telah diambil." << endl;
                    found = true;

                    ofstream histori("histori.txt", ios::app);
                    if (histori.is_open())
                    {
                        histori << gantiSpasi(nama) << " " << gantiSpasi(barang) << " " << id << " " << harga << endl;
                        histori.close();
                    } 
                    // Masukin ke TambahItem
                }
                else if (konfirmasi == 'N' || konfirmasi == 'n')
                {
                    cout << "Pengambilan dibatalkan." << endl;
                }
            }
        }
        data.close();
    }
    else
    {
        cout << "File tidak ditemukan." << endl;
    }
    if (!found)
    {
        cout << "Tidak ada barang dengan ID " << idBarang << endl;
    }
}

// void mengambilItems() {
//     string namaCari;
//     int idBarang;
//     cout << "Masukkan nama client yang mengambil barang: ";
//     cin.ignore();
//     getline(cin, namaCari);
//     cout << "Masukkan ID barang yang diambil: ";
//     cin >> idBarang;

//     ifstream data("dataGudang.txt");
//     ofstream temp("temp.txt");                        ==>> temp.txt
//     string nama, barang;
//     int id, harga;
//     bool found = false;

//     if (data.is_open() && temp.is_open()) {
//         while (data >> nama >> barang >> id >> harga) {
//             if (gantiUnderscore(nama) == namaCari && id == idBarang) {
//                 cout << "[INFO] Barang milik " << namaCari << " dengan ID " << idBarang << " telah diambil." << endl;
//                 found = true;
//                 // Simpan ke histori
//                 ofstream histori("histori.txt", ios::app);
//                 if (histori.is_open()) {
//                     histori << gantiSpasi(namaCari) << " " << gantiSpasi(barang) << " " << id << " " << harga << endl;
//                     histori.close();
//                 }
//             } else {
//                 // Simpan barang yang tidak diambil ke file sementara
//                 temp << gantiSpasi(nama) << " " << gantiSpasi(barang) << " " << id << " " << harga << endl;
//             }
//         }
//         data.close();
//         temp.close();
//         // Ganti file asli dengan file sementara
//         remove("dataGudang.txt");
//         rename("temp.txt", "dataGudang.txt");
//     } else {
//         cout << "File tidak ditemukan." << endl;
//     }

//     if (!found) {
//         cout << "Tidak ada barang dengan ID " << idBarang << " untuk " << namaCari << "." << endl;
//     }


// Sama aja kita timpa dengan ofstream dengan input ulang

void mencariItems()
{
    clearScreen();
    string client;
    string nama, barang;
    int id, harga;
    bool found = false;

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mencari Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan nama client: ";
    cin.ignore();
    getline(cin, client);

    ifstream data("dataGudang.txt");
    cout << "Barang milik " << client << ":" << endl;
    if (data.is_open())
    {
        while (data >> nama >> barang >> id >> harga)
        {
            if (gantiUnderscore(nama) == client)
            {
                cout << "- " << gantiUnderscore(barang) << " (ID: " << id << ")( Harga: Rp" << harga << ")" << endl;
                found = true;
            }
        }
        data.close();
    }
    else
    {
        cout << "File tidak ditemukan" << endl;
    }

    if (!found)
    {
        cout << "Barang tidak ditemukan" << endl;
    }
}

void historiItems()
{
    clearScreen();
    string nama, barang;
    int id, harga;
    int total = 0;
    char pilihMenu, ulang;
    ifstream histori("histori.txt");
    do{

        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(8) << " " << "Histori Items" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "1. Menampilkan Histori" << endl;
        cout << "2. Menampilkan Total Keuntungan" << endl;
        cout << "3. Sorting Histori " << endl; //=======>> belum tau namanya
        cout << "4. Exit History" << endl;
        cout << "Pilih : ";
        cin >> pilihMenu;
        switch (pilihMenu)
        {
        case '1': // Ifstream gabisa di dalam switch
            if (histori.is_open())
            {
                while (histori >> nama >> barang >> id >> harga)
                {
                    cout << "Nama: " << nama << ", Barang: " << barang << ", ID: " << id << ", Harga: Rp" << harga << endl;
                }
            }
            else
            {
                cout << "Gagal membuka file histori." << endl;
            }
            break;
        case '2':
            if (histori.is_open())
            {
                while (histori >> nama >> barang >> id >> harga)
                {
                    cout << "Harga: Rp" << harga << endl;
                    total += harga;
                }
                cout << setfill('-') << setw(12) << " +" << endl;
                cout << "Total Keuntungan: Rp" << total << endl;
            }
            else
            {
                cout << "Gagal membuka file histori." << endl;
            }
            break;
        case '3':
            sortInsertion();
            break;
        case '4':
            menuPage();
            break;
        default:
            cout << "Input tidak sesuai.\n Tolong Input yang sesuai\n";
            cin.ignore();
            system("pause");
            historiItems();
            break;
        }
        histori.close();
        // sorting ascending -> belum
        // search barang tertentu [opsional] -> belum
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Kembali ke menu histori? (y/n) : ";
        cin >> ulang;
    }while(ulang == 'Y' || ulang == 'y');
}

void menampilkanItems()
{
    clearScreen();
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menampilkan Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    ifstream data("dataGudang.txt");
    string nama, barang;
    int id, harga;
    if (data.is_open())
    {
        cout << setfill('=') << setw(40) << endl;
        cout << setfill(' ')
             << setw(25) << left << "Nama"
             << setw(15) << left << "Barang"
             << setw(5) << left << "ID"
             << setw(10) << left << "Harga" << " " << endl;
        cout << setfill('=') << setw(40) << endl;
        while (data >> nama >> barang >> id >> harga)
        {
            cout << setfill(' ')
                 << setw(25) << left << gantiUnderscore(nama)
                 << setw(15) << left << gantiUnderscore(barang)
                 << setw(5) << left << id
                 << "Rp" << setw(10) << left << harga << endl;
        }
        data.close();
    }
    else
    {
        cout << "File tidak ditemukan." << endl;
    }
}

int totalKeuntunganRekursif(ifstream &file, int total)
{
    string nama, barang;
    int id, harga;
    if (file >> nama >> barang >> id >> harga)
    {
        return totalKeuntunganRekursif(file, total + harga);
    }
    else
    {
        return total;
    }
}

int hitungTotalKeuntungan()
{
    ifstream file("histori.txt");
    if (!file.is_open())
    {
        cout << "Gagal membuka file histori!" << endl;
        return 0;
    }
    return totalKeuntunganRekursif(file, 0);
}

void errorInput()
{
    cout << "Input tidak valid, silakan coba lagi." << endl;
}