

// By Author Aman Kumar
ll gcd(ll num1, ll num2){
	if(num2 < num1)
		change(&num2, &num1);
	ll num = num1;
	ll res = 1;
	while(num != 1){
		if(num1%num==0 && num2%num==0)
			res = num;
		num--;
	}
	return res;
}


ll lcm(ll num1, ll num2){
	if(num2 < num1)
		change(&num2, &num1);
	ll num = num1;
	ll res = 1;
	while(num != 1){
		if(num1%num==0 && num2%num==0)
			return num;
		num--;
	}
	return res;
}

// By Ai (using Euclidean Algorithm)
ll gcd(ll num1, ll num2){
	while(num1 != 0){
		ll temp = num1;
		num1 = num2%num1;
		num2 = temp;
	}
	return num2;
}

ll lcm(ll num1, ll num2){
	return (num1 /gcd(num1,num2) * num2);
}

// By Author Sumit Malik
ll gcd(ll num1, ll num2){

	if(num2%num1 == 0)
		return num1;

	return gcd(num2%num1, num1);
}
ll lcm(ll num1, ll num2){
	return (num1*num2) / gcd(num1,num2);
}
