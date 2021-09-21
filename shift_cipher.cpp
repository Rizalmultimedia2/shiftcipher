#include <iostream>
#include <string>
using namespace std;
string encrypt(string text, int key)
{
    string result;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            result += ' ';
        else if (isupper(text[i]))
            result += char(int(text[i] + key - 65) % 26 + 65);
        else
            result += char(int(text[i] + key - 97) % 26 + 97);
    }
    return result;
}

string decrypt(string text, int key)
{
    return encrypt(text, 26 - key);
}

int main()
{
    string text;
    int key;
    int option;
    bool loop = true;
    cout << "-- SHIFT CIPHER PROGRAM --";
    while (loop)
    {
        cin.ignore();
        cout << "\nMasukkan Text: \n";
        getline(cin, text);
        cout << "\nMasukkan Key (0-25): \n";
        cin >> key;
        cout << "\nHasil Enkripsi: " << encrypt(text, key) << '\n';
        cout << "Hasil Dekripsi: " << decrypt(encrypt(text, key), key) << '\n';
        cout << "Apakah akan diulang? (y/n): ";
        char option;
        cin >> option;
        if (option == 'y' || option == 'Y')
            loop = true;
        else
            loop = false;
    }
    return 0;
}
