# include<iostream>
# include<vector>

// 题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
using namespace std;

const int MAX = 100;
vector<int> tree[MAX];
int nodes_num;  // 结点数目
int non_leaf_num;  // 非叶子节点数目
int max_level;  // 树的层数
int leaf_num[MAX] = {0};  //每层的叶子节点数

void dfs(int level, int id){
    if(tree[id].size() == 0){
        leaf_num[level]++;
        max_level = max_level > level ? max_level : level;
        return;
    }
    else{
        for(int i = 0; i < tree[id].size(); i++){
            dfs(level+1, tree[id][i]);
        }
    }
}

int main(){
    cin >> nodes_num >> non_leaf_num;
    for(int i = 0; i < non_leaf_num; i++){
        int node_id, child_num;
        cin >> node_id >> child_num;
        for(int j = 0; j < child_num; j ++){
            int tmp;  // 孩子节点的编号
            cin >> tmp;
            tree[node_id].push_back(tmp);  
        }
    }
    dfs(0, 1);  // 根节点从1开始
    for(int i = 0; i <= max_level; i++){
        if(i == 0){
            cout << leaf_num[i];
        }
        else{
            cout << " " << leaf_num[i];
        }
    }
    return 0;
}
