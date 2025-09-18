#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> words;
vector<char> letters;
int coeff[26];
int assignVal[26];
bool used[10];
bool leading[26];
long long solutions = 0;

void dfs(int idx, long long sum) {
    if (idx == (int)letters.size()) {
        if (sum == 0) solutions++;
        return;
    }
    char c = letters[idx];
    int ci = c - 'A';
    for (int d = 0; d <= 9; d++) {
        if (used[d]) continue;
        if (d == 0 && leading[ci]) continue; // leading zero forbidden
        used[d] = true;
        dfs(idx + 1, sum + 1LL * coeff[ci] * d);
        used[d] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    // collect letters
    set<char> s;
    for (auto &w : words) for (char c : w) s.insert(c);
    letters.assign(s.begin(), s.end());

    if (letters.size() > 10) {
        cout << 0 << "\n";
        return 0;
    }

    // coeff array
    memset(coeff, 0, sizeof(coeff));
    memset(leading, 0, sizeof(leading));

    for (int i = 0; i < n-1; i++) {
        long long base = 1;
        for (int j = (int)words[i].size()-1; j >= 0; j--) {
            coeff[words[i][j] - 'A'] += base;
            base *= 10;
        }
        if (words[i].size() > 1) leading[words[i][0]-'A'] = true;
    }
    {
        long long base = 1;
        for (int j = (int)words[n-1].size()-1; j >= 0; j--) {
            coeff[words[n-1][j] - 'A'] -= base;
            base *= 10;
        }
        if (words[n-1].size() > 1) leading[words[n-1][0]-'A'] = true;
    }

    memset(used, 0, sizeof(used));
    dfs(0, 0);

    cout << solutions << "\n";
}
