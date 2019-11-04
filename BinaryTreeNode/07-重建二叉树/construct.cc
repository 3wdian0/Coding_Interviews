#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


/*
 *  前序遍历 [1 2 4 5 3 6 7]
 *  中序遍历 [4 2 5 1 6 3 7]
 *        1 
 *      /   \
 *     2     3
 *    / \   / \
 *   4   5 6   7 
 */

/*
 *  前序遍历 [1 2 3]
 *  中序遍历 [2 1 3]
 *        1 
 *      /   \
 *     2     3
 */

TreeNode * constructCore(vector<int> &pre, vector<int> &in, int prestart, int preend, int instart, int inend){
    // 前序遍历根节点
    TreeNode *root = new TreeNode(pre[prestart]);
    if(prestart==preend){
        /*
         * 停止条件, 重要！！！
         */
        return root;
    }

    int tag = instart;
    while(in[tag]!=root->val){
        tag += 1;
    }
    int length = tag - instart;

    root->left = constructCore(pre,in, prestart+1,        prestart+(length), instart, tag-1);
    root->right= constructCore(pre,in, prestart+length+1, preend,            tag+1,   inend);
    return root;
}

TreeNode * construct(vector<int> &pre, vector<int> &in){
    return constructCore(pre, in, 0, pre.size()-1,  0, in.size()-1);
}

void levelOrderTraversal(TreeNode * root){
    if(root==NULL)
        return ;
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    q1.push(root);
    while(!q1.empty()){
        cout<<q1.front()->val<<" ";
        if(q1.front()->left!=NULL)
            q2.push(q1.front()->left);
        if(q1.front()->right!=NULL)
            q2.push(q1.front()->right);
        q1.pop();
        if(q1.empty()){
            queue<TreeNode *> t = q1; q1 = q2; q2 = t;
            cout<<endl;
        }
    }

}
void _print(vector<int> num){
    for(int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, char * argv[]){
    vector<int> pre;
    vector<int> in;
    // 测试用例1
    //pre.push_back(1); pre.push_back(2); pre.push_back(3);
    //in.push_back(2);  in.push_back(1);  in.push_back(3);

    // 测试用例2
    pre.push_back(1); pre.push_back(2); pre.push_back(4); pre.push_back(5); pre.push_back(3); pre.push_back(6); pre.push_back(7);
    in.push_back(4);  in.push_back(2);  in.push_back(5);  in.push_back(1);  in.push_back(6);  in.push_back(3);  in.push_back(7);

    cout<<"前序遍历:";_print(pre);
    cout<<"中序遍历:";_print(in);
    TreeNode * constructRoot = construct(pre,in);
    cout<<"构建后，进行层序遍历:"<<endl;
    levelOrderTraversal(constructRoot);
    return 0;
}
