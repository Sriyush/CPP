#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int w, vector<int> weight, vector<int> value, int n, vector<vector<int>> &dp) {
    if (ind == n - 1) {
        if (weight[n - 1] <= w) {
            return value[ind];
        }
        return 0;
    }
    if (dp[ind][w] != -1) {
        return dp[ind][w];
    }
    int nottake = solve(ind + 1, w, weight, value, n, dp);
    int take = INT_MIN;
    if (weight[ind] <= w) {
        take = value[ind] + solve(ind + 1, w - weight[ind], weight, value, n, dp);
    }
    return dp[ind][w] = max(take, nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(0, maxWeight, weight, value, n, dp);
}

int main() {
    int n, maxWeight;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> weight(n), value(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cout << "Enter maximum weight capacity: ";
    cin >> maxWeight;
    
    int maxValue = knapsack(weight, value, n, maxWeight);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
