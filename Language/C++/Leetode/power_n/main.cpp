#include <iostream>

using namespace std;

double power_n_0(double a, int n) {
    double res = 1;
    if(n < 0) {
        n = -n;
        a = 1.0/a;
    }

    for(int i = 0; i < n; ++i) {
        res *= a;
    }

    return res;
}

double power_n_1(double a, int n) {
    if(n < 0) {
        n = -n;
        a = 1.0/a;
    }
    if(n == 0) return 1;
    if(n == 1) return a;

    return (n/2?a:1)*power_n_1(a*a, n/2);
}

int main() {
    int a = 2;
    int n = -3;

    cout << power_n_1(a, n) << endl;
    return 0;
}