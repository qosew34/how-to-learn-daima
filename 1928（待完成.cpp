/*#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    vector<vector<char>> temp(12,vector<char>());
    vector<int> much(12,0);//初始化！
    int cengshu=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            cengshu++;
        }
        else if(s[i]==']'){
// 将当前层整个内容重复 much 次，追加到父层
            for (int rep = 0; rep < much[cengshu]; rep++) {
                for (size_t j = 0; j < temp[cengshu].size(); j++) {
                    temp[cengshu - 1].push_back(temp[cengshu][j]);
                }
            }
            cengshu--;
        }
        else if(isdigit(s[i])){
            if(much[cengshu]==0){
                much[cengshu]=s[i]-'0';
            }
            else{
                much[cengshu]*=10;
                much[cengshu]+=s[i]-'0';
            }
        }
        else {
            temp[cengshu].push_back(s[i]);
        }
    }
    for(int l=0;l<temp[0].size();l++){
        cout<<temp[0][l];
    }
    cout<<endl;
    return 0;
}靠，怎么天天要优化时间和内存*/
#include <iostream>
#include <string>
using namespace std;

// 递归解码函数，p为引用参数，表示当前扫描的位置
string decode(const string& s, int& p) {
    string res;
    while (p < s.size()) {
        if (isdigit(s[p])) {
            // 解析数字
            int repeat = 0;
            while (p < s.size() && isdigit(s[p])) {
                repeat = repeat * 10 + (s[p] - '0');
                p++;
            }
            if (p < s.size() && s[p] == '[') {
                p++; // 跳过 '['
                string sub = decode(s, p);
                p++; // 跳过 ']'
                for (int i = 0; i < repeat; ++i) res += sub;
            }
        } else if (s[p] == ']') {
            return res;
        } else {
            res += s[p++];
        }
    }
    return res;
}

int main() {
    string input;
    cin >> input;
    int p = 0;
    cout << decode(input, p) << endl;
    return 0;
}