#include <bits/stdc++.h>
using namespace std;

// Function to check if two line segments intersect and return the intersection point
pair<int, int> findIntersection(vector<int> wire1, vector<int> wire2) {
    int x1 = wire1[0], y1 = wire1[1], x2 = wire1[2], y2 = wire1[3];
    int x3 = wire2[0], y3 = wire2[1], x4 = wire2[2], y4 = wire2[3];

    if (x1 == x2 && y3 == y4) { // Vertical and horizontal
        if (min(x3, x4) <= x1 && x1 <= max(x3, x4) && min(y1, y2) <= y3 && y3 <= max(y1, y2)) {
            return {x1, y3};
        }
    } else if (x3 == x4 && y1 == y2) { // Horizontal and vertical
        if (min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y3, y4) <= y1 && y1 <= max(y3, y4)) {
            return {x3, y1};
        }
    }
    return {-1, -1}; // No intersection
}

// Function to calculate voltage generated at intersections
int calculateVoltage(const map<pair<int, int>, set<vector<int>>> &intersections) {
    int totalVoltage = 0;

    for (const auto &entry : intersections) {
        const set<vector<int>> &wiresAtPoint = entry.second;

        int numWires = wiresAtPoint.size();
        int minWireLength = INT_MAX;

        for (const auto &wire : wiresAtPoint) {
            int length = abs(wire[2] - wire[0]) + abs(wire[3] - wire[1]);
            minWireLength = min(minWireLength, length);
        }

        totalVoltage += numWires * minWireLength;
    }
    return totalVoltage;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> wires(n, vector<int>(4));

    for (int i = 0; i < n; ++i) {
        cin >> wires[i][0] >> wires[i][1] >> wires[i][2] >> wires[i][3];
    }

    string animalData;
    cin.ignore();
    getline(cin, animalData);

    map<string, int> animals;
    stringstream ss(animalData);
    string token;
    while (getline(ss, token, ' ')) {
        size_t pos = token.find(':');
        if (pos != string::npos) {
            string name = token.substr(0, pos);
            int resistance = stoi(token.substr(pos + 1));
            animals[name] = resistance;
        }
    }

    string animalTouch;
    getline(cin, animalTouch);

    // Find intersections
    map<pair<int, int>, set<vector<int>>> intersections;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pair<int, int> intersection = findIntersection(wires[i], wires[j]);
            if (intersection.first != -1) {
                intersections[intersection].insert(wires[i]);
                intersections[intersection].insert(wires[j]);
            }
        }
    }

    // Calculate total voltage
    int totalVoltage = calculateVoltage(intersections);

    // Check if the animal touching the fence dies
    if (totalVoltage > animals[animalTouch]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    // Calculate probability of animals dying
    int dyingAnimals = 0;
    for (const auto &entry : animals) {
        if (totalVoltage > entry.second) {
            ++dyingAnimals;
        }
    }

    double probability = (double)dyingAnimals / animals.size();
    cout << fixed << setprecision(2) << probability << endl;

    return 0;
}
