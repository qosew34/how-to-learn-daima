#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> road;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        road.push_back(temp);
    }
    int time=0;
    //检测最大的，最大的到0那就是到0
    int last_0=0;
    int day=0;
    while(!all_of(road.begin(),road.end(),[](int x){return x==0;})){
        for(int j=last_0;j<n;j++){
            if(j==last_0&&road[j]==0){
                last_0++;
            }//第一位，0不管
            /*到最后一位，非0-1是0则不管，无论如何day+1
            本位非0，-1
            前一位非0本位0 day+1,break
            */
            else if(j==n-1){
                day++;
                if(road[j]!=0){
                    road[j]--;
                }
                break;
            }
            else if(road[j]!=0){
                road[j]--;
            }
            else if(road[j]==0){
                day++;
                break;
            }
        }
    }
    cout<<day;
}
/*又tle了，妈的
想想ai会怎么写
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> road(n);
    for(int i = 0; i < n; i++) {
        cin >> road[i];
    }
    int day = 0;
    int prev = 0;
    for(int i = 0; i < n; i++) {
        day += max(0, road[i] - prev);
        prev = road[i];
    }
    cout << day << endl;
    return 0;
}
    我草，太他妈精妙了
    我怎么想不到，妈的
*/