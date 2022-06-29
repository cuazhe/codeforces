#include <iostream>
#include <vector>
using namespace std;


void cal(int n, int a, int b, int k) {
    long long N = 1000000007;
    vector<long long> dp(1 + n, 0);
    dp[a] = 1;
    vector<long long> ps(1 + n, 0);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + dp[i];
    }
    int cur;
    long long prev;
    for (int i = 0; i < k; i++) {
        vector<long long> temp(1 + n, 0);
        vector<long long> ps_nxt(1 + n, 0);
        for (int j = 1; j <=n; j++) {
            if (j == b) {
                continue;
            }
            if (j < b) {
                if ((j + b) % 2 == 0) {
                    cur = (j + b) / 2 - 1;
                }
                else {
                    cur = (j + b) / 2;
                }
                prev = ps[cur] - ps[0];
                prev = prev + N - dp[j];
                //if (prev < 0) {
                //    cout << "found error!" << "\n";
                //}
                prev %= N;
                temp[j] += prev;
                temp[j] %= N;
            }
            else {
                cur = (j + b) / 2 + 1;
                prev = ps[n] - ps[cur - 1] + N;
                prev = prev + N - dp[j];
                prev %= N;
                temp[j] += prev;
                temp[j] %= N;
            }
        }
        for (int j = 1; j <= n; j++) {
            ps_nxt[j] = (ps_nxt[j - 1] + temp[j]) % N;
        }
        ps = ps_nxt;
        dp = temp;
        
        /*
        int res_aux = 0;
        for (int m = 1; m <= n; m++) {
            cout << "m = " << m << " ; temp[m] = " << temp[m] << "\n";
            res_aux += dp[m];
            res_aux %= N;
        }
        cout << "i = " << i << " ; " << res_aux << "\n";
        */
        
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += dp[i];
        res %= N;
    }
    cout << res << "\n";
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    cal(n, a, b, k);
    
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 655 ms, 200 KB.
