#include<iostream>
#include<stdio.h>
#include<cstdlib>

using namespace std;

/*
 * 圆形面积:   pi*(r)^2
 * 正方形面积: (2r)^2
 * (pi*r*r)/(2r*2r) = pi/4 = 点在圆形内的次数/所有点的次数 = count/n
 * pi = count/n*4
 */
double area(int n, int m){
    double pi=0.0;
    int count = 0;
    for(int i=0; i<n; i++){
        int x = rand()%m;
        int y = rand()%m;
        if(x*x+y*y<m*m){
            count++;
        }
    }
    pi = double(count)/n*4;
    return pi;
}

int main(int argc, char * argv[]){
    // rand()会返回一随机数值, 范围在0至RAND_MAX 间。RAND_MAX定义在stdlib.h, 其值为2147483647。
    cout<<rand()%100<<endl;
    double pi = area(1000000,10000);
    printf("%f\n",pi);
    return 0;
}
