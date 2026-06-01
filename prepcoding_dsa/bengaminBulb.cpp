// by Author Aman Kumar
vector<ll> bengaminBulb(ll a, ll b){
	if(a<b)
		return {};

	vector<ll> vec(a, 0);
	for(ll i=1; i<=b; i++){
		for(ll j=i; j<a; j+=i){
			vec[j] = vec[j] == 0 ? 1 : 0;
		}
	}
	return vec;
}

void print(vector<ll>& num){
	for(ll i=0; i<num.size(); i++)
		if(num[i]==1)
			cout<<i<<" ";
}


//By Ai

//By Sumit Malik
vector<ll> bengaminBulb(ll a, ll b){
	if(a<b)
		return {};

	vector<ll> vec;
	for(ll i=1; i*i<=a; i++){
		vec.push_back((i*i));
	}
	return vec;
}


void print(vector<ll>& num){
	for(ll i=0; i<num.size(); i++)
		cout<<num[i]<<" ";
}
