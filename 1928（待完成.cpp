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
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<string> stk;  // 只存父字符串
    string current = "";  // 当前字符串
    int num = 0;  // 当前重复数
    for (char c : s) {
        if (c == '[') {
            stk.push(current);  // 压入父层字符串
            current = "";
            num = 0;  // 为本层准备解析数字
        } else if (c == ']') {
            string parent = stk.top();
            stk.pop();
            // 默认重复1次
            if (num == 0) num = 1;
            // 重复当前字符串
            string repeated;
            repeated.reserve(num * current.size());  // 预分配优化
            for (int i = 0; i < num; ++i) {
                repeated += current;
            }
            current = parent + repeated;  // 合并到当前
        } else if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else {
            current += c;
        }
    }
    cout << current << endl;  // 最外层即current
    return 0;
}