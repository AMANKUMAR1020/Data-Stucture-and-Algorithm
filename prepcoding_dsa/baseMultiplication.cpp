//By Author Aman Kumar
ll SingleDigitMultiplication(ll num, ll d, ll base){
    ll result = 0;
    ll powTen = 1;
    ll carry = 0;

    while(num){
        ll newNum = ((num%10) * d) + carry;

        carry = newNum/base;
        result += (newNum%10)*powTen; // change to 10 to base
        powTen *= 10;
        num /= 10;
    }
    result += carry*powTen;
    return result;
}
ll baseMultiplication(ll num1, ll num2, ll base){
    ll result = 0;
    ll powTen = 1;

    while(num1 && num2){

        ll num2Digit = num2 % 10;
        num2 /= 10;
        ll sumResult = SingleDigitMultiplication(num1, num2Digit, base);

        result += (sumResult*powTen);
        powTen *= 10;
    }
    return result;
}


//By Ai
ll SingleDigitMultiplication(ll num, ll d, ll base){
    ll result = 0;
    ll powTen = 1;
    ll carry = 0;

    while(num){
        ll newNum = ((num%10) * d) + carry;

        carry = newNum/base;
        result += (newNum%base)*powTen;
        powTen *= 10;
        num /= 10;
    }
    result += carry*powTen;
    return result;
}
ll baseMultiplication(ll num1, ll num2, ll base){
    ll result = 0;
    ll powTen = 1;

    while(num1 && num2){

        ll num2Digit = num2 % 10;
        num2 /= 10;
        ll sumResult = SingleDigitMultiplication(num1, num2Digit, base);

        result += (sumResult*powTen);
        powTen *= 10;
    }
    return result;
}


//By Sumit malik
public static int getSum(int b, int n1, int n2) {
    int rv = 0;

    int c = 0;
    int p = 1;

    while (n1 > 0 || n2 > 0 || c > 0) {
        int d1 = n1 % 10;
        int d2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;

        int d = d1 + d2 + c;
        c = d / b;
        d = d % b;

        rv += d * p;
        p *= 10;
    }

    return rv;
}
public static int getProductWithASingleDigit(int b, int n1, int d2) {
    int rv = 0;

    int c = 0;
    int p = 1;

    while (n1 > 0 || c > 0) {
        int d1 = n1 % 10;
        n1 = n1 / 10;

        int d = d1 * d2 + c;
        c = d / b;
        d = d % b;

        rv += d * p;
        p *= 10;
    }

    return rv;
}
public static int getProduct(int b, int n1, int n2) {
    int rv = 0;

    int p = 1;

    while (n2 > 0) {
        int d2 = n2 % 10;
        n2 = n2 / 10;

        int sprd = getProductWithASingleDigit(b, n1, d2);
        rv = getSum(b, rv, sprd * p);

        p *= 10;
    }

    return rv;
}
