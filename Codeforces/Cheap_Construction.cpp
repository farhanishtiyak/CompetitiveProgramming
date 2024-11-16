#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    
    // Initialize result with "infinity"
    vector<int> result(N + 1, INT_MAX);
    
    // Using a map to store positions of each substring
    unordered_map<string, vector<int>> substring_positions;

    // Generate all substrings and store their positions
    for (int start = 0; start < N; ++start) {
        for (int length = 1; length <= N - start; ++length) {
            string substring = S.substr(start, length);
            substring_positions[substring].push_back(start + 1); // Store 1-based index
        }
    }

    // Iterate over each unique substring
    for (const auto& entry : substring_positions) {
        const string& substring = entry.first;
        const vector<int>& positions = entry.second;

        // Count how many times this substring can connect components
        int count = positions.size();
        int length = substring.length();

        // Update the result for the number of components
        if (count <= N) {
            result[count] = min(result[count], length);
        }
    }

    // Output results for each k from 1 to N
    for (int k = 1; k <= N; ++k) {
        cout << (result[k] == INT_MAX ? 0 : result[k]) << " ";
    }
    cout << endl;

    return 0;
}
