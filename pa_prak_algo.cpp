#include <iostream>
#include <iomanip>
using namespace std;

char pilihMenu;
string username, password, ulangMenu;
bool kesempatan = false;
int kesempatanlogin = 3;

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
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "username : ";
    getline(cin, username);
    cout << "password : ";
    cin >> password;
}

void menaruhItems()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menaruh Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
};

void mengambilItems()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mengambil Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
};

void mencariItems()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mencari Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
};

void menuPage()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "SELAMAT DATANG DI GUDANG" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Menaruh item" << endl;
    cout << "2. Mengambil item" << endl;
    cout << "3. Mencari item" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Mau ngapain    : ";
    cin >> pilihMenu;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    switch (pilihMenu)
    {
    case '1':
        menaruhItems();
        system("pause");
        break;
    case '2':
        mengambilItems();
        system("pause");
        break;
    case '3':
        mencariItems();
        system("pause");
        break;

    default:
        errorInput();
        system("pause");
        menuPage();
        break;
    }
    cout << "ingin kembali? (y/n) : ";
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
};

int main()
{
    loginPage();
    menuPage();
};
