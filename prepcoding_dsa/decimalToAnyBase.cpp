//By Author Aman Kumar
ll decimalToAnyBase(ll num, ll base){
	ll result = 0;
	ll powTen = 1;

	while(num){
		ll rem = num%base;
		ll newNum = rem*powTen;

		result += newNum;

		powTen *= 10;
		num /= base;
	}
	return result;
}

//By Ai
#include <string>

std::string decimalToAnyBase(ll num, ll base) {
    if (num == 0) return "0";
    std::string result = "";
    while (num) {
        ll rem = num % base;
        // Support for bases > 10:
        char digit = (rem < 10) ? ('0' + rem) : ('A' + rem - 10);
        result = digit + result;
        num /= base;
    }
    return result;
}



//By Sumit Malik
// Function to convert a decimal number to any base (base ≤ 10)
// Returns the result as an integer that represents the new base digits in order.
typedef long long ll;

ll decimalToAnyBase(ll num, ll base) {
    ll result = 0, powTen = 1;
    while (num) {
        result += (num % base) * powTen;
        powTen *= 10;
        num /= base;
    }
    return result;
}
