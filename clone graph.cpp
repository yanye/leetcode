/************************************************************************/
/* 
˼·��
��ȡ������ȱ�����˼�룺��ÿ���ڵ㣬�鿴���ھӽڵ㣬���������ˣ��������neighbors��
��û�б����ʣ�������Ҫnewһ���½ڵ㣬Ȼ���ٽ���Ӧ��neighbor��ϵ�Ժã����������δ���ʶ����С�
������鷳�Ǻ����׳�ʱ��������ô�жϽڵ��Ƿ����Ҫ������Ч�ķ�ʽ��������õ���map�ķ�ʽ����ʾ�ڵ��Ƿ񱻷��ʹ�
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
        
        map<UndirectedGraphNode*,UndirectedGraphNode*> nodeMap;//����map�����ݽṹ���ֽڵ��Ƿ񱻷��ʹ���map<oldnode,newnode>����������ʹ���map[oldnode]Ӧ����ֵ
        
        deque<UndirectedGraphNode*> nodeQueue;//������ȱ������ö��еķ�ʽ����ʾδ���ʽڵ�Ķ���
        nodeQueue.push_back(node);
        
        while(!nodeQueue.empty()){
            UndirectedGraphNode* tmpNode=nodeQueue.front();//ȡ����ͷ���
            nodeQueue.pop_front();
            
            if(!nodeMap.count(tmpNode)){//����count�ķ�ʽ���жϽڵ��Ƿ񱻷��ʹ�����map��find����Ҫ��
                UndirectedGraphNode* newNode= new UndirectedGraphNode(tmpNode->label);//δ�����ʹ������½�һ���ڵ㣬���Ҹ���map
                nodeMap[tmpNode]=newNode;
            }
            for(int i=0;i<tmpNode->neighbors.size();i++){//������neighbor
                UndirectedGraphNode* tmpNeiNode=tmpNode->neighbors[i];
                if(!nodeMap.count(tmpNeiNode)){
                    UndirectedGraphNode* tmpNewNode=new UndirectedGraphNode(tmpNeiNode->label);
                    nodeMap[tmpNeiNode]=tmpNewNode;
                    nodeQueue.push_back(tmpNeiNode);
                }
                nodeMap[tmpNode]->neighbors.push_back(nodeMap[tmpNeiNode]);//ע���µ�ͼ�У�ÿ��neighborsҪָ���½ڵ�
            }
            
        }
        return nodeMap[node];
    }
};