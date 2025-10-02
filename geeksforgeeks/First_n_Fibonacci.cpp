// User function template for C++

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        vector<int> vec(n,0);
        if(n==1)
            return vec;
        vec[1] = 1;

        for(int i=2; i<n;  i++){
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec;
    }
};
