#include <iostream>
#include <string>

using namespace std;

int vocal(char);

int main() {
    string name;
    unsigned int cont = 0;

    cout << "Put your name: ";
    getline(cin, name, '\n');

    for(int i = 0; i < name.length(); i++) {
        if(vocal(name.at(i))) {
            cont++;
        }
    }

    cout << "Your name has " << cont << " vocals." << endl;

    return 0;
}

int vocal(char a) {
    string vocals = "aeiouAEIOU";

    for(int i = 0; i < vocals.length(); i++) {
        if(vocals.at(i) == a) {
            return 1;
        }
    }

    return 0;
}
