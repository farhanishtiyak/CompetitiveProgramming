#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string N;
    cin >> N;
    long long num = stoll(N);
    long long cur = 1;
    int x = 0;
    while (cur < num) {
        cur *= 3;
        x++;
    }

    if (cur == num) {
        cout << x << endl; 
    } else {
        cout << -1 << endl; 
    }

    return 0;
}
