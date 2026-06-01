//By Author Aman Kumar
ll BaseToDecimal(ll num, ll base){
	ll result = 0;
	ll powBase = 1;

	while(num){
		result += (num%10)*powBase;
		num /= 10;
		powBase *= base;

	}
	return result;
}

//By Ai
typedef long long ll;

ll BaseToDecimal(ll num, ll base) {
    ll result = 0, powBase = 1;
    while (num) {
        result += (num % 10) * powBase;
        powBase *= base;
        num /= 10;
    }
    return result;
}

#include <string>
typedef long long ll;

ll BaseToDecimalStr(const std::string& numStr, ll base) {
    ll result = 0;
    for(char c : numStr) {
        ll digit;
        if ('0' <= c && c <= '9') digit = c - '0';
        else if ('A' <= c && c <= 'Z') digit = c - 'A' + 10;
        else if ('a' <= c && c <= 'z') digit = c - 'a' + 10;
        else continue; // or handle error
        result = result * base + digit;
    }
    return result;
}


//By Sumit Malik
public static int getValueInDecimal(int n, int b) {
    int rv = 0;
    int p = 1;

    while (n > 0) {
        int dig = n % 10;
        n = n / 10;

        rv += dig * p;
        p = p * b;
    }

    return rv;
}
