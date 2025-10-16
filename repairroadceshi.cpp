#include <bits/stdc++.h>
using namespace std;

// 引入A代码函数（简化）
bool can(double t, double n, double J, double vj, double H, double vh) {
    double dj = vj * t;
    double dh = vh * t;

    bool c1 = false;
    if (dj >= J) {
        double max_rj = (dj <= 3 * J) ? (dj + J) / 2.0 : dj - J;
        max_rj = min(max_rj, n);
        double pp = n - H;
        if (dh >= pp) {
            double max_rp = (dh <= 3 * pp) ? (dh + pp) / 2.0 : dh - pp;
            max_rp = min(max_rp, n);
            double min_lh = n - max_rp;
            if (max_rj >= min_lh) c1 = true;
        }
    }

    bool c4 = false;
    if (dh >= H) {
        double max_rh = (dh <= 3 * H) ? (dh + H) / 2.0 : dh - H;
        max_rh = min(max_rh, n);
        double ppj = n - J;
        if (dj >= ppj) {
            double max_rpj = (dj <= 3 * ppj) ? (dj + ppj) / 2.0 : dj - ppj;
            max_rpj = min(max_rpj, n);
            double min_lj = n - max_rpj;
            if (max_rh >= min_lj) c4 = true;
        }
    }

    bool c2 = (dj >= n + min(J, n - J));
    bool c3 = (dh >= n + min(H, n - H));

    return c1 || c2 || c3 || c4;
}

double solveA(double n, double J, double vj, double H, double vh) {
    double low = 0, high = 1e8;
    for (int i = 0; i < 200; i++) {
        double mid = (low + high) / 2;
        if (can(mid, n, J, vj, H, vh)) high = mid;
        else low = mid;
    }
    return low;
}

// B代码的函数
double repair(double vl,double vr,double locr,double locl,double n){
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

double solveB(double n, double J, double vj, double H, double vh){
    double locr, locl, vr, vl;
    if(J>H){locr=J;vr=vj;locl=H;vl=vh;}
    else{locr=H;vr=vh;locl=J;vl=vj;}
    return repair(vl,vr,locr,locl,n);
}

int main() {
    srand(42);
    int N = 1000; // 测试1000组随机数据
    for(int i=0;i<N;i++){
        double n = rand()%100 + 10;
        double J = (rand()%1000)/10.0;
        double H = (rand()%1000)/10.0;
        J = min(J, n-1.0);
        H = min(H, n-1.0);
        double vj = (rand()%100)/10.0 + 0.1;
        double vh = (rand()%100)/10.0 + 0.1;
        double a = solveA(n,J,vj,H,vh);
        double b = solveB(n,J,vj,H,vh);
        if (fabs(a - b) > 1e-3) {
            cout << "Difference found!\n";
            cout << "n="<<n<<" J="<<J<<" vj="<<vj<<" H="<<H<<" vh="<<vh<<"\n";
            cout << "A="<<a<<"  B="<<b<<"\n";
            return 0;
        }
    }
    cout << " All " << N << " tests matched!" << endl;
}
