// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefProduct(n), suffProduct(n), res(n);
    
        // Construct the prefProduct array
        prefProduct[0] = 1;
        for (int i = 1; i < n; i++)
            prefProduct[i] = arr[i - 1] * prefProduct[i - 1];

        for(int a : prefProduct)
            cout<<a<<" ";
            cout<<endl;

        // Construct the suffProduct array
        suffProduct[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--)
            suffProduct[j] = arr[j + 1] * suffProduct[j + 1];
        for(int a : suffProduct)
            cout<<a<<" ";
            cout<<endl;
    
        // Construct the result array using
        // prefProduct[] and suffProduct[]
        for (int i = 0; i < n; i++)
            res[i] = prefProduct[i] * suffProduct[i];
    	
        return res;
    }
};
