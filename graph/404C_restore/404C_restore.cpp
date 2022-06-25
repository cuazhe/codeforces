#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void find(vector<int>& dist, int n, int k) {
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({dist[i], i + 1});
    }
    sort(arr.begin(), arr.end(), [] (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    
    /*
    for (int i = 0; i < n; i++) {
        cout << arr[i][0] << " ; " << arr[i][1] << "\n";
    }
    */
    
    
    //int cnt = 0;
    vector<vector<int>> res;
    vector<int> deg(n + 1, 0);
    
    int cur = 0, prev = -1, prev_dist = -1, flag;
    vector<int> prev_deg_nodes = {};
    int i = 0;
    vector<int> cur_deg_nodes= {};
    while (i < n) {
        if (i == 0) {
            if (arr[i][0] != 0) {
                cout << -1 << "\n";
                return;
            }
            prev_deg_nodes.push_back(arr[i][1]);
            cur++;
            prev = arr[i][1];
            prev_dist = 0;
            //deg[arr[i][1]]++;
            i++;
            continue;
        }
        if (arr[i][0] == prev_dist + 1) {
            //flag_nxt = 1;
            flag = 0;
            for (int j = 0; j < prev_deg_nodes.size(); j++) {
                if (deg[prev_deg_nodes[j]] < k) {
                    deg[prev_deg_nodes[j]]++;
                    deg[arr[i][1]]++;
                    cur_deg_nodes.push_back(arr[i][1]);
                    flag = 1;
                    res.push_back({prev_deg_nodes[j], arr[i][1]});
                    break;
                }
            }
            if (flag == 0) {
                cout << -1 << "\n";
                return;
            }
            i++;
        }
        else {
            if (arr[i][0] - arr[i - 1][0] != 1) {
                cout << -1 << "\n";
                return;
            }
            prev_dist++;
            prev_deg_nodes = cur_deg_nodes;
            cur_deg_nodes = {};
        }
    }
    cout << res.size() << "\n";
    for (auto& c: res) {
        cout << c[0] << " " << c[1] << "\n";
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k;
    cin >> n >> k;
    vector<int> dist(n, 0);
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        dist[i] = temp;
    }
    
    /*
    for (int i = 0; i < n; i++) {
        cout << dist[i] << "\n";
    }
    */
    find(dist, n, k);
    
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 186 ms, 9200 KB.
// The idea is straightforward, we only need to implement the idea.
