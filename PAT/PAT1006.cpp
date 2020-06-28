#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//题目链接：https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928

typedef struct MyTime{
    unsigned hh;
    unsigned mm;
    unsigned ss;
    void init(string s){
        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 2);
        string s3 = s.substr(6, 2);
        hh = stoul(s1, 0, 10);
        mm = stoul(s2, 0, 10);
        ss = stoul(s3, 0, 10);
    }
}my_time;

typedef struct Record{
    my_time sign_in_time;
    my_time sign_out_time;
    string id;
    void init(string s1, string s2, string s3){
        id = s1;
        sign_in_time.init(s2);
        sign_out_time.init(s3);
    }
}record;

bool cmp(my_time t1, my_time t2){  
    // 比较函数，用来比较两个时间的早晚，按时间从小到大
    if(t1.hh < t2.hh){
        return true;
    }
    else if(t1.hh == t2.hh){
        if(t1.mm < t2.mm){
            return true;
        }
        else if(t1.mm == t2.mm){
            if(t1.ss < t2.ss){
                return true;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool cmp_1(record r1, record r2){  
    // 比较函数，用来找到最早的sign_in_time，按进入时间从早到晚排序
    return cmp(r1.sign_in_time, r2.sign_in_time);
}

bool cmp_2(record r1, record r2){
    //比较函数，用来找到最晚的sign_out_time，按时间从晚到早排序
    return !cmp(r1.sign_out_time, r2.sign_out_time);
}
int main(){
    vector<record> records;
    int lines;
    cin >> lines;
    for(int i = 0; i < lines; i++){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        record r;
        r.init(s1, s2, s3);
        records.push_back(r);
    }
    vector<record>::iterator it_begin = records.begin();
    vector<record>::iterator it_end = records.end();
    sort(it_begin, it_end, cmp_1);
    cout << records[0].id << " ";
    sort(it_begin, it_end, cmp_2);
    cout << records[0].id;
    return 0;
}
