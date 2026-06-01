//By Author Aman Kumar
ll* SumOfTwoArray(ll arr1[], ll arr2[], ll arr1Len, ll arr2Len){
    ll maxLen = arr1Len > arr2Len? arr1Len : arr2Len;
    ll* res = new ll[maxLen];
    ll i=0,j=0,k=0;

    while(i<arr1Len && j<arr2Len){
        res[k++] = arr1[i++] + arr2[j++];
        // cout<<" "<<res[k-1]<<endl;
    }
    
    while(j<arr2Len){
        res[k++] = arr2[j++];
        //cout<<" "<<res[k-1]<<endl;
    }

    while(i<arr1Len){
        res[k++] = arr1[i++];
        //cout<<" "<<res[k-1]<<endl;
    }

    return res;
}


int main(){
	text();
	ll n,i=0; cin>>n;

    ll arr1[n] = {0};
    while(i < n){
        cin>>arr1[i++];
    }

    i=0;
    ll m;     cin>>m;
    ll arr2[m] = {0};
    while(i < m){
        cin>>arr2[i++];
    }
    ll maxLen = m > n ? m : n;
    ll* res = SumOfTwoArray(arr1, arr2, n, m);

    for(ll i=0; i<maxLen; i++){
        cout<<res[i]<<" ";
    }
    delete[] res;

	return 0;
}

//By Ai

//By Sumit malik