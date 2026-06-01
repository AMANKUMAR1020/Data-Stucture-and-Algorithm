
// by Aman Kumar 
void printDigitLeftToRight(ll& n){
	ll temp=0;
	while(n != 0){
		temp = temp*10 + n%10;
		n /= 10;
	}
	cout<<temp<<endl;
}


// by Summit malik sir;
void printDigitLeftToRight(ll& num){
	ll mod = 0;
	ll n = num;
	while(n != 0){
		n /= 10;
		mod++;
	}

	int temp = pow(10, mod-1);

	while(temp != 0){
		cout<<num/temp<<endl;
		num %= temp;
		temp /= 10;
	}
}
