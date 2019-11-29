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


bool digit(int i, int j, int k){
    if(number(i)+number(i)<=k)
        return  true;
    else
        return false;
}


bool check(int i, int j, vector<vector<bool> > &visited, int k){
    if(i>=0 && j>=0 && i<visited.size() && j<visited[0].size() && digit(i, j, k) && visited[i][j]==false){
        return true;
    }
    else
        return false;
}

int movingCountCore(int i, int j, vector<vector<bool> > &visited, int k){
    int count = 0;
    if(check(i,j,visited, k)){
        // 找到一个, 即count加1
        visited[i][j] = true;
        count = 1 + movingCountCore(i+1,j,visited,k)+movingCountCore(i,j+1,visited,k)+movingCountCore(i-1,j,visited,k)+movingCountCore(i,j-1,visited,k);
    }
    return count;
}

int movingCount(int m, int n){
    // visited 标记矩阵
    vector<vector<bool> > visited;
    for(int i=0; i<m; i++){
        vector<bool> t;
        for(int j=0; j<n; j++){
            t.push_back(false);
        }
        visited.push_back(t);
    }
    // 从起点<0,0>开始回溯
    int count = movingCountCore(0,0,visited,18);

    return count;
}


int main(int argc, char *argv []){
    cout<<movingCount(5,4)<<endl;
    cout<<movingCount(4,4)<<endl;
    cout<<movingCount(1,4)<<endl;
    cout<<movingCount(0,4)<<endl;
    cout<<movingCount(-1,4)<<endl;
    return 0;
}
