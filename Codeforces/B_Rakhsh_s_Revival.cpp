#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(int n, int m, int k, const string& s) {
    int numUses = 0;
    int i = 0;

    while (i < n) {
        if (s[i] == '0') {
            // We found the start of a weak segment of 0's
            int start = i;
            // Move i to the end of this segment
            while (i < n && s[i] == '0') {
                i++;
            }
            int len = i - start;

            // If the segment is long enough to be a problem
            if (len >= m) {
                // We need to use Timar to strengthen this segment
                // Each application of Timar covers 'k' positions
                // The number of applications needed to cover the segment
                numUses += (len - m) / k + 1;
            }
        } else {
            // Skip over strong spots
            i++;
        }
    }

    return numUses;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;

        // Process each test case
        cout << solve(n, m, k, s) << endl;
    }

    return 0;
}
