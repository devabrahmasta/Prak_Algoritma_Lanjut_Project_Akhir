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
        \/.             \/.     \/.        \/.          
          )";
    cout<<GREEN<<BOLD<<"SIMpan BArang ONLINE"<<endl;
    cout<<RESET<<"Made by : ";
    cout<<RED<<"ARIZ";
    cout<<RESET<<" & ";
    cout<<BLUE<<"DEVA";
    
    
    cout << RESET << endl;  // Kembali ke warna default
}

void clearScreen(){
    system("cls");
    cout<<"\033[2J\033[H";
    cout<<"\033[1;1H";
    tampilkanHeader();
}