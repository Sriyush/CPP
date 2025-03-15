#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i <= n; i++) {
        int ind = abs(nums[i]);
        if (nums[ind] < 0) {
            cout << ind; 
            return 0;
        }
        nums[ind] = -nums[ind];
    }

    return 0;
}