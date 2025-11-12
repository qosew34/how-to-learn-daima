#include <bits/stdc++.h>
using namespace std;

struct Node {
    int winner; // 存储该子树的胜者编号（1-based）
    Node *l, *r;
    Node(int w): winner(w), l(nullptr), r(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;      // 题目格式：第一行给 n（n <= 7）
    int m = 1 << n;                 // 参赛队伍数为 2^n

    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i) cin >> a[i]; // 接下来 m 个能力值，按编号 1..m

    // 特判：只有 1 支队伍时（n==0 的情况）
    if (m == 1) {
        cout << 1 << '\n';
        return 0;
    }

    // 叶节点：每个选手对应一个节点，winner 初始化为该选手编号
    vector<Node*> cur;
    cur.reserve(m);
    vector<Node*> all_nodes; all_nodes.reserve(2*m); // 用于最后释放内存
    for (int i = 1; i <= m; ++i) {
        Node* leaf = new Node(i);
        cur.push_back(leaf);
        all_nodes.push_back(leaf);
    }

    // 自底向上合并为比赛树
    while (cur.size() > 1) {
        vector<Node*> nxt;
        nxt.reserve(cur.size() / 2);
        for (size_t i = 0; i + 1 < cur.size(); i += 2) {
            Node* left = cur[i];
            Node* right = cur[i+1];
            int win = (a[left->winner] > a[right->winner]) ? left->winner : right->winner;
            Node* parent = new Node(win);
            parent->l = left;
            parent->r = right;
            nxt.push_back(parent);
            all_nodes.push_back(parent);
        }
        cur.swap(nxt);
    }

    Node* root = cur[0];
    // 决赛双方分别是 root->l->winner 与 root->r->winner
    int leftWinner = root->l->winner;
    int rightWinner = root->r->winner;
    int runner_up = (a[leftWinner] > a[rightWinner]) ? rightWinner : leftWinner;
    cout << runner_up << '\n';

    // 释放内存（竞赛场合可略，但这里展示完整性）
    for (Node* p : all_nodes) delete p;

    return 0;
}
/*ll arr[100010]={0},tree[500050]={0};  //arr为存储数据的数组，tree是存线段树的数组
void build(int node,int start,int end){   //建树函数，参数是根节点和左右区间 
	if(start==end){		//如果两边相等 
		tree[node]=arr[start]; //填的就是数组里的初始值 
		return;  //递归边界 
	}
	int leftnode=node*2;  //算出左右节点（完全二叉树的性质） 
	int rightnode=node*2+1;  
	int mid=(start+end)/2;    //把数组从中间劈成两半
	build(leftnode,start,mid);  //左边右边分开建树 
	build(rightnode,mid+1,end);
	tree[node]=tree[leftnode]+tree[rightnode]; //根节点的值=左根+右根 
} 
洛谷的线段树    
*/