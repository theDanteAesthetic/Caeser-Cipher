#include <iostream>
#include <string>

using namespace std;

const int maxchar = 'z';
const int minchar = ' ';
const int charrange = 1 + maxchar - minchar;

//A mod function that is "safe" to use even when val might be negative

char safemod(int val, int mod) {
int modval = val % mod;
if (modval < 0) {
    modval += mod;
}
return char(modval + 32);
}

//encode: a function that takes a message and key, and returns the encrypted
//message
//decode: a function that takes an encrypted message and key, and returns the
//original message
//main: function for managing the user interface

string encode(string message, string key){
    string result = "";
    for(int i = 0; i < message.size(); i++){
        char messageChar = message[i];
        char keyChar = key[i % key.size()];
        int messageIndex = (int)messageChar - (int)minchar;
        int keyIndex = (int)keyChar - (int)minchar;
        int encryptedIndex = (messageIndex + keyIndex) % charrange;
        char encryptedChar = static_cast<char>(encryptedIndex + (int)minchar);
        result += encryptedChar;
    }
    return result;
}

string decode(string message, string key){
    string result = "";
    for(int i = 0; i < message.size(); i++){
        char messageChar = message[i];
        char keyChar = key[i % key.size()];
        int messageIndex = (int)messageChar;
        int keyIndex = (int)keyChar;
        int encryptedIndex = safemod((messageIndex - keyIndex), charrange);
        char encryptedChar = static_cast<char>(encryptedIndex);
        result += encryptedChar;
    }
    return result;
}
int main(){
    string answer;
    string message;
    string key;

    cout << "Would you like to encode or decode a message?" << endl;
    cin >> answer;

    if(answer != ""){
        if(answer != "encode" && answer != "decode"){
            cout << "Sorry! I didn't quite catch that! Please answer either 'encode' or 'decode'" << endl;
            cout << "Would you like to encode or decode a message?" << endl;
            cin >> answer;
        }
        cout << "What message would you like to " << answer << endl;
        cin >> message; //I tried using getline() so it didn't ignore whitespace but it didn't work
        if(answer == "encode"){
            cout << "What encryption key would you like to use?" << endl;
            cin >> key;
            cout << "encoded message: " << encode(message, key) << endl;
        }
        if(answer == "decode"){
            cout << "What decryption key would you like to use?" << endl;
            cin >> key;

            cout << "decoded message: " << decode(message, key) << endl;
        }
        }
    
    
}