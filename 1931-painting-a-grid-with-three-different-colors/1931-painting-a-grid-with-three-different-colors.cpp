const int mod = 1e9 + 7;
using matrix = vector<vector<int>>;
static matrix I;

matrix Id(int sz) {
    matrix I(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; i++)
        I[i][i] = 1;
    return I;
}

// modular matrix multiplication
matrix operator*(const matrix& A, const matrix& B) {
    const int n = A.size(), p = A[0].size(), q = B.size(), m = B[0].size();
    if (p != q)
        return {};
    matrix C(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < p; k++) {
            for (int j = 0; j < m; j++) {
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

// MSBF modular Matrix Exponentiation
matrix modPow(const matrix& M, unsigned n, int sz) {
    if (n == 0)
        return I;
    bitset<32> B(n);
    int bMax = 31 - countl_zero(n);
    matrix ans = M;
    for (int i = bMax - 1; i >= 0; i--) {
        ans = ans * ans;
        if (B[i])
            ans = ans * M;
    }
    return ans;
}

// int modular exponentiation
int modPow(int base, unsigned n) {
    if (n == 0)
        return 1;

    bitset<32> B(n);
    int bMax = 31 - countl_zero(n);
    long long ans = 1;
    long long b = base % mod;

    for (int i = bMax; i >= 0; i--) {
        ans = (ans * ans) % mod;
        if (B[i])
            ans = (ans * b) % mod;
    }
    return ans;
}
matrix M3 ={{3, 2}, 
            {2, 2}};
matrix M4 ={{3, 2, 1, 2}, 
            {2, 2, 1, 2}, 
            {1, 1, 2, 1}, 
            {2, 2, 1, 2}};
matrix M5 ={{3, 2, 2, 1, 0, 1, 2, 2},
            {2, 1, 2, 1, 1, 1, 1, 2},
            {2, 2, 2, 1, 0, 1, 2, 2}, 
            {1, 1, 1, 1, 1, 2, 1, 1},
            {0, 1, 0, 1, 2, 1, 0, 1}, 
            {1, 1, 1, 2, 1, 1, 1, 1},
            {2, 1, 2, 1, 0, 1, 2, 1}, 
            {2, 2, 2, 1, 1, 1, 1, 1}};
class Solution {
public:
    matrix M;
    int colorTheGrid(int m, int n) {

        switch(m){
            case 1: return 3LL * modPow(2, n - 1) % mod;
            case 2: return 6LL * modPow(3, n - 1) % mod;
            case 3: M=M3; break;
            case 4: M=M4; break;
            case 5: M=M5;
        }
        int sz = 1 << (m - 2); // number of patterns
        I = Id(sz);
        matrix A = modPow(M, n-1, sz);
        long long ans = 0;
        for (int i=0; i < sz; i++) {
            long long rowSum=reduce(A[i].begin(), A[i].end(), 0LL) % mod;
            ans=(ans+(6LL*rowSum) % mod) %mod; // each Type has 6 combinations
        }
        return ans;
    }
};