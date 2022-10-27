/*定义
二叉搜索树又称为二叉排序树，它或者是一棵空树，或者是具有以下性质的二叉树：

若它的左子树不为空，则左子树上所有结点的值都小于根结点的值。
若它的右子树不为空，则右子树上所有结点的值都大于根结点的值。
它的左右子树也分别是二叉搜索树。*/

struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
}TreeNode;

//升序数组
int* ascending order(int *nums, int numsSize){
  int *ans = nums;
  for(int i=0; i<numsSize; i++){
    if(nums[i] > nums[i + 1]){
      int temp = nums[i];
      nums[i] = nums[i + 1];
      nums[i+1] = temp;
    }
  }
  return ans;
}

struct TreeNode* searchTree(int *nums, int right, int left){
    if(left > right){
      return NULL;
    }
   //得是升序数组
   int mid = (right + left) / 2;
   TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
   root->left = searchTree(nums, left, mid - 1);
   root->right = secrchTree(nums, mid + 1, right);
   return root;
}
