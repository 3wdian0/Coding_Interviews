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

int main(int argc, char *argv[]){
    binary(18);
    cout<<method1(18)<<endl;
    return 0;
}
