#include <iostream>
#include <vector>
using namespace std;

vector<int> par(26, 0);
vector<int> lookup(26, 0);

int find(int i) {
    if (par[i] == i) {
        return par[i];
    }
    par[i] = find(par[i]);
    return par[i];
}

void unite(int i , int j) {
    int par_i = find(i);
    int par_j = find(j);
    if (par_i == par_j) {
        return;
    }
    par[par_i] = par_j;
    return;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    par = vector<int> (26, 0);
    for (int i = 0; i < 26; i++) {
        par[i] = i;
        lookup[i] = i;
    }
    int cur = 0;
    string res = "";
    char cur_max = 'a';
    for (int i = 0; i < n; i++) {
        if (s[i] <= cur_max) {
            int p = find(s[i] - 'a');
            res += ('a' + lookup[p]);
        }
        else {
            char temp = s[i];
            if (cur >= k) {
                res += s[i];
                continue;
            }
            while (cur < k && temp > cur_max) {
                unite(temp - 'a', temp - 'a' - 1);
                temp -= 1;
                cur++;
            }
            if (cur < k) {
                res += 'a';
            }
            else {
                int prev = find(temp - 'a');
                res += ('a' + lookup[prev]);
            }
            cur_max = s[i];
        }
    }
    cout << res << endl;
}



int main() {
    // insert code here...
    //string s = "abc";
    //string res = s + 'd';
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    //char s = 'd';
    //char res = s - 1;
    //std::cout << res << "\n";
    return 0;
}

// AC. The key part is the greedy algorithm here. 
