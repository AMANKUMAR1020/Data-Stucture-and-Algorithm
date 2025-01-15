#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> L(N), R(N), X(N);
    long long sumL = 0;  // This will store the sum of the initial choices of L_i
    
    // Read the input values for L and R
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
        X[i] = L[i];  // Start with X_i = L_i
        sumL += L[i]; // Calculate the sum of L_i values
    }
    
    long long delta = -sumL;  // The difference we need to adjust to make the sum 0
    
    // Try to adjust the values of X[i] from L[i] towards R[i] to balance the sum
    for (int i = 0; i < N; ++i) {
        long long maxAdjustment = R[i] - L[i];  // Maximum we can increase X[i] by
        if (delta > 0) {
            // We need to increase the sum to 0, so we increase X[i]
            long long increase = min(delta, maxAdjustment);
            X[i] += increase;
            delta -= increase;
        }
        if (delta == 0) break;  // If delta is 0, we don't need any more adjustments
    }
    
    if (delta != 0) {
        // If we couldn't adjust the sum to 0
        cout << "No\n";
    } else {
        // If the sum is 0, output the sequence
        cout << "Yes\n";
        for (int i = 0; i < N; ++i) {
            cout << X[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
