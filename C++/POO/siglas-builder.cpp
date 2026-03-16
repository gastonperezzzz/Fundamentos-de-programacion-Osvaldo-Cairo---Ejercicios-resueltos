#include <cctype>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
    int i;
    string palabra;
    string siglas = "";

    cout << "Ingrese una palabra o frase: ";
    getline(cin, palabra, '\n');

    for(i = 0; i < (int)palabra.length(); i++) {
        if(i == 0) {
            siglas = siglas + palabra.at(i);
        }
        else if(palabra.at(i) == ' ' && isalpha(palabra.at(i + 1))) {
            siglas = siglas + palabra.at(i + 1);
        }
    }

    cout << siglas << endl;

    return 0;
}
