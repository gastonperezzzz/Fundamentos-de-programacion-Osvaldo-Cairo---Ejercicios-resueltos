#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, j;
    int lengstr1, lengstr2;
    string phrase, phrase_enc;
    string alphabet = "abcdefghijklmnopqrstuvwxyzaABCDEFGHIJKLMNOPQRSTUVWXYZA";

    cout << "Ingrese una cadena de caracteres para encriptar: ";
    getline(cin, phrase, '\n');

    lengstr1 = phrase.length();
    lengstr2 = alphabet.length();

    for(i = 0; i < lengstr1; i++) {
        if(phrase.at(i) == ' ') {
                phrase_enc += ' ';
            }
        for(j = 0; j < lengstr2; j++) {
            if(phrase.at(i) == alphabet.at(j)) {
                phrase_enc += alphabet.at(j + 1);
                break;
            }
        }
    }

    cout << phrase_enc << endl;

    return 0;
}
