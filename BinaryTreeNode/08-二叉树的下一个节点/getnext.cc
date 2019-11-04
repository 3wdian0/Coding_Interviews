#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
    TreeNode(int x, TreeNode *p): val(x),left(NULL),right(NULL),parent(p){}
};
TreeNode * getNext(TreeNode *pNode);
void levelOrderTraversal(TreeNode * root){
    if(root==NULL)
        return;
    queue<TreeNode *> q1,q2,t;
    q1.push(root);
    while(!q1.empty()){
        cout<<q1.front()->val<<" ";
        if(q1.front()->left!=NULL)
            q2.push(q1.front()->left);
        if(q1.front()->right!=NULL)
            q2.push(q1.front()->right);
        q1.pop();
        if(q1.empty()){
            t = q1; q1 = q2; q2 = t;
            cout<<endl;
        }
    }
            
}

void inOrder(TreeNode *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
void inOrder2(TreeNode *root){
    if(root==NULL)
        return;
    inOrder2(root->left);
    if(getNext(root)!=NULL)
        cout<<root->val<<"->"<<getNext(root)->val<<"\t";
    else
        cout<<root->val<<"->没有下一个节点"<<endl;
    inOrder2(root->right);
}
/*
 * 中序遍历的下一个节点
 *         1
 *       /   \
 *      2     3
 *     / \   / \
 *    4   5 6   7
 *       / \
 *      8   9
 * 中序遍历：[4 2 8 5 9 1 6 3 7]
 * 
 *  * 中序遍历的下一个节点
 *         1
 *       /   \
 *      2     3
 *     / \   / \
 *    4   5 6   7
 *       / \
 *      8   9
 *     /     \
 *    10     11
 * 中序遍历：[4 2 10 8 5 9 11 1 6 3 7]
 * 如果输入7, 则下一个节点为空
 */

TreeNode * getNext(TreeNode *pNode){
    /*
     * BAD:
     * 算法思路(分类讨论)
     * 非叶子节点的下一个是，右子树的最左节点
     *                     , 无右子树
     * 叶子节点的下一个是，
     */

    /*
     * GOOD:
     * 算法思路
     * 有右子树，右子树的最左节点
     * 无右子树，向上找即可
     *
     */
    if(pNode->right!=NULL){
        pNode = pNode->right;
        while(pNode->left!=NULL){
            pNode = pNode->left;
        }
        return pNode;
    }else{
        TreeNode * pParent = pNode->parent;
        while(pParent!=NULL && pParent->left!=pNode){
            pParent = pParent->parent;
            pNode   = pNode->parent;
        }

        /*
        if(pParent==NULL){
            cout<<"中序遍历的最后一个节点"<<endl;
            return NULL;
        }
        else
            return pParent;
        */
        return pParent;
    }
}

int main(int argc, char * argv[]){
    TreeNode * root                 = new TreeNode(1,  NULL);        TreeNode * one = root;
    root->left                      = new TreeNode(2,  root);
    root->right                     = new TreeNode(3,  root);

    root->left->left                = new TreeNode(4,  root->left);
    root->left->right               = new TreeNode(5,  root->left);   TreeNode * five = root->left->right;

    root->right->left               = new TreeNode(6,  root->right);
    root->right->right              = new TreeNode(7,  root->right);

    root->left->right->left         = new TreeNode(8,  root->left->right);
    root->left->right->right        = new TreeNode(9,  root->left->right);

    root->left->right->left->left   = new TreeNode(10, root->left->right->left);
    root->left->right->right->right = new TreeNode(11, root->left->right->right); TreeNode * eleven = root->left->right->right->right;

    cout<<"层序遍历:"<<endl;levelOrderTraversal(root);

    // 测试用例
    cout<<getNext(five)->val<<endl;
    cout<<getNext(one)->val<<endl;
    cout<<getNext(eleven)->val<<endl;

    cout<<"\n中序遍历:"<<endl;inOrder(root);cout<<endl;
    cout<<"\n中序遍历:"<<endl;inOrder2(root);cout<<endl;
    return 0;
}
