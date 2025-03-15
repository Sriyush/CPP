#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        bool possible = false;
        
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                string numStr = to_string(i);
                bool valid = true;
                
                for (char c : numStr) {
                    if (c != '0' && c != '1') {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    int otherFactor = n / i;
                    numStr = to_string(otherFactor);
                    
                    for (char c : numStr) {
                        if (c != '0' && c != '1') {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (valid) {
                        possible = true;
                        break;
                    }
                }
            }
        }
        
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
