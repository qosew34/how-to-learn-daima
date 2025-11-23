/*
n为平方数，p是n的最小的质因数。有无n的正因数1,，d2，满足n/p-d1=d2-1
且这相等的差是p的倍数?若有，求出n。若没有，说明理由。
写了点小玩具*/



#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 smallest_prime_factor(int64 x) {
    if (x % 2 == 0) return 2;
    for (int64 d = 3; d * d <= x; d += 2) {
        if (x % d == 0) return d;
    }
    return x;
}

vector<int64> divisors(int64 n) {
    vector<int64> low, high;
    for (int64 i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            low.push_back(i);
            if (i * i != n) high.push_back(n / i);
        }
    }
    for (auto it = high.rbegin(); it != high.rend(); ++it) low.push_back(*it);
    return low;
}

int main(int argc, char** argv) {
    // Usage: ./search [maxN]
    // Default maxN = 1000000 (search square numbers n up to that)
    int64 maxN = 1000000;
    if (argc >= 2) {
        long long v = atoll(argv[1]);
        if (v > 0) maxN = v;
    }

    bool found_case_d1_is_1 = false;
    bool found_general = false;

    cout << "Searching square numbers n (n <= " << maxN << ") ..." << endl;

    for (int64 t = 1; t * t <= maxN; ++t) {
        int64 n = t * t;
        if (n <= 1) continue; // skip n = 1
        int64 p = smallest_prime_factor(n);
        int64 np_div_p = n / p;

        // Case A: assume d1 = 1
        // condition: diff = n/p - 1 is divisible by p AND diff != 0
        int64 diffA = np_div_p - 1;
        if (diffA != 0 && diffA % p == 0) {
            cout << "[FOUND - d1 = 1 case] n = " << n
                 << ", p = " << p
                 << ", d1 = 1, d2 = " << np_div_p
                 << ", diff = " << diffA
                 << " (divisible by " << p << ")" << endl;
            found_case_d1_is_1 = true;
        }

        // Case B: arbitrary positive divisors d1, d2 of n
        // condition:
        //   diff = n/p - d1 == d2 - 1
        //   diff % p == 0
        //   diff != 0
        vector<int64> divs = divisors(n);
        for (int i = 0; i < (int)divs.size(); ++i) {
            int64 d1 = divs[i];
            int64 diff = np_div_p - d1;
            if (diff == 0) continue;           // enforce diff != 0
            if (diff % p != 0) continue;       // must be multiple of p
            int64 needed = np_div_p + 1 - d1;  // candidate d2
            if (needed <= 0) continue;
            if (binary_search(divs.begin(), divs.end(), needed)) {
                int64 d2 = needed;
                cout << "[FOUND - arbitrary divisors] n = " << n
                     << ", p = " << p
                     << ", d1 = " << d1
                     << ", d2 = " << d2
                     << ", diff = " << diff
                     << " (divisible by " << p << ")" << endl;
                found_general = true;
                // keep searching to list all within range
            }
        }
    }

    if (!found_case_d1_is_1) {
        cout << "No solution found for the d1 = 1 case within the search range (with diff != 0)." << endl;
    }
    if (!found_general) {
        cout << "No solution found for arbitrary divisors within the search range (with diff != 0)." << endl;
    }

    cout << "Search finished." << endl;
    return 0;
}