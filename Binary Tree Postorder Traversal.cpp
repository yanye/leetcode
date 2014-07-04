/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**************************/
 /*
 思路： 
 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
 如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
 若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问
 */
  /**************************/
class Solution {
public:
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
	//后序遍历
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postResult;
        if(root==NULL || root->val=='#') return postResult;//易错点，因为函数返回类型是vector<int>，所以不能返回NULL
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* preVisit=root;
        TreeNode* visit=root;
        while(!nodeStack.empty()){//栈不为空则继续遍历
            visit=nodeStack.top();
			//首先判断了左孩子和右孩子是否为空，若都为空，则可以输出当前节点；
			//否则判断右（左）孩子不为空且和previsit相等，说明其孩子节点都已经被访问过了，也可直接输出当前节点
            if( (isLeftNull(visit) && isRightNull(visit)) || ((!isRightNull(visit)) && preVisit==visit->right) || ((!isLeftNull(visit)) && preVisit==visit->left )){
                postResult.push_back(visit->val);   
                preVisit=visit;
                nodeStack.pop();
            }else{//不满足以上条件，则说明其还有孩子节点未访问，不能立刻输出。
                if(!isRightNull(visit)){//先将右节点入栈。
                    nodeStack.push(visit->right);
                }
                if(!isLeftNull(visit)){//再将左节点入栈。
                    nodeStack.push(visit->left);
                }
            }
        }
        return postResult;
    }
};