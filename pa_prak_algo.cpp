#include <iostream>
#include <iomanip>
using namespace std;


struct akun_pengguna{
    int ID;
    string username;
    string password;
};

akun_pengguna akun[1001];
int jumlahakun=0;
char pilihMenu;
string username, password;
string ulangMenu;
bool kesempatan = false;
int kesempatanlogin = 3;

//Fungsi
void errorInput();
void loginPage();
void menaruhItems();
void mengambilItems();
void mencariItems();
void menuPage();


int main(){
    loginPage();
}

void errorInput(){
    system("pause");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(4) << " " << "Mohon maaf Anda salah input" << endl
         << endl
         << endl;
    cout << setfill(' ') << setw(4) << " " << "Mohon masukkan input kembali" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void loginPage(){
    bool check_username=false;
    bool check_password=false;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "username : ";
    getline(cin, username);
    cout << "password : ";
    cin >> password;

    for(int i=0;i<=jumlahakun;i++){
        if(username==akun[i].username) check_username=true;
        if(password==akun[i].password) check_password=true;
        if(check_password==true&&check_username==true){
            break;
        }
        else {
            check_password=false;
            check_username=false;
        }
    }
    if(check_password==true&&check_username==true){
        cout<<"Login Berhasil";
        cin.ignore();
        getchar();
        menuPage();
    }
    else {
        cout<<"Username atau Password salah. Tolong masukan yang benar atau buat akun dahulu"<<endl;
        cin.ignore();
        getchar();
    }
}

void menaruhItems(){
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menaruh Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void mengambilItems(){
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mengambil Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void mencariItems(){
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Mencari Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void menuPage(){
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
}