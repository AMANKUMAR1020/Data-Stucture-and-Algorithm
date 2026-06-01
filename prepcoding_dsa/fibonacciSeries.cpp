// by Aman X Ai

void fibonacciSeries(ll& cnt){
	ll first=0,second=1;
	for(ll i=0; i<=cnt; i++){
		if(i==0){
			cout<<first<<" ";
		}else{
			ll result = first + second;
			first = second;
			second = result;
			cout<<result<<" ";
		}
	}
}


// by summit malik
void fibonacciSeries(ll& cnt){
	ll first=0,second=1;
	for(ll i=0; i<=cnt; i++){
		cout<<first<<" ";
		ll result = first + second;
		first = second;
		second = result;
	}
}