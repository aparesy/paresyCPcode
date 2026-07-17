#include <iostream>

#ifdef DEBUG
 
#define var(x) cerr << #x << ": " << x << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
#define var(x)
#define range(a, b)
#define cerr if (false) cerr
#endif

using namespace std;
int n;

void solve_case() {
    int rounds;
    cin  >> rounds;
    rounds --;

    int a, b;
    cin >> a >> b;

    if (a > b) 
        swap(a, b);

    int delta = b - a;

    if (delta & 1) { // everything moves one spot, thus parity of delta can't change unless they wait in a corner
        int moves_to_left = a - 1;
        int moves_to_right = n - b;

        int moves_to_corner = min(moves_to_left, moves_to_right);
        rounds -= moves_to_corner + 1;
        b = delta;
        a = 1; // a will wait one turn in the corner, for the parities to match
        // it's irrelevant which corner they go to, as they will be in the same position after the same number of moves, 
        // this just reduces the problem to the case where delta is even
        delta = b - a;
    }

    int middle = (a + b) / 2;
    int moves_to_middle = middle - a; // also middle - b, but they are the same
    if (rounds < moves_to_middle) {
        cout << 0 << endl;
        return;
    }
    rounds -= moves_to_middle;
    // now they meet again every second move
    int meetings_after_meeting = rounds / 2;
    int total_meetings = 1 + meetings_after_meeting; // the first meeting
    cout << total_meetings << endl;
}

int main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    int test_cases;
    cin >> test_cases;
    while (cin>>n) {
        solve_case();
    }
}
