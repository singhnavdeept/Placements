#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    while (t--) {
        long long n;
        cin >> n;
        long long k = 1;
        for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
           k *= i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        k *= n;
    }
    
    cout << k << endl;
    }

    return 0;
}