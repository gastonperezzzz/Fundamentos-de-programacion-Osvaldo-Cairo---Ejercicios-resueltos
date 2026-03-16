#include <iostream>

using namespace std;

int main() {
    int array[5] = {2, 4, 6, 8, 10};
    int *p_array;

    p_array = &array[0];

    for(int i = 0; i < 5; i++) {
        cout << "Posicion [" << i << "]: " << *(p_array + i) << endl;
    }

    return 0;
}