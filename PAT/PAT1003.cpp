#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376

struct EdgeNode{  // 用邻接表表示的图的一个边
    int to, w;  // 顶点序号和边长
};

void emergency(int city_num, int road_num, int current_in, int must_save);
const int MAX = 501;
const int INF = 999999999;
int main(){
    int city_num, road_num, current_in, must_save;
    
    while(cin >> city_num >> road_num >> current_in >> must_save){
        emergency(city_num, road_num, current_in, must_save);
    }
    return 0;
}

void emergency(int city_num, int road_num, int current_in, int must_save){  // 采用Dijkstra算法
    vector<EdgeNode> map[MAX];  // 采用邻接表存储这张图
    int team_num[MAX] = {0};  // 每个城市的救援队数量
    int mask[MAX] = {0};  // 标记每个节点是否被选中，初始时只有current_in被选中
    int path[MAX] = {0};  // path[i]表示到i节点的最短路径上，i的前驱节点
    int rescue_num[MAX] = {0};  // rescue_num[i]表示从源节点current_in到i经过最短路径的最大救援队数目，初始将current_in位置处的设置为初始城市的救援队数目
    int result[2] = {0};  // result[0]表示最短路径的数目，result[1]表示能携带的最大救援队数目
    int path_num[MAX] = {0};  // path_num[i]表示从current_in到节点i最短路径的数目
    int dist[MAX];  //dist[i]表示从current_in节点到i节点的最短路径长度，初始设为INF 
    for (int i = 0; i < MAX; i++){
        dist[i] = INF;
    }
    dist[current_in] = 0;
    for (int i = 0; i < city_num; i++){
        cin >> team_num[i];
    }
    rescue_num[current_in] = team_num[current_in];  // 设置起始城市救援队数目
    path_num[current_in] = 1;
    for (int i = 0; i < road_num; i++){  // 录入边的信息
        EdgeNode e1, e2;
        int start, end;
        cin >> start >> end >> e1.w;
        e1.to = end;
        map[start].push_back(e1);
        e2.to = start;
        e2.w = e1.w;
        map[end].push_back(e2);
    }
    // 在录入节点信息之后，采用Dijkstra算法求解
    /*
    输入：用邻接表表示的图(vector<EdgeNode> map[MAX])，每个节点存储的救援队数目(team_num[MAX])
    输出：rescue_num[MAX]; dist[MAX]; path_sum[MAX]
    算法描述：1.for i=1 to n:
             2.    找到未被标记的，到达距离最短的节点（即mask[i]==0且dist[i]为最小），当未找到满足条件的节点时返回
             3.    查找与该节点相连的节点，根据距离和救援队数目，更新rescue_num和dist和path_sum
    */
    for (int i = 0; i < city_num; i++){
        int u = -1;
        int min = INF;  // 寻找与选中点相邻的最小的边，以及这条边所指向的节点
        for (int j = 0; j < city_num; j++){
            if(!mask[j] && dist[j]<min){
                u = j;
                min = dist[j];
            }
        }
        mask[u] = 1;
        //cout << "u: " << u;
        if(u == -1)
            break;
        for (int j = 0; j < map[u].size(); j++){
            int id = map[u][j].to;
            if(!mask[id] && dist[id]>dist[u]+map[u][j].w){
                dist[id] = dist[u] + map[u][j].w;
                rescue_num[id] = rescue_num[u] + team_num[id];
                path_num[id] = path_num[u];
            }
            else if(!mask[id] && dist[id]==dist[u]+map[u][j].w){  // 注意这里是携带多条最短路径上的救援队
                rescue_num[id] = rescue_num[u] + team_num[id] >= rescue_num[id] ? rescue_num[u] + team_num[id] : rescue_num[id];
                path_num[id] += path_num[u];
            }
        }
        
    }

    result[0] = path_num[must_save];
    result[1] = rescue_num[must_save];
    cout << result[0] << " " << result[1];
}
