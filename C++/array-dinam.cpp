#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int *pArray;

    pArray = new int[3];

    for(int i = 0; i < 3; i++) {
        cout << "value [" << i + 1 << "]: ";
        cin >> pArray[i];
    }

    for(int i = 0; i < 3; i++) {
        cout << "position [" << i + 1 << "]: " << pArray[i] << endl;
    }

    cout << "Again, but memory will remove." << endl;
    delete pArray;

    for(int i = 0; i < 10; i++) {
        cout << "position [" << i + 1 << "]: " << pArray[i] << endl;
    }

    return 0;
}
