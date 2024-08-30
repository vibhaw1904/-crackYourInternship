#include <iostream>
using namespace std;

class Fibonacci {
public:
    void generateFibonacci(int n) {
        int t1 = 0, t2 = 1, nextTerm = 0;
        cout << "Fibonacci Series: ";

        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                cout << t1 << " ";
                continue;
            }
            if (i == 2) {
                cout << t2 << " ";
                continue;
            }
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;

            cout << nextTerm << " ";
        }
        cout << endl;
    }

    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }

    void printFibonacci(int n) {
        for (int i = 0; i < n; ++i) {
            cout << fib(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    Fibonacci fibonacci;

    int n;
    cout << "Enter the number: ";
    cin >> n;

    // Iterative approach
    fibonacci.generateFibonacci(n);

    // Recursive approach
    cout << "Recursive Fibonacci Series: ";
    fibonacci.printFibonacci(n);

    return 0;
}
