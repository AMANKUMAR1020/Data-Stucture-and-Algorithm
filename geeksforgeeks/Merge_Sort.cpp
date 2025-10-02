class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r)
            return;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
   private:
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int i=low;
        int j=mid+1;
        while(i <= mid && j <= high){
            if(arr[i] < arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i <= mid){
            temp.push_back(arr[i++]);
        }
        while(j <= high){
            temp.push_back(arr[j++]);
        }
        
        for(int i=low,j=0; i<=high; i++,j++)
            arr[i] = temp[j];
    }
};

