#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

bool hasSubtreeCore(TreeNode *A, TreeNode *B);

// 迭代遍历树A的同时, 检查B是否是A的子树
bool hasSubtreeIterative(TreeNode *root, TreeNode * B){
    queue<TreeNode *> q1,q2;
    if(root!=NULL){
        q1.push(root);
    }
    while(!q1.empty()){
        TreeNode * t = q1.front();
        cout<<"迭代"<<t->val<<" ";
        if(hasSubtreeCore(t,B)==true)
            return true;
        if(t->left!=NULL){
            q2.push(t->left);
        }
        if(t->right!=NULL){
            q2.push(t->right);
        }
        q1.pop();
        if(q1.empty()){
            queue<TreeNode *> q = q1; q1 = q2; q2 = q;
            cout<<endl;
        }
        
    }
    return false;
}

/*
 *          1
 *       /     \
 *      2       3
 *    /   \    /  \
 *   4     5  6    7
 *   前序遍历: 1 2 4 5 3 6 7
 */

bool hasSubtreeCore(TreeNode *A, TreeNode *B){
    // 判断树B, 是否为树A的子树
    if(A==NULL && B!=NULL)
        return false;
    if(A!=NULL && B==NULL)
        return false;
    if(A==NULL && B==NULL)
        return true;
    if(A->val == B->val){
        return (hasSubtreeCore(A->left,B->left) && hasSubtreeCore(A->right,B->right));
    }else{
        return false;
    }
}
bool hasSubtree(TreeNode *A, TreeNode *B){
    bool result = false;
    if(A!=NULL){
        cout<<A->val<<" ";
        //if(hasSubtreeCore(A,B)==true);
        if(hasSubtreeCore(A,B)==true)
            result = true;               // 1修改result为true
    }
    if(A->left!=NULL){
        result = hasSubtree(A->left, B); // 可能在这里重新被修改为false
    }
    if(A->right!=NULL){
        result = hasSubtree(A->right,B);
    }
    return result;
}
bool hasSubtreeRecursive(TreeNode *A, TreeNode *B){
    bool result = false;
    if(A!=NULL){
        cout<<A->val<<" ";
        //if(hasSubtreeCore(A,B)==true);
        result = hasSubtreeCore(A,B);
    }
    if(A->left!=NULL && result==false){
        result = hasSubtreeRecursive(A->left, B);
    }
    if(A->right!=NULL && result==false){
        result = hasSubtreeRecursive(A->right,B);
    }
    return result;
}
int main(int argc, char * argv []){
    TreeNode * A = new TreeNode(1);
    A->left      = new TreeNode(2);
    A->right     = new TreeNode(3);
    A->left->left   = new TreeNode(4);
    A->left->right  = new TreeNode(5);
    A->right->left  = new TreeNode(6);
    A->right->right = new TreeNode(7);
    TreeNode * B = new TreeNode(3);
    B->left      = new TreeNode(6);
    B->right     = new TreeNode(7);

    if(hasSubtreeIterative(A,B)==true)
        cout<<"  A中包含B的子树"<<endl;
    else
        cout<<"A中不包含B的子树"<<endl;
    if(hasSubtreeRecursive(A,B)==true)
        cout<<"  A中包含B的子树"<<endl;
    else
        cout<<"A中不包含B的子树"<<endl;

    if(hasSubtree(A,B)==true)
        cout<<"  A中包含B的子树"<<endl;
    else
        cout<<"A中不包含B的子树"<<endl;
    return 0;
}
