//
//  main.cpp
//  325B_stadium_cpp
//
//  Created by ZheWang on 6/22/22.
//  Copyright © 2022 ZheWang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;
typedef long long LL;

long long solve(long long n, long long cur) {
    long long start = 1, end = 3*1e9;
    //end = n / cur + 1;
    
    if (cur >= ((long long)1<<30) - 1) {
        //end = (1000000000000000000 / cur);
        end = n / cur + 1;
    }
    //cout << "end = " << end << "\n";
    long long mid;
    long long flag = -1;
    while (start < end) {
        mid = (start + end) / 2;
        long long temp = 2 * cur * mid + mid * mid - mid;
        if (temp == 2 * n) {
            flag = mid;
            break;
        }
        else if (temp > 2 * n) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    if (flag != -1) {
        if (mid % 2 == 1) {
            return mid;
        }
        else {
            return -1;
        }
    }
    long long temp = 2 * cur * start + start * start - start;
    if (temp != 2 * n) {
        return -1;
    }
    if (start % 2 == 0) {
        return -1;
    }
    return start;
}


void find(long long n) {
    //cout << "n = " << n << "\n";
    int k = 0;
    long long cur;
    vector<long long> res = {};
    while (true) {
        /*
        if (k % 1 == 0) {
            cout << "k = " << k << "\n";
        }
        */
        if (k >= 60) {
            break;
        }
        cur = ((long long)1<<k) - 1;
        //cout << "cur = " << cur << "\n";
        if (cur > n) {
            break;
        }
        long long temp = solve(n, cur);
        if (temp != -1) {
            long long cur_res = (long long)temp * ((long long)1<<k);
            res.push_back(cur_res);
            //cout << "cur = " << cur << "\n";
            //cout << "temp = " << temp << "\n";
            //cout << "k = " << k << "\n";
            //cout << "cur_res = " << cur_res << "\n";
        }
        k++;
    }
    if (res.size() == 0) {
        cout << -1 << "\n";
    }
    std::sort(res.begin(), res.end());
    int kk = res.size();
    //cout << "res.size() = " << res.size() << "\n";
    for (int i = 0; i < kk; i++) {
        cout << res[i] << "\n";
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    long long n;
    cin >> n;
    //cout << "input finished" << "\n";
    //scanf("%I64d", &n);
    find(n);
    //int k = 59;
    //long long test = ((long long)1<<59);
    //long long test = (LL)2147483647 + 1;
    //cout << test << "\n";
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 30 ms, 8 kB. 
// The long long issue is so annoying!
