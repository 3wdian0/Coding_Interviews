#include<iostream>
#include<vector>

using namespace std;

/*
 *
 * 长度为：1
 * 长度为：2
 * 长度为：3
 *
 * 绳子
 * 长度为n：- - - - - -
 * 剪成m段：k[0] k[1] k[2] . . . k[m]
 * (n>1, m>1)
 */

int maxProductAfterCutting_dynamicSolution(int n, int m){
    vector<int> num ;
    for(int i = 0; i<=n; i++){
        num.push_back(0);
    }
    num[1] = 1;
    num[2] = 2;
    return 0;
}
int main(int argc, char * argv []) {
    return 0;
}
