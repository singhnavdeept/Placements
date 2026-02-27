#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

using Matrix = vector<vector<long long>>;

int N;
long long K;

Matrix multiply(Matrix &A, Matrix &B) {

    Matrix result(N, vector<long long>(N, 0));

    for(int i = 0; i < N; i++) {

        for(int j = 0; j < N; j++) {

            for(int k = 0; k < N; k++) {

                result[i][j] =
                (result[i][j] + A[i][k] * B[k][j]) % MOD;

            }

        }

    }

    return result;
}

Matrix power(Matrix base, long long exp) {

    Matrix result(N, vector<long long>(N, 0));

    // Identity matrix
    for(int i = 0; i < N; i++)
        result[i][i] = 1;

    while(exp > 0) {

        if(exp % 2 == 1)
            result = multiply(result, base);

        base = multiply(base, base);

        exp /= 2;
    }

    return result;
}

int main() {

    cin >> N >> K;

    Matrix A(N, vector<long long>(N));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> A[i][j];

    Matrix answer = power(A, K);

    long long sum = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sum = (sum + answer[i][j]) % MOD;

    cout << sum;

}