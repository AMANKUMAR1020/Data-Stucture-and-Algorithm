bool checkIfExist(int* arr, int arrSize) {
    int  n = arrSize;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<2*n; j++)
            if(arr[i] == 2*arr[j%n] && i != j%n){
                printf("%d %d",arr[i],2*arr[j%n]);
                return true;
            }

    return false;
}
