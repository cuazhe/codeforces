#include <iostream>
#include <vector>
using namespace std;


void cal(int n) {
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    int N = 1e9 + 7;
    vector<vector<long long>> cnk(n + 1, vector<long long> (n + 1, 0));
    cnk[0][0] = 1;
    cnk[1][0] = 1;
    cnk[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if ((j == 0) || (j == i)) {
                cnk[i][j] = 1;
            }
            else {
                cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % N;
            }
        }
    }
    
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "i = " << i << " ; j = " << j << "; cnk[i][j] = " << cnk[i][j] << "\n";
        }
    }
    */
    
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[1][1] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if ((j == 1) || (j == i)) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + ((dp[i - 1][j] * j) % N);
                dp[i][j] %= N;
            }
        }
    }
    vector<long long> f(n, 0);
    f[1] = 1;
    long long cur;
    for (int i = 2; i < n; i++) {
        cur = 0;
        for (int j = 1; j <= i; j++) {
            cur += dp[i][j];
            cur %= N;
        }
        f[i] = cur % N;
    }
    
    long long res = 1;
    for (int i = 1; i < n; i++) {
        cur = (cnk[n][i] * f[i]) % N;
        res += cur;
        res %= N;
    }
    cout << res % N << "\n";
    return;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    cal(n);
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 436 ms, 25 MB.
// This is related to Bell number. 
