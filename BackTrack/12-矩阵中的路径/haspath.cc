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
bool hasPathCore(vector<vector<char> > &matrix, int i, int j, int &length, vector<vector<bool> > visited, string &str);

bool hasPath(vector<vector<char> > matrix, string str){
    // visited 标记矩阵
    vector<vector<bool> > visited;
    for(int i=0; i<matrix.size(); i++){
        vector<bool> t;
         for(int j=0; j<matrix[0].size(); j++){
            t.push_back(false);
        }
        visited.push_back(t);
    }
    // 记录当前在矩阵中找到的字符串长度
    int length = 0;
    // 从起点<0,0>开始回溯
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(hasPathCore(matrix,i,j,length,visited,str)){
                cout<<"  找到:"<<str<<endl;
                return true; // 找到在for中结束
            }
        }
    }

    cout<<"没找到:"<<str<<endl;
    return false; //  在for中没结束, 即没找到
}

bool hasPathCore(vector<vector<char> > &matrix, int i, int j, int &length, vector<vector<bool> > visited, string &str){
    if(str[length]=='\0'){
        // important: 停止条件
        return true;
    }

    // 默认为false
    bool tag = false;
    if(i<matrix.size() && j<matrix[0].size() && i>=0 && j>=0 && str[length]==matrix[i][j] && visited[i][j]==false){
        visited[i][j] = true;
        length += 1;
        tag = (hasPathCore(matrix,i+1,j,length,visited,str)||hasPathCore(matrix,i,j+1,length,visited,str)||hasPathCore(matrix,i-1,j,length,visited,str)||hasPathCore(matrix,i,j-1,length,visited,str));
        if(tag==false){
            visited[i][j] = false;
            length -= 1;
        }
    }
    return tag;
}
int main(int arc, char *argv[]){
    vector<vector<char> > matrix;
    vector<char> c;
    c.push_back('a');c.push_back('b');c.push_back('f');c.push_back('g'); matrix.push_back(c);c.clear();
    c.push_back('c');c.push_back('f');c.push_back('c');c.push_back('s'); matrix.push_back(c);c.clear();
    c.push_back('j');c.push_back('d');c.push_back('e');c.push_back('h'); matrix.push_back(c);c.clear();
    _print(matrix);
    string s = "bfce";
    hasPath(matrix,s);
    s = "abfb";
    hasPath(matrix,s);
    return 0;

}

