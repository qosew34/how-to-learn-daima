#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,k,x;
        cin>>n>>k>>x;
        int max=x;
        int min=0;
        int mid=0;
        vector<int> dis;
        int prev=0;
        vector<int> loc;
        for(int j=0;j<n;j++){
            int temp;cin>>temp;
            dis.push_back(temp-prev);
            prev=temp;
            loc.push_back(temp);
        }
        dis.push_back(x-prev);
        int total=0;
        for(int l=0;l<n+1;l++){
            if(total>k) break;
            if(dis[l]-2*max-1>0){
            total+=dis[l]-2*mid;
        }
        if(total<k){
        while(min<=max){
            mid=(max+min)/2;
            total=0;
            for(int l=0;l<n+1;l++){
                if(total>k) break;
                if(dis[l]-2*mid-1>0){
                    total+=dis[l]-2*mid;
                }
            }
            if(total>k){
                min=mid+1;
            }
            else max=mid-1;
        }
    max=min;}}
        for(l=0;l<n+1;l++){
            if(dis[l]-2*mid>0){
                for(int m=loc[l];i<=loc[i+1])
            }
        }
        
    }
}
/*const double EPS = 1e-12;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    cout.setf(std::ios::fixed);
    cout<<setprecision(10);
    while(t--){
        int n; long long k; double x;
        cin>>n>>k>>x;
        vector<double> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(), a.end());

        auto feasible = [&](double r)->bool{
            // build intervals [L,R] = [ai - r, ai + r] clipped to [0,x]
            vector<pair<double,double>> iv;
            for(int i=0;i<n;i++){
                double L = max(0.0, a[i] - r);
                double R = min(x, a[i] + r);
                if (R + EPS < L) continue;
                iv.emplace_back(L, R);
            }
            if(iv.empty()){
                // no forbidden intervals -> whole [0,x] is free -> infinite points
                return true;
            }
            sort(iv.begin(), iv.end());
            // merge intervals
            vector<pair<double,double>> merged;
            for(auto &p: iv){
                if(merged.empty() || p.first > merged.back().second + EPS){
                    merged.push_back(p);
                }else{
                    merged.back().second = max(merged.back().second, p.second);
                }
            }
            long long isolated = 0;
            double prev = 0.0;
            for(auto &p: merged){
                double L = p.first, R = p.second;
                if(L > prev + EPS){
                    // positive length gap => can place infinitely many points
                    return true;
                }else{
                    // gap length approx zero
                    // it's an isolated point only if the currently-encountered interval is degenerate (point)
                    if (fabs(L - prev) <= EPS && (R - L) <= EPS){
                        isolated++;
                    }
                }
                prev = max(prev, R);
            }
            // tail [prev, x]
            if(x > prev + EPS) return true; // positive length gap
            // if x == prev, there might already have been a degenerate point counted when interval was [x,x]
            return isolated >= k;
        };

        // binary search r
        double lo = 0.0, hi = x;
        for(int it=0; it<80; ++it){
            double mid = (lo + hi) / 2.0;
            if(feasible(mid)) lo = mid;
            else hi = mid;
        }
        double best_r = lo;

        // reconstruct k positions for best_r
        vector<pair<double,double>> iv;
        for(int i=0;i<n;i++){
            double L = max(0.0, a[i] - best_r);
            double R = min(x, a[i] + best_r);
            if (R + EPS < L) continue;
            iv.emplace_back(L, R);
        }
        sort(iv.begin(), iv.end());
        vector<pair<double,double>> merged;
        for(auto &p: iv){
            if(merged.empty() || p.first > merged.back().second + EPS){
                merged.push_back(p);
            }else{
                merged.back().second = max(merged.back().second, p.second);
            }
        }

        vector<double> ans;
        long long need = k;
        double prev = 0.0;
        // fill positive-length gaps first (they can host unlimited)
        for(auto &p: merged){
            double L = p.first, R = p.second;
            if(L > prev + EPS){
                double gapL = prev, gapR = L;
                double gapLen = gapR - gapL;
                // place as many as needed, spread evenly
                long long place = need; // we can place all remaining here
                if(place > 0){
                    double spacing = gapLen / (place + 1);
                    for(long long j=1;j<=place;j++){
                        double pos = gapL + spacing * j;
                        ans.push_back(pos);
                    }
                    need = 0;
                    break;
                }
            }
            prev = max(prev, R);
        }
        if(need>0 && x > prev + EPS && ans.empty()){ // if still need and there is tail gap
            double gapL = prev, gapR = x;
            double gapLen = gapR - gapL;
            long long place = need;
            double spacing = gapLen / (place + 1);
            for(long long j=1;j<=place;j++){
                double pos = gapL + spacing * j;
                ans.push_back(pos);
            }
            need = 0;
        }
        if(need>0){
            prev = 0.0;
            for(auto &p: merged){
                double L = p.first, R = p.second;
                if( fabs(L - prev) <= EPS && (R - L) <= EPS ){
                    // isolated point at prev (==L==R)
                    if(need>0){
                        ans.push_back(prev);
                        need--;
                    }
                }
                prev = max(prev, R);
            }
        }

        if(need>0){

            double cur = 0.0;
            for(auto &p: merged){
                double L = p.first, R = p.second;
                if(L > cur + EPS){
                    double pos = cur + min(1e-6, (L - cur) / 2.0);
                    while(need>0 && pos < L - 1e-15){
                        ans.push_back(pos);
                        need--;
                        pos += 1e-6;
                    }
                }
                cur = max(cur, R);
                if(need==0) break;
            }
            if(need>0 && x > cur + EPS){
                double pos = cur + min(1e-6, (x - cur) / 2.0);
                while(need>0 && pos < x + 1e-15){
                    ans.push_back(pos);
                    need--;
                    pos += 1e-6;
                }
            }
        }

        while(need>0){
            double pos = max(0.0, min(x, (double)need * 1e-7));
            ans.push_back(pos);
            need--;
        }


        for(size_t i=0;i<ans.size() && i<(size_t)k;i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}*/