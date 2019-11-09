#include<iostream>
#include<vector>
#include<limits.h>

#define max(x,y) (x>y)?x:y;

using namespace std;

/*
 *
 * 绳子长度为n
 * 剪成m段：k[0] k[1] k[2] . . . k[m-1]
 * (n>1, m>1)
 * k[0]*k[1]*k[2]*...*k[m-1]
 *
 * 长度为：1
 * 长度为：2
 * 长度为：3
 *
 */

int maxProductAfterCutting_dynamicSolution(int n){
    vector<int> num ;
    for(int i = 0; i<=5; i++){
        num.push_back(1);
    }
    /*
     * num[1] = 1;
     * num[2] = 2;
     * num[3] = 3;
     * num[4] = 4;
     * num[5] = 2*3;
     */
    for(int j=1; j<=n; j++){
        int q = INT_MIN;
        for(int i=1;i<=j;i++){
            q = max(q, i*num[j-i]);
        }
        num[j] = q;
    }

    return num[n];
}
int main(int argc, char * argv []) {
    int i;
    i=1;cout<<i<<"->"<<maxProductAfterCutting_dynamicSolution(i)<<endl;
    i=2;cout<<i<<"->"<<maxProductAfterCutting_dynamicSolution(i)<<endl;
    i=3;cout<<i<<"->"<<maxProductAfterCutting_dynamicSolution(i)<<endl;
    i=4;cout<<i<<"->"<<maxProductAfterCutting_dynamicSolution(i)<<endl;
    i=5;cout<<i<<"->"<<maxProductAfterCutting_dynamicSolution(i)<<endl;
    i=8;cout<<i<<"->"<<maxProductAfterCutting_dynamicSolution(i)<<endl;
    return 0;
}
