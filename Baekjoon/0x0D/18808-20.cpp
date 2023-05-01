#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int note[42][42];
int r, c, paper[12][12];

bool check(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(paper[i][j] == 1 && note[x+i][y+j] == 1) return false;
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(paper[i][j] == 1) {
                note[x+i][y+j] = 1;
            }
        }
    }
    return true;
}

void rotate() {
    int tmp[12][12];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            tmp[i][j] = paper[i][j];
        }
    }
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            paper[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r, c);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> paper[i][j];
            }
        }
        for(int rot = 0; rot < 4; rot++) {
            bool is_paste = false;
            for(int x = 0; x <= n-r; x++) {
                if(is_paste) break;
                for(int y = 0; y <= m-c; y++) {
                    if(check(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate();
        }

    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += note[i][j];
        }
    }
    cout << ans << '\n';
}