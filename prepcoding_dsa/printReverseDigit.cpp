//Author Aman Kumar
void printReverseDigit(ll& num){
	ll mod = 0;
	ll n = num;
	while(n != 0){
		n /= 10;
		mod++;
	}

	int temp = pow(10, mod-1);

	while(temp != 0){
		cout<<num%10<<endl;
		num /= 10;
		temp /= 10;
	}
}

// by Ai

// by summit malik

void printReverseDigit(ll& num){
	ll mod = 0;
	ll n = num;
	while(n != 0){
		cout<<n%10<<endl;
		n /= 10;
	}
}


