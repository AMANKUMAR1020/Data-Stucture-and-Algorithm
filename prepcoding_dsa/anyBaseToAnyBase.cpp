//By Author Aman Kumar
ll anyBaseToDecimal(ll num, ll base){
    ll result = 0;
    ll powBase = 1;

    while(num){
        result += (num%10)*powBase;
        powBase *= base;
         num /= 10;
    }
    cout<<result<<endl;
    return result;
}

ll decimalToAnyBase(ll num, ll base){
    ll result = 0;
    ll powBase = 1;

    while(num){
        result += (num%base)*powBase;
        num /= base;
        powBase *= 10;
    }
    cout<<result<<endl;
    return result;
}


ll anyBaseToAnyBase(ll target, ll ib, ll fb){
    ll num = anyBaseToDecimal(target, ib);
    ll result = decimalToAnyBase(num, fb);

    return result;
}

//By Ai
inline ll anyBaseToAnyBase(ll target, ll ib, ll fb) {
    ll num = 0, powBase = 1;
    while (target) {
        num += (target % 10) * powBase;
        powBase *= ib;
        target /= 10;
    }
    ll result = 0, powTen = 1;
    while (num) {
        result += (num % fb) * powTen;
        num /= fb;
        powTen *= 10;
    }
    return result;
}



//By Sumit Malik
ll anyBaseToDecimal(ll num, ll base){
    ll result = 0;
    ll powBase = 1;

    while(num){
        result += (num%10)*powBase;
        powBase *= base;
         num /= 10;
    }
    cout<<result<<endl;
    return result;
}

ll decimalToAnyBase(ll num, ll base){
    ll result = 0;
    ll powBase = 1;

    while(num){
        result += (num%base)*powBase;
        num /= base;
        powBase *= 10;
    }
    cout<<result<<endl;
    return result;
}


ll anyBaseToAnyBase(ll target, ll ib, ll fb){
    ll num = anyBaseToDecimal(target, ib);
    ll result = decimalToAnyBase(num, fb);

    return result;
}