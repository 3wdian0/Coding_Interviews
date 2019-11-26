#include<iostream>

using namespace std;

void swap(int *a, int *b){
    if(a<b){
        int *t = a;
        a = b;
        b = t;
    }
}

int swap1(int a, int b){
    if(a<b)
        return b;
    else
        return a;
}
int swap2(int a, int b){
    if(a<b)
        return b;
    else
        return a;
}

int gcd(int a, int b){
    /* 
     * Greatest Common Divisor(GCD)
     *
     * 辗转相除法
     *
     *
     */
    if(a<0||b<0)
        return 0;
    int t;
    swap(a,b);
    while(b>0){
        t = a%b;
        swap(a,b);
        b = t;
    }

    return a;
}

int main(int main, char * argc[]){
    int a = 10, b = 15;
    cout<<gcd(a,b)<<endl;
    a = 9;
    b = 10;
    cout<<gcd(a,b)<<endl;
    return 0;
}
