#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

unordered_map<int, vector<int>> graph;
map<tuple<int, int>, bool> visited;
map<tuple<int, int, int>, bool> forbid;
struct node {
    int cur, prev, dist, from_idx, cur_idx;
};
const int ms = 20123 * 2;
node lookup[ms];
int idx = 0;
int n, m, k;

void output(int i) {
    if (lookup[i].from_idx != -1) {
        output(lookup[i].from_idx);
    }
    cout << lookup[i].cur << " ";
}

void bfs() {
    node cur_node;
    queue<node> stk;
    lookup[0] = (node){1, -1, 0, -1, 0};
    idx++;
    for (auto c: graph[1]) {
//        node temp;
//        temp.cur = c;
//        temp.prev = 1;
//        temp.dist = 1;
//        temp.from_idx = 0;
//        temp.cur_idx = idx;
        node temp = {c, 1, 1, 0, idx};
        lookup[idx] = temp;
        stk.push(temp);
        idx++;
    }
    
    while (stk.size() > 0) {
        node cur_node = stk.front();
        stk.pop();
        if (cur_node.cur == n) {
            cout << cur_node.dist << "\n";
            output(cur_node.cur_idx);
            cout << "\n";
            return;
        }
        for (auto c: graph[cur_node.cur]) {
            tuple<int, int, int> ss = make_tuple(cur_node.prev, cur_node.cur, c);
            if (forbid[ss] == true) {
                continue;
            }
            if (visited[make_tuple(cur_node.cur, c)] == true) {
                continue;
            }
//            node nxt;
//            nxt.cur = c;
//            nxt.prev = cur_node.cur;
//            nxt.dist = cur_node.dist + 1;
//            nxt.from_idx = cur_node.cur_idx;
//            nxt.cur_idx = idx;
            node nxt = {c, cur_node.cur, cur_node.dist + 1, cur_node.cur_idx, idx};
            lookup[idx] = nxt;
            idx++;
            stk.push(nxt);
            visited[make_tuple(cur_node.cur, c)] = true;
        }
     }
    cout << -1 << "\n";
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cin >> n >> m >> k;
    int from, to, fb1, fb2, fb3;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for (int i = 0; i < k; i++) {
        cin >> fb1 >> fb2 >> fb3;
        forbid[make_tuple(fb1, fb2, fb3)] = true;
    }
    bfs();
    //tuple<int, int> temp = make_tuple(1, 2);
    //visited[temp] = false;
    //cout << visited[temp] << "\n";
    
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 2994 ms, 153900 KB. Slightly runs within the time limit.
