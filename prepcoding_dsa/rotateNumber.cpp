//Author Aman Kumar
void change(ll *a, ll *b){
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void rotateNumber(ll& num, ll& target){	
	
	int digits = num > 1 ? log10(num) : 0 ;
	ll result = 0;

	if(target <0 || target > digits+1){
		cout<<-1<<endl;
		return;
	}
	while(target--){
		int rem = num%10;
		ll newValue = rem*pow(10,digits);
		num /= 10;
		num = newValue + num;
	}

	cout<<num<<endl;
}


// by Ai
#include <iostream>
#include <cmath>

void rotateNumber(long long& num, long long& target) {
    if (num < 0) {
        std::cout << "Input number should be non-negative." << std::endl;
        return;
    }

    int digits = (num == 0) ? 1 : std::floor(std::log10(num)) + 1;
    
    if (target < 0 || target >= digits) {
        std::cout << -1 << std::endl;
        return;
    }

    long long power = std::pow(10, target);
    long long rem = num % power;
    long long newValue = rem * std::pow(10, digits - target);
    num /= power;
    num = newValue + num;
    std::cout << num << std::endl;
}

ll digitCount(ll num){
    ll cnt = 0;
    if (num == 0) return 1;
    while(num){
        num /= 10;
        cnt++;
    }
    return cnt;
}

ll intPow(ll base, ll exp) {
    ll result = 1;
    while (exp--) result *= base;
    return result;
}

ll rotateNumber(ll num, ll target){
 ll numDigitCount = digitCount(num);
    if (numDigitCount == 1) return num;

    target %= numDigitCount;

    if (target < 0)
        target += numDigitCount; // Convert negative (left) to positive right rotation

    if (target == 0) return num;

    ll tenPow = intPow(10, target);
    ll divPow = intPow(10, numDigitCount - target);

    ll rem = num % divPow;
    ll div = num / divPow;

    ll result = rem * tenPow + div;

    return result;
}

// by summit malik
void rotateNumber(ll& num, ll& target){		
    int temp = n;
    int nod = 0;
    while (temp > 0) {
        temp = temp / 10;
        nod++;
    }

    k = k % nod;
    if (k < 0) {
        k = k + nod;
    }

    int div = 1;
    int mult = 1;
    for (int i = 1; i <= nod; i++) {
        if (i <= k) {
            div = div * 10;
        } else {
            mult = mult * 10;
        }
    }

    int q = n / div;
    int r = n % div;

    r = r * mult + q;
    System.out.println(r);
}