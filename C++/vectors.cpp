#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vInt(3);

    for(int i = 0; i < 3; i++) {
        cout << "Put vector value [" << i + 1 << "]: ";
        cin >> vInt[i];
    }

    for(int i = 0;i < 3; i++) {
        cout << "Value [" << i + 1 << "]: " << vInt[i] << endl;
    }

    return 0;
}
