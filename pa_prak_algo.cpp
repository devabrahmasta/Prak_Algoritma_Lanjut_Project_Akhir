#include <iostream>
#include <iomanip>
using namespace std;

struct akun_pengguna
{
    int ID;
    string username;
    string password;
};

//deklarasi global
akun_pengguna akun[1001];
int jumlahakun = 0;
char pilihMenu;
string username, password;
string ulangMenu;
bool kesempatan = false;
int kesempatanlogin = 3;

// Fungsi
void errorInput();
void loginPage();
void menaruhItems();
void mengambilItems();
void mencariItems();
void menuPage();

void registerID();

int main()
{
    loginPage();
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
    char pil_akun;
    char optionFalse;
    bool check_username = false;
    bool check_password = false;
    cout<<"Apakah sudah punya akun?(y/n): ";
    cin>>pil_akun;
    if(pil_akun=='y'||pil_akun=='Y'){
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "username : ";
        cin.ignore();
        getline(cin, username); //Nanti diganti
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
            else if(optionFalse == 2) // registerpage
                loginPage();
            

        }
    }
    else if(pil_akun=='n'||pil_akun=='N'){
        cout<<"Buat akun terlebih dahulu"<<endl;
        system("pause");
        registerID();
    }
    else {
        cout<<"Input tidak ada yang cocok."<<endl;
        cout<<"Kembali ke Login Page"<<endl;
        system("pause");
        loginPage();
    }
    
}

void menaruhItems()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(8) << " " << "Menaruh Items" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void mengambilItems()
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
}

void registerID(){
    jumlahakun++;
    cout<<"============MEMBUAT AKUN============="<<endl;
    for(int i=jumlahakun;i<=jumlahakun;i++){
        akun[i].ID=i;
        cout<<"Masukkan Username: ";
        cin>>akun[i].username;
        cout<<"Masukkan Password: ";
        cin>>akun[i].password;
    }
    cin.get();
    loginPage();
}