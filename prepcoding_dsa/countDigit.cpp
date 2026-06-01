// by Aman Kumar 
int countDigit(ll& n){
	return n==0 ? 0 : log10(n)+1;
}

// by Summit malik sir;
int countDigit(ll& n){
	int cnt=0;
	while( n != 0){
		n /= 10;
		cnt++;
	}
	return cnt;
}