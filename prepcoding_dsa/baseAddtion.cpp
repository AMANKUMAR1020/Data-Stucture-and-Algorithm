//By Author Amna Kumar
ll baseAddtion(ll num1, ll num2, ll base){
    ll result = 0;
    ll carry = 0;
    ll powTen = 1;

    // Add corresponding digits
    while(num1 > 0 || num2 > 0 || carry){
        ll d1 = num1 % 10;
        ll d2 = num2 % 10;
        ll sum = d1 + d2 + carry;

        carry = (sum >= base) ? sum/base : 0;

        result += (sum % base) * powTen;

        num1 /= 10;
        num2 /= 10;
        powTen *= 10;
    }
    return result;
}

// By Ai
ll baseAddition(ll num1, ll num2, ll base) {
    ll result = 0, carry = 0, powTen = 1;

    while (num1 || num2 || carry) {
        ll d1 = num1 % 10;
        ll d2 = num2 % 10;

        ll sum = d1 + d2 + carry;
        result += (sum % base) * powTen;
        carry = sum / base;

        num1 /= 10;
        num2 /= 10;
        powTen *= 10;
    }

    return result;
}


// By Sumit malik
ll baseAddtion(ll num1, ll num2, ll base){
    ll result = 0;
    ll carry = 0;
    ll powTen = 1;

    // Add corresponding digits
    while(num1 > 0 || num2 > 0 || carry){
        ll d1 = num1 % 10;
        ll d2 = num2 % 10;
        ll sum = d1 + d2 + carry;

        carry = (sum >= base) ? sum/base : 0;

        result += (sum % base) * powTen;

        num1 /= 10;
        num2 /= 10;
        powTen *= 10;
    }
    return result;
}