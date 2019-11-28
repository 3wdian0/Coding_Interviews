#include<iostream>
#include<vector>

using namespace std;

int number(int i){
    int sum = 0;
    while(i){
        sum+=i%10;
        i = i/10;
    }
    return sum;
}

int main(int argc, char *argv []){
    cout<<number(35)+number(37)<<endl;
    return 0;
}
