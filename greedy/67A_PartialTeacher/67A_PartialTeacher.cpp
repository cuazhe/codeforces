#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void cal(int n, string s) {
    vector<int> res(n, 0);
    //vector<vector<int>> temp;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '=') {
            if (i == 0) {
                //temp.push_back({0, 0});
                res[0] = 1;
                res[1] = 1;
            }
            else {
                res[i + 1] = res[i];
                //temp.push_back({0, 0});
            }
        }
        else if (s[i] == 'L') {
            if (i == 0) {
                //temp.push_back({1, 0});
                res[0] = 2;
                res[1] = 1;
            }
            else {
                if (res[i] > 1) {
                    res[i + 1] = 1;
                }
                else {
                    res[i + 1] = 1;
                    res[i] = 2;
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] == 'L') {
                            if (res[j] > res[j + 1]) {
                                break;
                            }
                            else {
                                res[j] = res[j + 1] + 1;
                            }
                        }
                        if (s[j] == '=') {
                            res[j] = res[j + 1];
                        }
                    }
                }
            }
        }
        else {
            if (res[i] == 0) {
                res[i] = 1;
            }
            res[i + 1] = res[i] + 1;
        }
    }
    //int ans = accumulate(res.begin(), res.end(), 0);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    string s;
    cin >> s;
    cal(n, s);
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 30 ms, 0 KB. The main part is to recognize that when looking back, we only increase the existed value.
