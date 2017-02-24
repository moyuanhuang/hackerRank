/*
 * Complete the function below.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createBST(vector < int > keys) {
	int cnt = 0;
	TreeNode *root = NULL;
	for(int k : keys){
		if(!root)
			root = new TreeNode(k);
		else
			insert(root, k, cnt);
		cout << cnt << endl;
	}
}

void insert(TreeNode* root, int k, int &cnt){
	++cnt;
	if(root->value > k){
		if(root->right)	insert(root->right, k, cnt);
		else	root->right = new TreeNode(k);
	}
	else{
		if(root->left)	insert(root->left, k, cnt);
		else	root->left = new TreeNode(k);
	}
	return;
}

