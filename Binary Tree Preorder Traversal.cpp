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
 前序遍历顺序是根左右。所以对每个节点，首先将其输出，然后将其入栈，一直找到它最最最左节点。
 在这个过程中，要一直输出加入栈。做完后，需要转到其右节点。然后一直重复上述过程即可
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preResult;
        if(root==NULL || root->val=='#') return preResult;
        stack<TreeNode*> nodeStack;
        TreeNode* visit=root;
        while(visit!=NULL || !nodeStack.empty()){//根节点不为空，并且栈不为空，则继续遍历
            while(!isNodeNull(visit)){//找到其最最最左节点
                preResult.push_back(visit->val);//输出左节点
                nodeStack.push(visit);//左节点入栈
                visit=visit->left;
            }
            //左节点全部入栈后，则转到其右节点
            if(!nodeStack.empty()){
                visit=nodeStack.top();//取栈顶元素
                visit=visit->right;//转到其右节点
                nodeStack.pop();//该栈顶元素及其左节点均被输出，而右节点已经保存了，所以删除该节点
            }
        }
        return preResult;
    }
};