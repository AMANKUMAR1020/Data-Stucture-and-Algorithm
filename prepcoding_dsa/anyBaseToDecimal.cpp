//By Author Aman Kumar
ll anyBaseToDecimal(ll num, ll base){
	ll result = 0;
	ll b = 1;

	while(num){
		ll rem = num%10;
		result += rem*b;
		num /= 10;
		b *= base;
	}
//	cout<<result<<endl;
	return result;
}



ll convertToAnyBaseCase(ll target, ll ib, ll fb){
	ll num = anyBaseToDecimal(target, ib);
	ll numBasePow = ib;
	ll numBase = 1;
	ll result = 0;

	while(num){
		ll rem = num%fb;
		ll temp = rem*numBase;

		result += temp;

		numBase *= numBasePow;
		num /= fb;
	}
	return result%(ll)MAX;
}




//By Ai


//By Sumit Malik
