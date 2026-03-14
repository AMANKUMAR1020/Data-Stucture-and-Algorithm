
class Solution {
  public:
    void zigZag(vector<int> &arr) {
        int n = arr.size();
        int i = 1;
        
        while(i < n){
            if(i%2==1){
                if(arr[i-1] > arr[i])swap(arr[i-1], arr[i]);
                if(i+1 < n && arr[i+1] > arr[i])swap(arr[i+1], arr[i]);
                // if(i+1 < n && arr[i+1] > arr[i-1])swap(arr[i+1], arr[i-1]);
            }else{
                if(arr[i-1] < arr[i])swap(arr[i-1], arr[i]);
                if(i+1 < n && arr[i+1] > arr[i])swap(arr[i+1], arr[i]);
                // if(i+1 < n && arr[i-1] > arr[i+1])swap(arr[i-1], arr[i+1]);
            }
            i++;
        }
        
        // i = 1;
        // while(i < n){
        //     if(i%2==1){
        //         if(arr[i-1] > arr[i]) return false;
        //         if(i+1 < n && arr[i] < arr[i+1]) return false;
        //     }else{
        //         if(arr[i-1] < arr[i]) return false;
        //         if(i+1 < n && arr[i] > arr[i+1]) return false;
        //     }
        //     i++;
        // }
        //return true;
    }
};


// 4, 3, 7, 8, 6, 2, 1
// 3, 7, 4, 8, 2, 6, 1