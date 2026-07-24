#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"
#include <iostream>
#include <vector>
#include "src/data-structure/binary-search.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> s(n);
    REP (i, n) {
        cin >> s[i];
    }
    int q; cin >> q;
    int cnt = 0;
    while (q --) {
        int t_i; cin >> t_i;
        int index = otukado::BinarySearch(-1, n, [&](int i) {
            return s[i] >= t_i;
        });
        cnt += index < n && s[index] == t_i;
    }
    cout << cnt << endl;
    return 0;
}
