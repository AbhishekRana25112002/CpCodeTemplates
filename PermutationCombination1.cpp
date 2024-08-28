//Permutation
long long nPr(int n, int r) {
    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
    }
    return result;
}

//Combination
long long nCr(int n, int r) {
    if (r > n - r) r = n - r;  // Use symmetry property
    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

//Easy code for filling ncr table
int mod = 1e9 + 7;
vector<vector<int>> ncr;
void fillncr(int n) {
    ncr.resize(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; ++i) {
        ncr[i][0] = 1;
        ncr[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            ncr[i][j] = (ncr[i - 1][j] % mod + ncr[i - 1][j - 1] % mod) % mod;
        }
    }
}


