#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

/*
 * 18/2=9···0
 *  9/2=4···1
 *  4/2=2···0
 *  2/2=1···0 
 *  1/2=0···1
 */

void binary(int x){
    stack<int> s;
    while(x/2!=0){
        s.push(x%2);
        x = x/2;
    }
    if(x%2!=0)
        s.push(1);
    while(!s.empty()){
        int i = s.top();
        s.pop();
        cout<<i;
    }
    cout<<endl;
} 

int method1(int x){
    int n = 0;
    while(x/2!=0){
        if(x%2==1)
            n++;
        x /=2;
    }
    if(x%2!=0)
        n++;
    return n;
}
int method2(int x){
    /*
     * 先判断整数的二进制表示的最右边是不是1
     * 判断完最右边，整数右移一位，此时，最右边第二位，变成了最右边第一位
     * 
     * 判断最右边第一位是不是1方法：把整数和1做'与运算'。理由：6的二进制是110，11的二进制是1011，那么6 and 11的结果就是2，它是二进制对应位进行逻辑运算的结果（0表示False，1表示True，空位都当0处理）。
     *
     * 注：负数右移会怎么样
     */
    int n = 0;
    while(x){
        if(x & 1){
            n++;
        }
        x = x>>1;
    }
    return n;
}
int method3(int x){
    /*
     * 换个角度，让1左移和数字做与运算进行判断
     * 1
     * 10
     * 100
     * 1000
     */
     unsigned int tag=1;
     int count=0;
     while(tag){
         if(x & tag){
             count++;
         }
         tag = tag << 1;
     }
     return count;
}
int main(int argc, char *argv[]){
    // 题目是说整数，所以就需要考虑：正数、负数、0
    binary(18);
    cout<<"法0:"<<method1(18)<<endl;
    cout<<"法1:"<<method2(18)<<endl;
    cout<<"法2:"<<method3(18)<<endl;
    cout<<(18)<<" ";binary(18);
    cout<<(18>>1)<<"  ";binary(18>>1);
    cout<<(18>>1>>1)<<"  ";binary(18>>1>>1);
    cout<<(18<<1)<<" ";binary(18<<1);
    cout<<"(18 & 1)="<<(18 & 1)<<" ";binary(18&1);
    cout<<"( 9 & 1)="<<(9 & 1)<<" ";binary(18&1);
    return 0;
}
