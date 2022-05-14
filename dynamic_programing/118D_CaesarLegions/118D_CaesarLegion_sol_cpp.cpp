#include <iostream>
#include <vector>
using namespace std;

int solve(int n1, int n2, int k1, int k2) {
    long long N = 1e8;

    long long dp_0[1 + n1][1 + n2][1 + k1];
    long long dp_1[1 + n1][1 + n2][1 + k2];
    
    memset(dp_0, 0 , sizeof(dp_0));
    memset(dp_1, 0 , sizeof(dp_1));
    
    dp_0[1][0][1] = 1;
    dp_1[0][1][1] = 1;
    
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i > 0) {
                for (int k = 2; k <= k1; k++) {
                    if (k > i) {
                        break;
                    }
                    dp_0[i][j][k] += dp_0[i - 1][j][k - 1];
                    dp_0[i][j][k] %= N;
                }
                for (int k = 1; k <= k2; k++) {
                    if (k > j) {
                        break;
                    }
                    dp_0[i][j][1] += dp_1[i - 1][j][k];
                    dp_0[i][j][1] %= N;
                }
            }
            if (j > 0) {
                for (int k = 2; k <= k2; k++) {
                    if (k > j) {
                        break;
                    }
                    dp_1[i][j][k] += dp_1[i][j - 1][k - 1];
                    dp_1[i][j][k] %= N;
                }
                for (int k = 1; k <= k1; k++) {
                    if (k > i) {
                        break;
                    }
                    dp_1[i][j][1] += dp_0[i][j - 1][k];
                    dp_1[i][j][1] %= N;
                }
            }
            
        }
    }
    int res0 = 0, res1 = 0;
    for (int k = 1; k <= k1; k++) {
        res0 += dp_0[n1][n2][k];
        res0 %= N;
    }
    
    for (int k = 1; k <= k2; k++) {
        res1 += dp_1[n1][n2][k];
        res1 %= N;
    }
    //cout << dp_1[n1][n2][k1][k2] << "\n";
    //cout << dp_2[n1][n2][k1][k2] << "\n";
    //cout << dp_2[1][1][1][1] << "\n";
    
    return (res0 + res1) % N;
    
    //return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //int n1 = 2, n2 = 1, k1 = 1, k2 = 10;
    int n1, n2, k1, k2;
    //n1 = read(), n2 = read(), k1 = read(), k2 = read();
    //scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    cin >> n1 >> n2 >> k1 >> k2;
    //cout << n1 << " " << n2 << " " << k1 << " " << k2 << "\n";
    int res = solve(n1, n2, k1, k2);
    std::cout << res << "\n";
    return 0;
}

// AC. The solution is from
// https://www.luogu.com.cn/problem/solution/CF118D.
