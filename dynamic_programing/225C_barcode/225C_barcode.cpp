#include <iostream>
#include <vector>
using namespace std;


int cal(int m, int n, int x, int y, vector<vector<char>>& mat) {
    vector<int> col_dot(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                col_dot[j]++;
            }
        }
    }
    
    vector<int> ps_coldot(m + 1, 0);
    for (int j = 0; j < m; j++) {
        ps_coldot[j + 1] = ps_coldot[j] + col_dot[j];
    }
    
    /*
    for (int j = 0; j <= m; j++) {
        cout << ps_coldot[j] << "\n";
    }
    */
    
    vector<vector<long long>> dp(m + 1, vector<long long>(2, INT_MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for (int j = 0; j <= m; j++) {
        for (int k = x; k <= y; k++) {
            if (j + k > m) {
                break;
            }
            dp[j + k][0] = min(dp[j + k][0], dp[j][1] + (k * n - (ps_coldot[j + k] - ps_coldot[j])));
            dp[j + k][1] = min(dp[j + k][1], dp[j][0] + (ps_coldot[j + k] - ps_coldot[j]));
        }
    }
    return min(dp[m][0], dp[m][1]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        for (int j = 0; j < m; j++) {
            mat[i][j] = cur[j];
        }
    }
    int res = cal(m, n, x, y, mat);
    cout << res << "\n";
    //std::cout << "Hello, World!\n";
    return 0;
}
