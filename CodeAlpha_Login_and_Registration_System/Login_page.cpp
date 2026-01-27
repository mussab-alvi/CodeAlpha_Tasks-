#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password, confirm;

    cout << "Enter new username: ";
    cin >> username;

    // Validation: empty username
    if(username.empty()) {
        cout << "Error: Username cannot be empty!\n";
        return;
    }

    // Directly check if file exists (no bool function)
    ifstream checkFile(username + ".txt");
    if(checkFile) {
        cout << "Error: Username already exists! Choose another.\n";
        return;
    }
    checkFile.close();

    cout << "Enter new password: ";
    cin >> password;

    if(password.length() < 6) {
        cout << "Error: Password must be at least 6 characters long!\n";
        return;
    }

    cout << "Confirm password: ";
    cin >> confirm;

    if(password != confirm) {
        cout << "Error: Passwords do not match!\n";
        return;
    }

    ofstream file(username + ".txt");
    file << password;
    file.close();

    cout << "Registration Successful............!!!\n";
}

void loginUser() {
    string username, password, storedPass;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if(!file) {
        cout << "Error: Username not found!\n";
        return;
    }

    file >> storedPass;
    file.close();

    if(storedPass == password) {
        cout << "Login Successful....................!!!\n";
        cout << "Welcome, " << username << "!\n";
    } else {
        cout << "Invalid Username or Password !!!\n";
    }
}

int main() {
    int option;
    do {
        cout << "\n-----------------Menu------------------\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "---------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting Program...............!!!\n"; break;
            default: cout << "Invalid choice, kindly choose again.\n";
        }
    } while(option != 3);

    return 0;
}
