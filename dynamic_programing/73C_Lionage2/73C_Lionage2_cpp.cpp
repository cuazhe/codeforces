#include <iostream>
#include <vector>
#include <map>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve(string s, int k, map<int, int>& lookup) {
    int m = s.size();
    if (m == 1) {
        cout << 0 << "\n";
        return;
    }
    //cout << "m = " << m << "\n";
    int cur = 0;
    if (k == 0) {
        for (int i = 1; i < m; i++) {
            cur += lookup[26 * (s[i - 1] - 'a') + (s[i] - 'a')];
        }
        cout << cur << "\n";
        return;
    }
    int dp[m][k + 1][26];
    memset(dp, -INF, sizeof(dp));
    int temp;
    int res = -INF;
    for (int i = 0; i < m; i++) {
        //cout << "i = " << i << "\n";
        if (i == 0) {
            for (int p = 0; p < 26; p++) {
                if ('a' + p == s[i]) {
                    dp[i][0][p] = 0;
                }
                else {
                    dp[i][1][p] = 0;
                }
            }
        }
        else {
            for (int j = 0; j <= min(i + 1, k); j++) {
                if (j == 0) {
                    temp = 26 * (s[i - 1] - 'a') + (s[i] - 'a');
                    if (dp[i - 1][j][s[i - 1] - 'a'] > -INF) {
                        dp[i][j][s[i] - 'a'] = dp[i - 1][j][s[i - 1] - 'a'] + lookup[temp];
                    }
                    //res = max(res, dp[i][j][s[i] - 'a']);
                }
                else {
                    for (int q = 0; q < 26; q++) {
                        if ('a' + q == s[i]) {
                            if (j > i) {
                                continue;
                            }
                            for (int p = 0; p < 26; p++) {
                                temp = 26 * p + q;
                                if (dp[i - 1][j][p] > -INF) {
                                    dp[i][j][q] = max(dp[i][j][q], dp[i - 1][j][p] + lookup[temp]);
//                                    if (dp[i][j][q] == 37) {
//                                        cout << "p = " << p << " ; q = " << q << " ; j = " << j << "\n";
//                                    }
                                    //res = max(res, dp[i][j][q]);
                                }
                            }
                        }
                        else {
                            if (j - 1 > i) {
                                continue;
                            }
                            for (int p = 0; p < 26; p++) {
                                temp = 26 * p + q;
                                //cout << "i - 1 = " << i - 1 << " ; j - 1 = " << j - 1 << "\n";
                                if (dp[i - 1][j - 1][p] > -INF) {
                                    dp[i][j][q] = max(dp[i][j][q], dp[i - 1][j - 1][p] + lookup[temp]);
//                                    if (dp[i][j][q] == 37) {
//                                        cout << "i = " << i << " ; j = " << j << "\n";
//                                        cout << "p = " << p << " ; q = " << q << "\n";
//                                    }
                                    //res = max(res, dp[i][j][q]);
                                }
                            }
                        }
                    }
                }
            }
        }
        //cout << res << "\n";
        
        for (int j = 0; j <= k; j++) {
            for (int q = 0; q < 26; q++) {
                res = max(res, dp[m - 1][j][q]);
            }
        }
//        for (int j = 0; j <= k; j++) {
//            for (int p = 0; p < 26; p++) {
//                cout << dp[i][j][p] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        
        
    }
    cout << res << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    int k;
    cin >> s >> k;
    int n;
    cin >> n;
    char c1, c2;
    int score;
    map<int, int> lookup;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2 >> score;
        lookup[26 * (c1 - 'a') + (c2 - 'a')] = score;
    }
    //lookup[2] = 1;
    
    /*
    for (auto c: lookup) {
        cout << c.first << " " << c.second << "\n";
    }
    */
    
    
    solve(s, k, lookup);
    //std::cout << lookup[10] << "\n";
    //cout << -INT_MAX << "\n";
    return 0;
}

// AC. 312 ms.
