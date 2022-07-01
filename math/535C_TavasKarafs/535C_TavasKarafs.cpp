#include <iostream>
#include <vector>
using namespace std;

int A, B, n;

void cal(long long ell, long long m, long long t) {
    long long cur = (t - A) / B + 1;
    if (cur < ell) {
        cout << -1 << "\n";
        return;
    }
    if (A + (ell - 1) * B > t) {
        cout << - 1 << "\n";
        return;
    }
    long long start = ell, end = cur;
    long long temp, to_eat;
    while (start < end) {
        //cout << "start = " << start << " ; end = " << end << "\n";
        long long mid = (start + end) / 2;
        //cout << "mid = " << mid << "\n";
        to_eat = (A + (ell - 1) * B + (A + (mid - 1) * B)) * (mid - ell + 1) / 2;
        if (mid - ell + 1 < m) {
            temp = (mid - ell + 1) * t;
        }
        else {
            temp = m * t;
        }
        if (to_eat <= temp) {
            //cout << "to_eat = " << to_eat << " ; temp = " << temp << "\n";
            start = mid + 1;
        }
        else {
            //cout << "to_eat = " << to_eat << " ; temp = " << temp << "\n";
            end = mid - 1;
        }
    }
    //cout << "start = " << start << " ; end = " << end << "\n";
    to_eat = (A + (ell - 1) * B + (A + (start - 1) * B)) * (start - ell + 1) / 2;
    if (start - ell + 1 < m) {
        temp = (start - ell + 1) * t;
    }
    else {
        temp = m * t;
    }
    if (to_eat <= temp) {
        cout << start << "\n";
    }
    else {
        cout << start - 1 << "\n";
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //int A, B, n;
    cin >> A >> B >> n;
    long long ell, m, t;
    for (int i = 0; i < n; i++) {
        cin >> ell >> t >> m;
        cal(ell, m, t);
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

// AC. 701 ms, 0 KB.
