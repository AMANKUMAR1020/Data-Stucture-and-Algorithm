//By Auhtor Aman Kumar
string numToStr(ll num){
	string str = "";
	ll len = num ? log10(num) + 1 : 0 ;

	if(len == 0)
		return str;

	while(num){
		char c = '0' + num%10;
		str = c + str;
		num /= 10;
	}
	cout<<str<<endl;

	ll leadingZero = 4;
	while(len + leadingZero > str.size()){
		str = '0' + str;
	}
	cout<<str<<endl;

	return str;
}

ll countDigitFreq(ll num, ll target){
	std::string digitCnt = numToStr(num); // with zeroes 6 assumming
    char targetChar = '0' + target;  // assuming targetDigit < 10
    ll temp = 0;
    for(char c : digitCnt){
        if(c == targetChar) temp++;
    }
    return temp;
}


//By Ai
#include <string>
#include <iomanip>
#include <sstream>

typedef long long ll;

std::string numToStr(ll num) {
    std::ostringstream oss;
    oss << std::setw(6) << std::setfill('0') << num;
    return oss.str();
}

ll countDigitFreq(ll num, ll target){
    string cnt = numToStr(target);
    string digitCnt = numToStr(num); //num ? log10(num) + 1 : 0 ;
    cout<<digitCnt<<endl;
    ll temp = 0;
    for(char c : digitCnt){
        if(cnt == c)
            temp++;
    }
    return temp;
}



//By Sumit Malik

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int d = scn.nextInt();

        int f = getDigitFrequency(n, d);
        System.out.println(f);
    }

    public static int getDigitFrequency(int n, int d) {
        int rv = 0;

        while (n > 0) {
            int dig = n % 10;
            n = n / 10;

            if (dig == d) {
                rv++;
            }
        }

        return rv;
    }
}
