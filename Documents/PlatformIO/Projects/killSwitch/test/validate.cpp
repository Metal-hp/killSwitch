//Function to validate password for killSwitch

#include <ostream>
#include <iostream>
using namespace std;

int main() {
    char key[10] = "Testing";
    char pass[10];
    
    cout << "Enter password: "; cin >> pass;
    
    if(pass == key)
        cout << "Granted";
    else if(pass != key)
        cout << "DENIED";
    
}
