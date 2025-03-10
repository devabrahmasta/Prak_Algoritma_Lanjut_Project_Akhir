#include <iostream>
#include <iomanip>
using namespace std;

struct gudang
{
    string namaBarang[1001];
    string idBarang[1001];
};

struct akun_pengguna
{
    int ID;
    string username;
    string password;
    gudang namaBarang;
};

// penyimpanan gudang
// string barang[1001] = { // diganti nanti
//     "Laptop",
//     "Printer",
//     "Meja",
//     "Kursi",
//     "Rak Buku",
//     "Proyektor",
//     "Kabel Listrik",
//     "Papan Tulis",
//     "AC (Air Conditioner)",
//     "Lampu"

// };

// deklarasi global
akun_pengguna akun[1001];
akun_pengguna pengguna;
int jumlahakun = 0, q = 0;
char pilihMenu;
string username, password;
string ulangMenu;
bool kesempatan = false;
int kesempatanlogin = 3;

// Fungsi
void errorInput();
void loginPage();
void menambahItems();
void mengambilItems();
void mencariItems();
void historiItems();
void menuPage();

int main()
{
    system("cls");
    // loginPage();
    menuPage();
}

void errorInput()
{
    system("pause");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(4) << " " << "Mohon maaf Anda salah input" << endl
         << endl
         << endl;
    cout << setfill(' ') << setw(4) << " " << "Mohon masukkan input kembali" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void loginPage()
{
    char optionFalse;
    bool check_username = false;
    bool check_password = false;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "username : ";
    getline(cin, username);
    cout << "password : ";
    cin >> password;

    for (int i = 0; i <= jumlahakun; i++)
    {
        if (username == akun[i].username)
            check_username = true;
        if (password == akun[i].password)
            check_password = true;
        if (check_password == true && check_username == true)
        {
            break;
        }
        else
        {
            check_password = false;
            check_username = false;
        }
    }
    if (check_password == true && check_username == true)
    {
        cout << "Login Berhasil";
        cin.ignore();
        getchar();
        menuPage();
    }
    else
    {
        cout << "Username atau Password salah." << endl
             << "Tolong masukan yang benar atau buat akun dahulu" << endl;
        cin.ignore();
        getchar();

        cout << "Ingin mencoba lagi atau register? (1/2): ";
        cin >> optionFalse;
        getchar();
        if (optionFalse == 1)
            loginPage();
        else if (optionFalse == 2) // registerpage
            loginPage();
    }
}

void menambahItems()
{
    int quantity;
    bool add = true;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menambah Items" << endl;

    do
    {
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Ingin menambahkan berapa barang : ";
        cin >> quantity;
        cin.ignore();
        for (int i = 0; i < quantity; i++)
        {
            cout << "Masukkan nama barang ke-" << q + 1 << " Anda : ";
            getline(cin, pengguna.namaBarang.namaBarang[q]);
            q++;
        }

        cout << "\nIngin menambah barang kembali? (y/n): ";
        cin >> ulangMenu;
    } while (ulangMenu == "Y" || ulangMenu == "y");
    cout << setfill('=') << setw(40) << "=" << endl;
}

void mengambilItems() // sama kek hapus barang. logicnya itu cari dulu baru hapus.
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mengambil Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void mencariItems()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mencari Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void menampilkanItems()
{
    // akun_pengguna pengguna;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menampilkan Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    if (q == 0)
    {
        cout << "\nMohon tambahkan barang terlebih dahulu\n";
    }
    else
    {
        for (int i = 0; i < q; i++)
        {
            cout << i + 1 << ". " << pengguna.namaBarang.namaBarang[i] << endl;
        }
    }
    cout << setfill('=') << setw(40) << "=" << endl;
}

void historiItems()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Histori Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    
    if (q == 0)
    {
        cout << "\nMohon tambahkan barang terlebih dahulu\n";
    }
    else
    {
        for (int i = 0; i < q; i++)
        {
            cout << i + 1 << ". " << pengguna.namaBarang.namaBarang[i] << endl;
        }
    }
    cout << setfill('=') << setw(40) << "=" << endl;
}

void menuPage()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "SELAMAT DATANG DI GUDANG" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "0. Logout" << endl;
    cout << "1. Menambah item" << endl;
    cout << "2. Mengambil item" << endl;
    cout << "3. Mencari item" << endl;
    cout << "4. Menampilkan item" << endl;
    cout << "5. Histori" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Mau ngapain    : ";
    cin >> pilihMenu;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    switch (pilihMenu)
    {
    case '0':
        main();
        system("pause");
        break;
    case '1':
        menambahItems();
        break;
    case '2':
        mengambilItems();
        system("pause");
        break;
    case '3':
        mencariItems();
        system("pause");
        break;
    case '4':
        menampilkanItems();
        system("pause");
        break;
    case '5':
        historiItems();
        system("pause");
        break;

    default:
        errorInput();
        system("pause");
        menuPage();
        break;
    }
    cin.ignore();
    cout << "Kembali ke menu? (y/n) : ";
    cin >> ulangMenu;
    if (ulangMenu == "Y" || ulangMenu == "y")
    {
        menuPage();
    }
    else if (ulangMenu == "N" || ulangMenu == "n")
    {
        exit(0);
    }
    else
    {
        errorInput();
        system("pause");
        menuPage();
    }
}