#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,k;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    if(n>=k){
        cout<<n-k;
        return 0;
    }

    vector<int> dot(100001,100001);
    dot[n]=0;

    priority_queue<pii,vector<pii>,greater<>> pq;

    pq.push({0,n});

    while(!pq.empty()){
        int cur=pq.top().second;
        int time=pq.top().first;
        pq.pop();

        if(time>dot[cur])continue;

        if(cur*2<=100000&&dot[cur*2]>time+1){
            dot[cur*2]=time+1;
            pq.push({time+1,cur*2});
        }
        if(cur<100000&&dot[cur+1]>time+1){
            dot[cur+1]=time+1;
            pq.push({time+1,cur+1});
        }
        if(cur>0&&dot[cur-1]>time+1){
            dot[cur-1]=time+1;
            pq.push({time+1,cur-1});
        }
    }
    cout<<dot[k];
}