#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void levelOrderTraversal(TreeNode *root){
    if(root==NULL)
        return;
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
            cout<<endl;
            queue<TreeNode *> t = q2; q2 = q1; q1 = t;
        }
    }

}

bool isSymmetricalCore(TreeNode *root1, TreeNode * root2);

bool isSymmetrical(TreeNode *root){
    /*
     * 算法思路:
     * 1、前序遍历 : 根节点 左节点 右节点
     * 2、前序遍历': 根节点 右节点 左节点
     * 3、root1 root 2
     */
     return isSymmetricalCore(root,root);
}

bool isSymmetricalCore(TreeNode *root1, TreeNode *root2){
    if(root1==NULL and root2!=NULL)
        return false;
    if(root1!=NULL and root2==NULL)
        return false;
    if(root1==NULL and root2==NULL)
        return true;
    if(root1->val==root2->val and isSymmetricalCore(root1->left,root2->right))
        return true;

}
int main(int argc, char *argv[]) {
    TreeNode * root = new TreeNode(1);
    root->left      = new TreeNode(2);
    root->right     = new TreeNode(3);

    root->left->left= new TreeNode(4);
    root->left->right=new TreeNode(5);

    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    levelOrderTraversal(root);


    root->left       = new TreeNode(2); root->right       = new TreeNode(2);
    //root->left->left = new TreeNode(3); root->left->right = new TreeNode(4); root->right->left = new TreeNode(4);root->right->right = new TreeNode(3);
    root->left->left = NULL           ; root->left->right = new TreeNode(4); root->right->left = new TreeNode(4);root->right->right = NULL            ;
    levelOrderTraversal(root);
    cout<<isSymmetrical(root)<<endl;
    return 0;
}
