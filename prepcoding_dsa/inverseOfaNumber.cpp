//Author Aman Kumar
void inverseOfaNumber(ll& num){
	ll n = num;
	int cnt = n>0 ? log10(n)+1 : 0;
	ll arr[cnt+1]={0};
	int i=1;
	while(i<=cnt){
		arr[(cnt - n%10)] = i++;
		n /= 10;
	}
	for(i=0; i<cnt; i++){
		cout<<arr[i];
	}
}

// by Ai
void inverseOfaNumber(ll num) {
    int digits = num > 0 ? log10(num) + 1 : 0;
    vector<int> inv(digits + 1, 0);

    for (int pos = digits; pos >= 1; --pos) {
        int digit = num % 10;
        inv[digit] = pos;
        num /= 10;
    }

    for (int i = 1; i <= digits; ++i) {
        cout << inv[i];
    }
    cout << endl;
}


// by summit malik sir
void inverseOfaNumber(ll& num){
	ll n = num;
	ll result=1;
	int cnt=1;

	while( n != 0 ){
		int rem = n%10;
		n /= 10;
		int newValue = cnt*pow(10,rem);
		result += newValue;
		cnt++;
	}
	cout<<result<<'\n';
}
