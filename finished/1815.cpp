#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        deque<pair<int,int>> worm; // front = head, back = tail
        string s;
        s.reserve(n);

        for (int i = 0; i < n; i++) {
            char temp; cin >> temp;
            s += temp;
        }

        for (int y = 30; y >= 11; y--) {
            worm.push_back({25, y});
        }

        int cir = -1, step = -1;

        for (int i = 0; i < (int)s.size(); i++) {
            auto [nx, ny] = worm.front(); // 取头

            if (s[i] == 'E') ny++;
            else if (s[i] == 'W') ny--;
            else if (s[i] == 'S') nx++;
            else if (s[i] == 'N') nx--;

            // 先让尾巴移动（题目允许头进入“刚刚空出来的尾格”）
            worm.pop_back();

            // 出界（棋盘是 1..50）
            if (nx < 1 || nx > 50 || ny < 1 || ny > 50) {
                cir = 1;
                step = i + 1;
                break;
            }

            // 撞到自己
            for (auto [a, b] : worm) {
                if (a == nx && b == ny) {
                    cir = 0;
                    step = i + 1;
                    break;
                }
            }
            if (cir != -1) break;

            // 新头入队
            worm.push_front({nx, ny});
        }

        if (cir == 0) cout << "The worm ran into itself on move " << step << ".\n";
        else if (cir == 1) cout << "The worm ran off the board on move " << step << ".\n";
        else cout << "The worm successfully made all " << s.size() << " moves.\n";
    }
    return 0;
}