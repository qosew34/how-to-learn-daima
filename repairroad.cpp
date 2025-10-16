/*         2024年，Y市和N市之间的一条道路出现了重大问题导致全线瘫痪，急需抢修，现在这个重任交给了小佳和小慧。
         已知Y市和N市的损毁道路长度为n，本身可视为[0,n]（包含两个端点）这段笔直的线段，现在小佳和小慧正处在这条路上的某个位置（可能相同也可能不在同一个位置），两个人的修路速度分别为vj​和vh​，而这项任务的进行由你决定，你可以让她们任意时刻开工，随时随地往某个方向进行道路的抢修工作，两个人在任何时刻都能转换方向，当然，让她们脱离[0,n]这段路是不合法的，工作方向的转换操作时间可以忽略不计。
        道路抢修结束的标志是路上的任何一个位置都被至少一个人修过，请你求出抢修结束的最短时间。*/
#include <bits/stdc++.h>
using namespace std;
double n;
double repair(double vl,double vr,double locr,double locl){
    vector<double> psb={};
    if((locr+locl)*(vr+vl)>=vl*(locl-locr+2*n)&&vl*(locl-locr+2*n)>=2*locl*(vl+vr)) psb.push_back((locr-locl+n)/(vr+vl));
    if((2*locr-locl)*(vl+vr)>=(2*n-locr+locl)*vl&&(2*n-locr+locl)*vl>=locl*(vl+vr)) psb.push_back((2*n-locr+locl)/(vl+vr));
    if((locr-locl)*(2*vl+vr)>=(n+2*locl+locr)*vl&&(n+2*locl+locr)*vl>=2*locl*(2*vl+vr)) psb.push_back((locr+n+2*locl)/(2*vl+vr));
    if((2*n-locr-locl)*(vl+2*vr)>=(4*n-2*locr-locl)*vr&&(4*n-2*locr-locl)*vr>=(2*n-2*locr)*(vl+2*vr)) psb.push_back((4*n-2*locr-locl)/(vl+2*vr));
    if(locr==locl) psb.push_back(max(min(locl,n-locl)/min(vl,vr),max(locl,n-locl)/max(vl,vr)));
    if(locr==locl) psb.push_back(n+min(n-locr,n)/max(vr,vl));
    psb.push_back(min((locl+n)/vl,(-locr+2*n)/vr));
    psb.push_back(min((2*n-locl)/vl,(locr+n)/vr));
    psb.push_back(max(locl/vl,min(2*n-locr-locl,locr-2*locl+n)/vr));
    psb.push_back(max((n-locr)/vr,min(locr+locl,2*locr-locl)/vl));
    psb.push_back(max(max((locl)/vl,(n-locl)/vr),max((locr)/vr,(n-locr)/vl)));
    psb.push_back((max(max((n-locl)/vl,(locl)/vr),max((n-locr)/vr,(locr)/vl))));
    sort(psb.begin(),psb.end());
    return (psb[0]);
}



int main(){
    int cishu;
    cin>>cishu;
    for(int ooo=0;ooo<cishu;ooo++){
    double vr,vl,locr,locl;
    double j,vj,h,vh;
    cin>>n>>j>>vj>>h>>vh;
    if(j>h){
        locr=j;vr=vj;
        locl=h;vl=vh;
    }
    else{
        locr=h;vr=vh;
        locl=j;vl=vj;
    }
    cout<<fixed<<setprecision(5)<<repair(vl,vr,locr,locl)<<endl;
}
}
/*未考虑单人覆盖整个道路的情况：你的代码只计算了两人分区合作的时间，但忽略了其中一人单独覆盖 [0, n] 的时间（另一人不动）。在某些情况下（如两人位置相近且速度差异大），单人覆盖可能更快。你需要计算两个单人时间，并与合作时间取 min。
相同位置未处理：当 J == H 时，你的代码固定分配 vl = vj（左人），vr = vh（右人），计算 max(J / vj, (n - J) / vh)。但此时两人位置相同，可以交换角色（让更快的人覆盖更长的一侧），需要计算两种分配并取 min。
位置可能超出 [0, n]：输入允许 0 ≤ J, H ≤ 10000，而 n ≤ 10000，两人可能起始在路外（<0 或 >n）。问题规定“脱离 [0, n] 不合法”，所以应将位置 clamp 到 [0, n] 内（例如，起始在 0 或 n）。
代数计算错误：四个 if 条件和 push_back 的表达式似乎是试图解析 tL(m) = tR(m) 的不同分段情况（tL 和 tR 是分段线性函数，有 4 种组合），但公式推导有误：

例如第一个 if 的条件 (locr+locl)*(vr+vl)>vl*(locl-locr+2*n) && ... 和 push (locr-locl+n)/(locr+locl) 不匹配标准解（详见下文方法）。这些不等式可能混淆了分段边界（d ≤ locl 和 e ≤ n-locr），导致候选值错误。
第五个 push_back 似乎想计算单人时间，但表达式 (locl+n)/vl 忽略了 min_dist 项（实际单人时间是 (n + min(pos, n-pos)) / v），且 (-locr+2*n)/vr 也不准确。
排序后取 psb[0] 假设是最小，但如果 if 条件未触发或计算错，psb 可能为空或错值，且未与单人时间比较。


未验证边界：未检查 m 是否在 [locl, locr] 内，未处理 delta = 0 的退化情况。
精度问题：浮点输入，但未处理 n=0 或 v=0（虽输入约束避免），且输出固定 5 位小数 ok，但计算中可能累积误差。*/
/*有小巧思，二分时间模拟是否可行*/
/*#include <bits/stdc++.h>
using namespace std;

bool can(double t, double n, double J, double vj, double H, double vh) {
    double dj = vj * t;
    double dh = vh * t;

    // Case 1: Jia covers 0, Hui covers n
    bool c1 = false;
    if (dj >= J) {
        double max_rj;
        if (dj <= 3 * J) {
            max_rj = (dj + J) / 2.0;
        } else {
            max_rj = dj - J;
        }
        max_rj = min(max_rj, n);
        double pp = n - H;
        if (dh >= pp) {
            double max_rp;
            if (dh <= 3 * pp) {
                max_rp = (dh + pp) / 2.0;
            } else {
                max_rp = dh - pp;
            }
            max_rp = min(max_rp, n);
            double min_lh = n - max_rp;
            if (max_rj >= min_lh) c1 = true;
        }
    }

    // Case 4: Hui covers 0, Jia covers n
    bool c4 = false;
    if (dh >= H) {
        double max_rh;
        if (dh <= 3 * H) {
            max_rh = (dh + H) / 2.0;
        } else {
            max_rh = dh - H;
        }
        max_rh = min(max_rh, n);
        double ppj = n - J;
        if (dj >= ppj) {
            double max_rpj;
            if (dj <= 3 * ppj) {
                max_rpj = (dj + ppj) / 2.0;
            } else {
                max_rpj = dj - ppj;
            }
            max_rpj = min(max_rpj, n);
            double min_lj = n - max_rpj;
            if (max_rh >= min_lj) c4 = true;
        }
    }

    // Case 2: Jia covers whole [0,n]
    bool c2 = (dj >= n + min(J, n - J));

    // Case 3: Hui covers whole [0,n]
    bool c3 = (dh >= n + min(H, n - H));

    return c1 || c2 || c3 || c4;
}

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        double n, J, vj, H, vh;
        cin >> n >> J >> vj >> H >> vh;
        double low = 0.0;
        double high = 1e8;
        for (int iter = 0; iter < 200; iter++) {
            double mid = (low + high) / 2.0;
            if (can(mid, n, J, vj, H, vh)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        printf("%.5f\n", low);
    }
    return 0;
}*/