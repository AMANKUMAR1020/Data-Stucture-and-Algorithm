// refined by Aman x Ai

void printPrime(ll low, ll high, ll *arr){
	for(ll i=0; i<high; i++){
		arr[i]=0;
	}
	arr[0]=0;
	arr[1]=0;

	ll num = sqrt(high);

	for(ll i=2; i<=num; i++){
		for(ll j=i*i; j<=high; j+=i){
			arr[j] = 1;
		}
	}
	for(ll i=low; i<=high; i++){
		if(arr[i]==0)
			cout<<i<<" ";
	}
	cout<<endl;
}

//by Ai
#include <iostream>
#include <cmath>

typedef long long ll;

void printPrime(ll low, ll high) {
    bool* arr = new bool[high + 1];
    for (ll i = 0; i <= high; i++) {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;

    ll num = sqrt(high);
    for (ll i = 2; i <= num; i++) {
        if (arr[i]) {
            for (ll j = i * i; j <= high; j += i) {
                arr[j] = false;
            }
        }
    }

    for (ll i = low; i <= high; i++) {
        if (arr[i])
            std::cout << i << " ";
    }
    std::cout << std::endl;

    delete[] arr;
}

int main() {
    ll low, high;
    std::cout << "Enter the lower bound: ";
    std::cin >> low;
    std::cout << "Enter the upper bound: ";
    std::cin >> high;
    printPrime(low, high);
    return 0;
}