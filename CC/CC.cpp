#include <bits/stdc++.h>
using namespace std;

void error(string e) {
    string red = "\033[31m";
    string rem = "\033[0m";
    cout << red + e + rem;
}

void success(string e) {
    string grn = "\033[32m";
    string rem = "\033[0m";
    cout << grn + e + rem;
}

string encr(string msg, int key) {
    string cip;
    for(auto i:msg) i != ' ' ? cip += char((i - 'A' + key) % 26 + 'A') : cip += ' ';
    return cip;
}

string decr(string cip, int key) {
    string msg;
    for(auto i:cip) i != ' ' ? msg += char((26 + i - 'A' - key) % 26 + 'A') : msg += ' ';
    return msg;
}

string LOGO = "                 ______        ______\n  Himanshu      / ____/       / ____/\n   Mahaur      / /           / /\n2024PIS5020   / /___        / /___\n              \\____/ AESER  \\____/ IPHER\n";

int main() {
    string rawMsg;
    string orgMsg;

    string encMsg;
    string decMsg;

    int key;

    cout << LOGO << endl;

    cout << "Enter Message: ";
    getline(cin, rawMsg);

    for(auto i:rawMsg) orgMsg += toupper(i);
    cout << "Original Message: " << orgMsg << endl;

    while(true) {
        cout << "\nEnter Key: ";
        cin >> key;

        if(cin.fail()) {
            error("Error: The key entered is not a number.\n");
            cin.clear();
            cin.ignore(10, '\n');
        }
        else {
            success("Success: Encrypting the message now.\n");
            break;
        }
    }

    encMsg = encr(orgMsg, key);
    decMsg = decr(encMsg, key);

    cout << "\nEncypted Message: " << encMsg << endl;
    cout << "Decrypted Message: " << decMsg << endl;
    cout << "Original Message: " << orgMsg << endl;

    if(decMsg == orgMsg) success("\nSuccess: The message was encrypted and decrypted correctly!\n");
    else error("\nError: Decryption failed. The decrypted message does not match the original!\n");
    
    return 0;
}