#include <iostream>
#include <set>

using namespace std;

int main() {
    long long N, k, l;
    cin >> N >> k >> l;

    // Set to track the edges
    set<long long> x_coords;
    set<long long> y_coords;

    // Add edges for all squares
    for (long long i = 1; i <= N; ++i) {
        long long left = i * k - l;
        long long right = i * k + l;
        long long bottom = i * k - l;
        long long top = i * k + l;

        // For horizontal lines
        y_coords.insert(bottom);
        y_coords.insert(top);

        // For vertical lines
        x_coords.insert(left);
        x_coords.insert(right);
    }

    // Calculate the area using the unique x and y coordinates
    long long total_area = 0;

    // Calculate width from unique x coordinates
    auto x_it = x_coords.begin();
    long long prev_x = *x_it;
    ++x_it;

    for (; x_it != x_coords.end(); ++x_it) {
        total_area += (*x_it - prev_x) * (y_coords.size() - 1); // height remains constant
        prev_x = *x_it;
    }

    // Calculate height from unique y coordinates
    auto y_it = y_coords.begin();
    long long prev_y = *y_it;
    ++y_it;

    for (; y_it != y_coords.end(); ++y_it) {
        total_area += (x_coords.size() - 1) * (*y_it - prev_y); // width remains constant
        prev_y = *y_it;
    }

    cout << total_area << endl;

    return 0;
}
