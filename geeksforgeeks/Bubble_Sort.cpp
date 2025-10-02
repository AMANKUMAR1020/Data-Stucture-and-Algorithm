class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        //merge sort
        int i = 0;
        int n = arr.size() - 1;
//        divid(arr,0, n);
        quickSort(arr,0,n);
    }
private:
    void divid(vector<int>& arr, int start, int end){
        if(start >= end)
            return;
        int mid = (start + end)/2;
        divid(arr,start,mid);
        divid(arr,mid+1,end);
        merge(arr, start, mid, end);
    }
    void merge(vector<int>& arr, int l, int mid, int r){
        vector<int> temp;
        int i=l, j = mid + 1;
        
        while(i <= mid && j <= r){
            if(arr[i] < arr[j])  
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i <= mid){
            temp.push_back(arr[i++]);
        }
        while(j <= r){
            temp.push_back(arr[j++]);
        }
        for(int i=l,j=0; i<=r; i++,j++)
            arr[i] = temp[j];
    }
    void quickSort(vector<int>& arr, int low, int high){
        if(low < high){
            int p = partition(arr,low,high);
            quickSort(arr,low,p);
            quickSort(arr,p+1,high);
        }
    }
    int partition(vector<int>& arr, int low, int high){
        int i = low;
        int j = high;
        int p = arr[low];
        
        while(i < j){
            while(arr[i] <= p && i <= high-1){i++;}
            while(arr[j] >= p && j >= low+1){j--;}
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
 };





/*

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j-1] > arr[j]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = arr[j-1];
                }
            }
        }
    }
};

class Solution {
    public void bubbleSort(int[] arr) {
        // bubble sort
        int n=arr.length;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n-1-i;j++){
        //         if(arr[j]>arr[j+1]){
        //             int temp=arr[j];
        //             arr[j]=arr[j+1];
        //             arr[j+1]=temp;
        //         }   
        //     }
        // }
        
        // selection sort
        // for(int i=0;i<n;i++){
        //     int ind = i;
        //     for(int j=i+1;j<n;j++){
        //         if(arr[ind] > arr[j]){
        //             ind = j;
        //         }
        //     }
        //     int temp = arr[i];
        //     arr[i] = arr[ind];
        //     arr[ind] = temp;
        // }

        // insertion sort
        // for(int i=1; i<n; i++){
        //     int temp = arr[i];
        //     int ind = i - 1;
        //     while(ind >= 0  && arr[ind] > temp){
        //         arr[ind+1] = arr[ind];
        //         ind--;
        //     }
        //     arr[ind+1] = temp;
        // }
        
        
        //merge sort
        arr = divid(arr,0, arr.size()-1);
    }
private:
    void divid(vector<int>& arr, int start, int end){
        if(start >= end)
            return;
        int mid = (start + end)/2;
        divid(arr,start,mid);
        divid(arr,mid+1,end);
        merge(arr, start, mid, end);
    }
    
    vector<int> merge(vector<int>& arr, int l, int mid, int r){
        vector<int> temp;
        int i=l, j = mid + 1;
        
        while(i <= mid && j <= r){
            if(arr[i] < arr[j])  
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i <= mid){
            temp.push_back(arr[i++]);
        }
        while(j <= r){
            temp.push_back(arr[j++]);
        }

        return temp;
    }
    
}


*/
