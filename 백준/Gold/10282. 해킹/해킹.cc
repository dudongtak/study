#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int t,n,d,c,a,b,s;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n>>d>>c;
        vector<vector<pii>> com(n);

        int cnt=0,time=-1;
        vector<int> dis(n,1e9);
        priority_queue<pii,vector<pii>,greater<>> pq;
        pq.push({0,c-1});
        dis[c-1]=0;

        for(int i=0;i<d;i++){
            cin>>a>>b>>s;
            com[b-1].push_back({a-1,s});
        }
        while(!pq.empty()){
            auto [sec,cur]=pq.top();
            pq.pop();

            if(dis[cur]<sec)continue;

            for(auto next:com[cur]){
                int pc=next.first;
                int cost=sec+next.second;
                if(dis[pc]<=cost)continue;
                dis[pc]=cost;
                pq.push({cost,pc});
            }
        }
        for(auto t:dis){
            if(t==1e9)continue;
            time=max(time,t);
            cnt++;
        }
        cout<<cnt<<" "<<time<<"\n";
    }
}