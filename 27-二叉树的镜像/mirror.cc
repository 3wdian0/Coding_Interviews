#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode * root){
	if(root!=NULL){
		cout<<root->val<<endl;
		if(root->left){
			preorderTraversal(root->left);
		}
		if(root->right){
			preorderTraversal(root->right);
		}
	}
}

void levelOrderTraversal(TreeNode * root){
	/*
	 * 算法思路
	 *
	 *
	 */
	queue<TreeNode*> q1,q2;
	if(root==NULL){
		cout<<"node空"<<endl;
		return;
	}else{
		q1.push(root);
	}
	while(!q1.empty())
	{
		cout<<q1.front()->val<<" ";
		if(q1.front()->left!=NULL){
			q2.push(q1.front()->left);
		}
		if(q1.front()->right!=NULL){
			q2.push(q1.front()->right);
		}
		q1.pop();
		if(q1.empty()){
			cout<<endl;
			queue<TreeNode*> t = q1;
			q1 = q2;
			q2 = t;
		}

	}


}

void mirrorRecursively(TreeNode *root){
	/* 算法思路
	 *
	 *      1                   1                   1
	 *    /   \               /   \               /   \
	 *   2     3     -->     3     2     -->     3     2
	 *  / \   / \           / \   / \           / \   / \
	 * 4   5 6             6     4   5             6 5   4
	 *
	 */
	if(root==NULL){
		return;
	}

	TreeNode * t;
	t = root->left;
	root->left = root->right;
	root->right = t;
	mirrorRecursively(root->left);
	mirrorRecursively(root->right);
}
int main(int argc, char * argv[]){
	TreeNode * root = new TreeNode(1);
	root->left      = new TreeNode(2);
	root->right     = new TreeNode(3);
	root->left->left      = new TreeNode(4);
	root->left->right     = new TreeNode(5);
	root->right->left     = new TreeNode(6);
	//root->right->right    = new TreeNode(7);
	//preorderTraversal(root);
	//TreeNode * root1;
	//levelOrderTraversal(root1);
	levelOrderTraversal(root);
	mirrorRecursively(root);
	levelOrderTraversal(root);
	return 0;
}
