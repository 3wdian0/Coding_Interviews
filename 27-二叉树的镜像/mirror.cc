#include<iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode * root){
	if(root!=NULL){
		if(root->left)
			inorderTraversal(root->left);
		cout<<root->val<<endl;
		if(root->right)
			inorderTraversal(root->right);
	}
}

int main(int argc, char * argv[]){
	TreeNode * root = new TreeNode(1);
	root->left      = new TreeNode(2);
	root->right     = new TreeNode(3);
	inorderTraversal(root);
	return 0;
}
