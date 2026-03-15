#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    queue<string> q;
    q.push("");

    while (!q.empty()) {
        string s = q.front(); 
        q.pop();

        if ((int)s.size() == n - 1) {
            long long pretotal = 0;
            string prenum = "1";

            // s 的长度是 n-1，只能遍历到 n-2
            for (int i = 0; i < (int)s.size(); i++) {
                int nextNum = i + 2; 

                if (s[i] == 'e') {
                    prenum += to_string(nextNum);         
                } 
                else if (s[i] == '+') {
                    pretotal += stoll(prenum);
                    prenum = to_string(nextNum);
                } 
                else if (s[i] == '-') {
                    pretotal += stoll(prenum);
                    prenum = "-" + to_string(nextNum);      
                }
            }

            pretotal += stoll(prenum);

            if (pretotal == 0) {
                cout << 1;
                for (int i = 0; i < (int)s.size(); i++) {
                    if (s[i] == '+') cout << '+';
                    else if (s[i] == '-') cout << '-';
                    else cout << ' ';
                    cout << i + 2;
                }
                cout << "\n";
            }
            continue;
        }

q.push(s + "e");
q.push(s + '+'); 
q.push(s + '-'); 
    }
}