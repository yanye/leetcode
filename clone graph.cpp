/************************************************************************/
/* 
思路：
采取广度优先遍历的思想：对每个节点，查看其邻居节点，若被访问了，则将其加入neighbors，
若没有被访问，则首先要new一个新节点，然后再将对应的neighbor关系对好，并将其加入未访问队列中。
此题的麻烦是很容易超时，所以怎么判断节点是否访问要采用有效的方式，这里采用的是map的方式来表示节点是否被访问过
*/
/************************************************************************/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        
        map<UndirectedGraphNode*,UndirectedGraphNode*> nodeMap;//采用map的数据结构保持节点是否被访问过，map<oldnode,newnode>，如果被访问过，map[oldnode]应该有值
        
        deque<UndirectedGraphNode*> nodeQueue;//广度优先遍历采用队列的方式，表示未访问节点的队列
        nodeQueue.push_back(node);
        
        while(!nodeQueue.empty()){
            UndirectedGraphNode* tmpNode=nodeQueue.front();//取队列头结点
            nodeQueue.pop_front();
            
            if(!nodeMap.count(tmpNode)){//采用count的方式来判断节点是否被访问过，比map的find方法要快
                UndirectedGraphNode* newNode= new UndirectedGraphNode(tmpNode->label);//未被访问过，则新建一个节点，并且更新map
                nodeMap[tmpNode]=newNode;
            }
            for(int i=0;i<tmpNode->neighbors.size();i++){//复制其neighbor
                UndirectedGraphNode* tmpNeiNode=tmpNode->neighbors[i];
                if(!nodeMap.count(tmpNeiNode)){
                    UndirectedGraphNode* tmpNewNode=new UndirectedGraphNode(tmpNeiNode->label);
                    nodeMap[tmpNeiNode]=tmpNewNode;
                    nodeQueue.push_back(tmpNeiNode);
                }
                nodeMap[tmpNode]->neighbors.push_back(nodeMap[tmpNeiNode]);//注意新的图中，每个neighbors要指向新节点
            }
            
        }
        return nodeMap[node];
    }
};