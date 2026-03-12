#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int t,n,d,c,a,b,s;
typedef pair<int,int> pii;
vector<vector<pii>> com(10000);
vector<int> dis;
priority_queue<pii,vector<pii>,greater<>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n>>d>>c;

        for(int i=0;i<n;i++)com[i].clear();
        dis.assign(n,1e9);
        pq=priority_queue<pii,vector<pii>,greater<>>();
        int cnt=0,time=-1;
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