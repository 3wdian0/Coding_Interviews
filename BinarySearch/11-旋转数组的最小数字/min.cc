#include<iostream>
#include<vector>

#define min_(x,y) (x>y)?y:x;

using namespace std;

void _print2(vector<int> &vec, int start, int end){
    cout<<"start:";
    for(int i=start; i<=end; i++){
        cout<<vec[i]<<" ";
    }
    cout<<"end";
    cout<<endl;
}

void _print(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void min(vector<int> &vec, int start, int end){
    if(start==end){
        cout<<"min:"<<vec[start]<<endl;
        return ;
    }
    if(start+1==end){
        int t = min_(vec[start],vec[start+1]);
        cout<<"min:"<<t<<endl;
        return ;
    }
    int m = (start+end)/2;
    if(vec[start]<=vec[m]){
        _print2(vec,m,end);
        min(vec, m, end);
    }else{
        _print2(vec,start,m);
        min(vec, start, m);
    }
}
int main(int argc, char * argv[]){
    vector<int> vec;
    // 4,5,6,7,1,2,3
    //vec.push_back(4);vec.push_back(5);vec.push_back(6);vec.push_back(7);vec.push_back(1);vec.push_back(2);vec.push_back(3);
    vec.push_back(1);vec.push_back(2);
    _print(vec);
    min(vec,0,vec.size()-1);
    return 0;
}
