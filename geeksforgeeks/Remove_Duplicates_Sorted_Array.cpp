class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        if(n==1)
            return arr;
        int start=0,end=1;

        unordered_set<int> seen;

        for (int i = 0; i < n; ++i) {
            if (seen.count(arr[i])) {
                arr[i] = -1;
            } else {
                seen.insert(arr[i]);
            }
        }
        
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] != -1) {
                arr[index++] = arr[i];
            }
        }
        arr.resize(index);

        return arr;
    }
};
/*
class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        if(n==1)
            return arr;
        int start=0,end=1;

        unordered_set<int> seen;

        for (int i = 0; i < n; ++i) {
            if (seen.count(arr[i])) {
                arr[i] = -1;
            } else {
                seen.insert(arr[i]);
            }
        }
        
        while( start < n && arr[start] != -1){start++;}
        end = start;

        while(end < n){
            while(end < n && arr[end] == -1){
                end++;
            }
            arr[start] = arr[end];
            arr[end] = -1;
            
            while(start < n && arr[start] != -1){
                start++;
            }
        }
        while(start < end){
            arr.pop_back();
            end--;
        }
        return arr;
    }
};


*/
