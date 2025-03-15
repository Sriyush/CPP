#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input number of vertices
    int N;
    cin >> N;

    // Input wall vertices
    vector<pair<int, int>> vertices(N);
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;

    for (int i = 0; i < N; ++i) {
        cin >> vertices[i].first >> vertices[i].second;
        minX = min(minX, vertices[i].first);
        minY = min(minY, vertices[i].second);
        maxX = max(maxX, vertices[i].first);
        maxY = max(maxY, vertices[i].second);
    }

    // Input brush size
    int M;
    cin >> M;

    // Calculate the dimensions of the bounding box
    int width = maxX - minX;
    int height = maxY - minY;

    // Calculate the number of presses required
    int pressesWidth = (width + M - 1) / M; // Ceiling of width / M
    int pressesHeight = (height + M - 1) / M; // Ceiling of height / M

    int totalPresses = pressesWidth * pressesHeight;

    // Output the result
    cout << totalPresses << endl;

    return 0;
}
