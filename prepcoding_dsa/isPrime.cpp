//Author Aman Kumar

bool isPrime(long long int& n){
	long long int num = 1;
	int cnt=0;

	for(long long int i=1; i<n/2; i++){
		if(!(n%i))
			cnt++;
	}
	return cnt==1 ? true : false;
}

// by Ai
bool isPrime(long long int& n){
	if(n==2 || n==3)
		return true;

	if(n<1 || !(n%2) || !(n%3))
		return false;

	for(long long int i=5; i <= n/i; i += 6){
		if(!(n%i) || !(n%(i+2)))
			return false;
	}
	return true;
}


// by summit malik
bool isPrime(long long int& n){
	ll num = sqrt(n);
	for(ll i=2; i<=num; i++){
		if(!(n%i))
			return false;
	}
	return true;
}