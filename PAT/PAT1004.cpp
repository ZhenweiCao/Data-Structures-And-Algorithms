# include<iostream>
# include<queue>
# include<vector>
using namespace std;

// 题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184

const int MAX = 100;
typedef int ElemType;
// 孩子节点
typedef struct CTNode{
    int child_id;  // 孩子节点的下标
    CTNode * next_child;  // 下一个孩子节点
} * ChildPtr;

typedef struct{
    ElemType data;
    int parent_id;  
    ChildPtr first_child_node;
}CTBox;

typedef struct{
    CTBox nodes[MAX];  //结点数组
    int n;  // 结点数目
    void init(){
        for(int i = 0; i < MAX; i++){
            nodes[i].first_child_node = nullptr;
            nodes[i].data = -1;
            nodes[i].parent_id = -1;
        }
    }
    void show(){
        cout << "The tree has " << n << " nodes." << endl;
        for(int i = 0; i < MAX; i++){
            cout << "Node[" << i << "]    parent id:" <<  nodes[i].parent_id;
            ChildPtr Node = nodes[i].first_child_node;
            while(Node != nullptr){
                cout << "    child id:" << (*Node).child_id;
                Node = (*Node).next_child;
            }
            cout << endl;
        }
    }
} Tree;

int main(){
    int line_num;
    Tree tree;
    tree.init();
    cin >> tree.n >> line_num;
    for(int i = 1; i <= line_num; i++){
        int node_id, child_num;
        cin >> node_id >> child_num;
        tree.nodes[node_id].first_child_node = (ChildPtr)malloc(sizeof(ChildPtr));
        ChildPtr *child_ptr = &(tree.nodes[node_id].first_child_node);
        for(int j = 0; j < child_num; j++){
            int tmp_child_id;
            cin >> tmp_child_id;
            tree.nodes[tmp_child_id].parent_id = node_id;
            ChildPtr tmp_child_node = (ChildPtr)malloc(sizeof(ChildPtr));
            (*tmp_child_node).child_id = tmp_child_id;
            (*tmp_child_node).next_child = nullptr;
            (*child_ptr) = tmp_child_node;
            child_ptr = &((**child_ptr).next_child);
        }
    }
    //tree.show();
    
    // 使用两个队列，每次存储一层的子节点，采用BFS进行遍历
    queue<int> q;
    q.push(1);
    vector<int> v;
    while(!q.empty()){
        queue<int> tmp;
        int count = 0;
        while(!q.empty()){        
            int t = q.front();
            tmp.push(t);
            q.pop();
        }
        while(!tmp.empty()){
            int t = tmp.front();
            tmp.pop();
            if(tree.nodes[t].first_child_node != nullptr){
                ChildPtr tmpchild = tree.nodes[t].first_child_node;
                while(tmpchild != nullptr){
                    q.push((*tmpchild).child_id);
                    tmpchild = (*tmpchild).next_child;
                }
            }else{
                count ++;  // 如果没有子节点
            }
        }
        v.push_back(count);
    }
    for(int i = 0; i < v.size(); i++){
        if(i == 0){
            cout << v[i];
        }
        else{
            cout << " " << v[i];
        }
    }
    for(int i = 1; i < tree.n; i++){
        ;  // 需要释放内存
    }
    return 0;
}
