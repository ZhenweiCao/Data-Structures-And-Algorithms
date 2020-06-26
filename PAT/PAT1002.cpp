#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

//题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000

typedef struct poly{
    unsigned exp;
    float coef;
}item;

void scan(item *a, int n){
    for (int i = 0; i < n; i++){
        cin >> (a+i)->exp;
        cin >> (a+i)->coef;
    }
}

void combine(item *a, int num1, item *b, int num2){
    item result[23];
    int i = 0, j = 0, k = 0;  // i, j分别用来扫描a和b，k用来扫描result
    while(i < num1 && j < num2){
        if((a+i)->exp > (b+j)->exp){  // 如果a[i]的指数大于b[j]的指数
            (result + k)->exp = (a + i)->exp;
            (result + k)->coef = (a + i)->coef;
            i++;
            k++;
        }else if((a+i)->exp < (b+j)->exp){  // 如果a[i]的指数小于b[j]的指数
            (result + k)->exp = (b + j)->exp;
            (result + k)->coef = (b + j)->coef;
            k++;
            j++;
        }else {  // 指数相等时把系数相加
            if((b + j)->coef + (a + i)->coef != 0){
                (result + k)->exp = (b + j)->exp;
                (result + k)->coef = (b + j)->coef + (a + i)->coef;
                k++;
            }
            i++;
            j++;
        }
    }
    while(i < num1){
        (result + k)->exp = (a + i)->exp;
        (result + k)->coef = (a + i)->coef;
        i++;
        k++;
    }
    while(j < num2){
        (result + k)->exp = (b + j)->exp;
        (result + k)->coef = (b + j)->coef;
        j++;
        k++;
    }
    cout << k;
    for (int t = 0; t < k; t++){  // k为生成result的长度
        cout << " " << (result + t)->exp << " ";
        printf("%.1f", (result + t)->coef);  
    }
    cout << endl;
}

int main(){
    item a[12], b[12];
    int num1, num2;
    while(cin >> num1){
        scan(a, num1);
        cin >> num2;
        scan(b, num2);
        combine(a, num1, b, num2);
    }
    system("pause");
    return 0;
}
