#include <iostream>
#include <vector>
using namespace std;

void cal(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> lcp(m + 2, vector<int>(n + 2, 0));
    for (int i = m; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }
    
    vector<vector<int>> rlcp(m + 2, vector<int> (n + 2, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                rlcp[i][j] = rlcp[i - 1][j + 1] + 1;
            }
        }
    }
    /*
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << lcp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    int idx = 1, nxt_idx = -1, cnt = 0;
    vector<vector<int>> pos_dire;
    while (idx <= n) {
        int cur_max = 0;
        int cur_from = -1, cur_to = -1;
        for (int i = 1; i <= m; i++) {
            if (lcp[i][idx] > cur_max) {
                cur_max = lcp[i][idx];
                cur_from = i;
                cur_to = i + lcp[i][idx] - 1;
                nxt_idx = idx + lcp[i][idx] - 1;
            }
        }
        
        for (int i = m; i >= 1; i--) {
            if (rlcp[i][idx] > cur_max) {
                cur_max = rlcp[i][idx];
                cur_from = i;
                cur_to = i - rlcp[i][idx] + 1;
                nxt_idx = idx + rlcp[i][idx] - 1;
            }
        }
        if (cur_max == 0) {
            cout << -1 << "\n";
            return;
        }
        cnt++;
        pos_dire.push_back({cur_from, cur_to});
        idx = nxt_idx + 1;
    }
    cout << cnt << "\n";
    for (auto c: pos_dire) {
        cout << c[0] << " " << c[1] << "\n";
    }
    return;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string s, t;
    cin >> s;
    cin >> t;
    cal(s, t);
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 77 ms, 36400 KB.
