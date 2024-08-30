#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    int num = n;

    while (num > 0) {
        ans = ans * 10 + (num % 10);
        num = num / 10;
    }

    if (ans == n) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
