#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void dfs(int i, vector<int>& par, vector<int>& visited, unordered_map<int, vector<int>> &graph) {
    visited[i] = 1;
    if (graph[i].size() == 0) {
        return;
    }
    for (auto c: graph[i]) {
        if (visited[c] == 1) {
            continue;
        }
        par[c] = i;
        dfs(c, par, visited, graph);
    }
    return;
}

vector<int> solve(int n, int r1, int r2, vector<int> &arr) {
    unordered_map<int, vector<int>> graph;
    for (int i = 1; i <= n; i++) {
        if (i == r1) {
            continue;
        }
        graph[i].push_back(arr[i]);
        graph[arr[i]].push_back(i);
    }
    vector<int> res(n + 1, 0);
    vector<int> visited(n + 1, 0);
    dfs(r2, res, visited, graph);
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    vector<int> arr(n + 1, 0);
    int cur;
    for (int i = 1; i <= n; i++) {
        if (i == r1) {
            continue;
        }
        cin >> cur;
        arr[i] = cur;
    }
    
    //cout << "r1 = " << r1 << "\n";
    
    /*
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    */
    
    vector<int> res = solve(n, r1, r2, arr);
    for (int i = 1; i <= n; i++) {
        if (i != r2) {
            cout << res[i] << " ";
        }
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 1013 ms, dfs. 
