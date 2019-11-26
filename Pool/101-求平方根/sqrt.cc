#include<iostream>
#include<cmath>

using namespace std;

// 二分法
double sqrt1(double n){
    double low = 0.0;
    double high= n;
    double mid = (low + high) / 2.0;
    while(abs(mid*mid-n)>0.00001){
        if(mid*mid>n)
            high = mid;
        else
            low  = mid;
        mid = (low + high) / 2.0;
    }
    return mid;
}

// 牛顿迭代法
double fun(double x, double n){
    return x*x-n;
}
double fun_(double x){
    return 2*x;
}
double sqrt2(double n) {
    /*
     * x^2  = n
     * 求x
     * 
     * f(x) = x^2 -n
     * 求f(x)=0的解, 牛顿迭代法
     * f'(x)= 2x 
     * y=f(x_0)+f'(x_0)(x-x_0)
     * -f(x_0)/f'(x_0)+x_0=x
     */
    double x = n;
    while(abs(x*x-n)>0.00001){
        x = x-fun(x,n)/fun_(x);
    }

    return x;
}

int main(int argc, char * argv[]){
    double x = 9.0;
    x = 10.;
    cout<<sqrt(x)<<endl;
    cout<<sqrt1(x)<<endl;
    cout<<sqrt2(x)<<endl;
    return 0;
}
