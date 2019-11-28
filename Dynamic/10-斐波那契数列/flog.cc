#include<iostream>
#include<vector>

using namespace std;
/*
 * 一只青蛙，可以跳1级台阶，也可以跳2级台阶。
 * 一共有n级台阶，可以有多少种跳法。
 */

int f(int n){
    if(n==2)
        return 2;
    if(n==1)
        return 1;
    if(n<1)
        return 0;
    return f(n-2)+f(n-1);
}

int main(int argc, char *argv[]){
    /*
     * 以4为例：
     * 1 (1 1 1) = f(3) 
     * 2 (2)     = f(2)
     */
    cout<<f(4)<<endl;
    cout<<f(2)<<";"<<f(3)<<endl;
    cout<<f(5)<<endl;
    return 0;
}
