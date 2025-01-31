#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    
    vector<vector<vector<int>>> A(n, vector<vector<int>>(n, vector<int>(n)));
    vector<vector<vector<int>>> prefixSum(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

    // Input the 3D array A and construct the prefix sum array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> A[i][j][k];
                // Fill the prefix sum array
                prefixSum[i + 1][j + 1][k + 1] = A[i][j][k]
                    + prefixSum[i][j + 1][k + 1]
                    + prefixSum[i + 1][j][k + 1]
                    + prefixSum[i + 1][j + 1][k]
                    - prefixSum[i][j][k + 1]
                    - prefixSum[i][j + 1][k]
                    - prefixSum[i + 1][j][k]
                    + prefixSum[i][j][k];
            }
        }
    }

    int q;
    cin >> q;
    
    // Process each query
    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        
        // Using the inclusion-exclusion principle to compute the sum of the range
        int result = prefixSum[x2][y2][z2]
                   - (x1 > 1 ? prefixSum[x1 - 1][y2][z2] : 0)
                   - (y1 > 1 ? prefixSum[x2][y1 - 1][z2] : 0)
                   - (z1 > 1 ? prefixSum[x2][y2][z1 - 1] : 0)
                   + (x1 > 1 && y1 > 1 ? prefixSum[x1 - 1][y1 - 1][z2] : 0)
                   + (x1 > 1 && z1 > 1 ? prefixSum[x1 - 1][y2][z1 - 1] : 0)
                   + (y1 > 1 && z1 > 1 ? prefixSum[x2][y1 - 1][z1 - 1] : 0)
                   - (x1 > 1 && y1 > 1 && z1 > 1 ? prefixSum[x1 - 1][y1 - 1][z1 - 1] : 0);
        
        cout << result << endl;
    }
}

int main() {
    solve();
    return 0;
}






/*

To optimize this code to O(log n) for range sum queries over a 3D array, we need to use a 3D prefix sum array. The goal is to preprocess the array so that each query can be answered in logarithmic time.

Here’s how to improve your current solution:

Step 1: Construct the 3D Prefix Sum Array
A 3D prefix sum array helps us calculate the sum of any sub-cuboid in constant time (O(1)) after an initial preprocessing step. For any given query, we can use the inclusion-exclusion principle to efficiently compute the sum of the elements in the desired sub-cuboid.

Let P[i][j][k] be the sum of elements in the cuboid from (1,1,1) to (i,j,k) in the original 3D array.

The relationship for computing the prefix sum is:

css
Copy
P[i][j][k] = A[i][j][k] + P[i-1][j][k] + P[i][j-1][k] + P[i][j][k-1]
             - P[i-1][j-1][k] - P[i-1][j][k-1] - P[i][j-1][k-1]
             + P[i-1][j-1][k-1]
Step 2: Querying using the Prefix Sum Array
Once the prefix sum array is built, for any query that asks for the sum within the range x1, x2, y1, y2, z1, z2, we can use the following inclusion-exclusion principle to compute the sum in O(1) time:

css
Copy
sum(x1, x2, y1, y2, z1, z2) = P[x2][y2][z2]
                                - P[x1-1][y2][z2]
                                - P[x2][y1-1][z2]
                                - P[x2][y2][z1-1]
                                + P[x1-1][y1-1][z2]
                                + P[x1-1][y2][z1-1]
                                + P[x2][y1-1][z1-1]

Key Points:
Prefix Sum Array: We build a 3D prefix sum array (prefixSum), which allows for O(1) query time after an O(n^3) preprocessing time.
Efficient Querying: For each query, we compute the sum using the inclusion-exclusion formula in constant time.
Memory: We use O(n^3) space for storing both the input and the prefix sum array.
Time Complexity:
Preprocessing: The 3D prefix sum array is built in O(n^3) time.
Query Time: Each query can be answered in O(1) time, thanks to the prefix sum array.
This approach dramatically improves the time for multiple queries once the preprocessing is done, although the preprocessing itself still takes O(n^3) time. Unfortunately, achieving a logarithmic time complexity for range queries directly on the 3D array is not possible without a more complex data structure (like segment trees or Fenwick trees) and would involve additional trade-offs in terms of complexity.

*/



