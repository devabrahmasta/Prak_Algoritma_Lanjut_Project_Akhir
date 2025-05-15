#include "function.hpp"

void menuPage();
void loginPage();
bool BacaFile(string Pengguna, string Kata_Sandi);

int main(){
    loginPage();
}
bool BacaFile(string Pengguna, string Kata_Sandi)
{   
    bool check=false;
    string Key_User=Pengguna,Key_Pass=Kata_Sandi,Username,Password;
    ifstream Database("dataAdmin.txt");
    if (Database.is_open()){
        while (Database >> Username >> Password){
            if(Key_User==Username&&Key_Pass==Password){
                check=true;
            }
        }
        Database.close();
    }
    else{
        cout << "File tidak ada" << endl;
        check=false;
    }
    return check;
}

void loginPage(){
    clearScreen();
    string username, password;
    cout << "Menu Login" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
    if(BacaFile(username, password)==true){
        cout << "Login Berhasil..."<< endl;
        cin.ignore();
        system("pause");
        
        menuPage();
    }else{
        loginPage();
    }
    
}

void menuPage(){
    clearScreen();
    int pilihMenu;
    string ulangMenu;
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