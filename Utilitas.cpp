#include "Utilitas.hpp"

using namespace std;

void tampilkanHeader(){
    cout<<CYAN<<BOLD;
    cout << R"(  
  _________.___   _   _ __________    _____   
 /   _____/|   | / \ / \\______   \. /  _  \.  
 \_____  \.|   |/   Y   \|    |  _/ /  /_\  \. 
 /        \|   /    |    \    |   \/    |    \.
/_______  /|___\___/ \__ /______  /\____|__  /
        \/.            \/.      \/.        \/.          
          )";
    cout<<GREEN<<BOLD<<"SIMpan BArang"<<endl;
    cout<<RESET<<"Made by : ";
    cout<<RED<<"ARIZ";
    cout<<RESET<<" & ";
    cout<<BLUE<<"DEVA";
    
    
    cout << RESET << endl;  // Kembali ke warna default
}

void clearScreen(){
    system("cls");
    
    tampilkanHeader();
}