#include<iostream>
#include<vector>
#include<string>

using namespace std;

void _print(vector<vector<char> > matrix){
    // matrix[i][j]
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool hasPath(vector<vector<char> > matrix){
    // visited 标记
    vector<vector<bool> > visited;
    for(int i=0; i<3; i++){
        vector<bool> t;
         for(int j=0; j<4; j++){
            t.push_back(false);
        }
        visited.push_back(t);
    }
    // 记录当前在矩阵中找到的字符串长度
    int length = 0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            //hasPathCore();
        }
    }

   return true;
}

bool hasPathCore(vector<vector<char> > &matrix, int i, int j, int &length, vector<vector<bool> > visitd){
    return true;
}
int main(int arc, char *argv[]){
    vector<vector<char> > matrix;
    vector<char> c;
    c.push_back('a');c.push_back('b');c.push_back('f');c.push_back('g'); matrix.push_back(c);c.clear();
    c.push_back('c');c.push_back('f');c.push_back('c');c.push_back('s'); matrix.push_back(c);c.clear();
    c.push_back('j');c.push_back('d');c.push_back('e');c.push_back('h'); matrix.push_back(c);c.clear();
    _print(matrix);
    string s1 = "bfce";
    string s2 = "abfb";
    return 0;

}

