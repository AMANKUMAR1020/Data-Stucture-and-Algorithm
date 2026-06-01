//By Author Aman Kumar
ll baseSubtraction(ll num1, ll num2, ll base){
    if(num1 < num2){
        return -1;
    }

    ll result = 0;
    ll carry = 0;
    ll powTen = 1;

    while(num1 || num2 || carry){
        ll d1 = num1 % 10 - carry;
        ll d2 = num2 % 10;
        ll newVal = d1 >= d2 ? d1-d2 : (d1+base) - d2;

        if(d2 >= d1)
            carry = 1;// it not work for carry++; why
        else
            carry = 0;

        result += newVal*powTen;
        num1 /= 10;
        num2 /= 10;
        powTen *= 10;
    }
    return result;
}


//By Ai
ll baseSubtraction(ll num1, ll num2, ll base) {
    if (num1 < num2) return -1; // Not handling negatives

    ll result = 0, borrow = 0, powTen = 1;

    while (num1 || num2) {
        ll d1 = (num1 % 10) - borrow;
        ll d2 = num2 % 10;

        if (d1 < d2) {
            d1 += base;
            borrow = 1;
        } else {
            borrow = 0;
        }

        ll diff = d1 - d2;
        result += diff * powTen;

        num1 /= 10;
        num2 /= 10;
        powTen *= 10;
    }

    return result;
}


//By Sumit malik
int p = 1;
while (n2 > 0) {
    int d1 = n1 % 10;
    n1 = n1 / 10;
    int d2 = n2 % 10;
    n2 = n2 / 10;

    int d = 0;
    d2 = d2 + c;

    if (d2 >= d1) {
        c = 0;
        d = d2 - d1;
    } else {
        c = -1;
        d = d2 + b - d1;
    }

    rv = rv + d * p;
    p = p * 10;
}

return rv;
