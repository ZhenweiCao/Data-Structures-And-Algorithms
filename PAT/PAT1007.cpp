#include <iostream>

using namespace std;

// 题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168

const int MAX = 10010;

// 采用分治策略求解最大和子串
int max_subseq(int a[], int result[], int i, int j){  // 通过传入的result数组，来同时获取左右下标和子序列之和
    if(i >= j){  // 如果i==j，说明在查找范围内只有一个数，那么最大之就是这个数
        result[0] = i;
        result[1] = i;
        result[2] = a[i];  
        return a[i];
    }
    int result_1[3] = {0};  // 递归时传入的参数
    int result_2[3] = {0};
    int mid = (i + j) / 2;
    int tmp3[3] = {mid, mid, a[mid]};
    int sum = a[mid];
    for(int t = mid + 1; t <= j; t++){  // 从中间向下标增大的方向开始寻找
        if(sum + a[t] > tmp3[2]){  // 题目要求，当有两个和相同的子序列时，输出最小的i和j，因此在这里当大于临时的最大max时，才更新max
            sum = sum + a[t];
            tmp3[2] = sum;
            tmp3[1] = t;
        }
        else{
            sum = sum + a[t];
        }
    }
    sum = tmp3[2];
    for(int t = mid - 1; t >= i; t--){
        if(sum + a[t] > tmp3[2]){
            sum = sum + a[t];
            tmp3[2] = sum;
            tmp3[0] = t;
        }
        else{
            sum = sum + a[t];
        }
    }
    int tmp1, tmp2;  // 保存左右两个子序列递归得到的子序列最大和
    tmp1 = max_subseq(a, result_1, i, mid-1);
    tmp2 = max_subseq(a, result_2, mid+1, j);
    if(tmp1 >= tmp2 && tmp1 >= tmp3[2]){
        // 左侧的和最大时
        result[0] = result_1[0];
        result[1] = result_1[1];
        result[2] = result_1[2];
        return tmp1;  
    }
    else if(tmp3[2] > tmp1 && tmp3[2] >= tmp2){  
        // 当包含中间点的和最大时
        result[0] = tmp3[0];
        result[1] = tmp3[1];
        result[2] = tmp3[2];
        return tmp3[2];
    }
    else{  
        // 右侧的和最大时
        result[0] = result_2[0];
        result[1] = result_2[1];
        result[2] = result_2[2];
        return tmp2;  
    }
}

int main(){
    int num;
    int data[MAX] = {0};
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> data[i];
    }
    bool all_neg = true;
    for(int i = 0; i < num; i++){  // 注意序列中出现为0的情况
        if(data[i] >= 0) all_neg = false;
    }
    if(all_neg){
        cout << 0 << " " << data[0] << " " << data[num-1];
        return 0;
    }
    int result[3] = {0};
    int m = max_subseq(data, result, 0, num-1);
    cout << result[2] << " " << data[result[0]] << " " << data[result[1]];
    return 0;
}
