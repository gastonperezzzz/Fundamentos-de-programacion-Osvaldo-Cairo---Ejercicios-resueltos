#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec(100);

    cout << "Vector size: " << vec.size() << endl;

    vector<int>().swap(vec);

    cout << "Vector size: " << vec.size() << endl;

    return 0;
}
