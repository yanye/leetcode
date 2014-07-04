/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  /******************************************/
 /*
 思路：
 中序遍历顺序是左根右。所以对每个节点，首先找到最左的节点，然后将其入栈，一直找到它最最最左节点。
 在这个过程中，要一直入栈。最后我们到了最左节点，可以将其输出，然后转到其右节点。一直重复上述过程即可
 */
 /*****************************************/
class Solution {
public:
	//判断节点是否为空，是则返回true，否则返回false
    bool isNodeNull(TreeNode *node){
        if(node==NULL || node->val=='#'){
            return true;
        }else{
            return false;
        }
    }
	//判断左孩子是否为空，是则返回true，否则返回false
    bool isLeftNull(TreeNode *node){
        if(node->left==NULL || node->left->val=='#'){
            return true;
        }else{
            return false;
        }
    }
	//判断右孩子是否为空，是则返回true，否则返回false
    bool isRightNull(TreeNode *node){
        if(node->right==NULL || node->right->val=='#'){
            return true;
        }else{
            return false;
        }
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inResult;
        if(isNodeNull(root)) return inResult;
        TreeNode *visit=root;
        stack<TreeNode*> nodeStack;
        while(visit!=NULL || !nodeStack.empty()){
            while(!isNodeNull(visit)){//一直找到最左节点
                nodeStack.push(visit);
                visit=visit->left;
            }
            
            if(!nodeStack.empty()){
                visit=nodeStack.top();
                inResult.push_back(visit->val);//对最左节点输出
                visit=visit->right;//转到右节点
                nodeStack.pop();
            }
        }
        return inResult;
    }
};