#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

// 题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336


int main(){

    // 建立一个数字到英语单词的映射
    map <int, string> m;
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < 10; i++){
        m.insert(pair<int, string>(i, s[i]));
    }
    
    char a[120] = {'0'};
    int count = 0;
    cin >> a;
    
    // 计算各个位数之和
    for(int i = 0; a[i] != '\0'; i++){
        count += a[i] - '0';
    }

    // 计算和用科学计数法表示的指数： 1.xxx * 10^exp
    int exp = -1;  
    int tmp = count;
    while(tmp != 0){
        tmp = tmp / 10;
        exp++;
    }
    if(count == 0){
        cout << "zero";  // 如果输入是0的话，前面的均不适用，在此仅输出"zero"即可
    }
    else{
        for(int i = 0; i <= exp; i++){
            tmp = (count / int(pow(10, (exp-i)))) % 10;
            if(i == 0){
             cout << m[tmp];
            }
            else{
                cout << " " << m[tmp];
            }
        }
    } 
    return 0;
}
