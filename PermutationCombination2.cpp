#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int MOD = 1000000007;

vector<long long> fact(MAX_N + 1);
vector<vector<long long>> npr(MAX_N + 1, vector<long long>(MAX_N + 1));
vector<vector<long long>> ncr(MAX_N + 1, vector<long long>(MAX_N + 1));

long long modInverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    for (int n = 0; n <= MAX_N; ++n) {
        for (int r = 0; r <= n; ++r) {
            npr[n][r] = (fact[n] * modInverse(fact[n-r], MOD)) % MOD;
            ncr[n][r] = (fact[n] * modInverse((fact[r] * fact[n-r]) % MOD, MOD)) % MOD;
        }
    }
}

int main() {
    precompute();

    int q;
    cin >> q;
    while (q--) {
        int n, r;
        cin >> n >> r;
        cout << "nPr = " << npr[n][r] << ", nCr = " << ncr[n][r] << endl;
    }

    return 0;
}




