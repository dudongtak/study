#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;

int N,M;
typedef long long ll;
vector<int> arr;
vector<pair<ll,ll>> coord;
vector<pair<int,int>> connect;
double answer=0;

double compute_dis(int a,int b){
    ll x=coord[a].first-coord[b].first;
    ll y=coord[a].second-coord[b].second;
    return sqrt(x*x+y*y);
}

int Find(int v){
    if(v==arr[v])return v;
    return arr[v]=Find(arr[v]);
}

void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);

    arr[y]=x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;
    coord.resize(N+1);
    arr.resize(N+1);

    for(int i=1;i<=N;i++)arr[i]=i;
    for(int i=1;i<=N;i++)cin>>coord[i].first>>coord[i].second;

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        
        connect.push_back({a,b});
    }

    for(int i=0;i<M;i++){
        int n1=connect[i].first;
        int n2=connect[i].second;
        if(Find(n1)!=Find(n2))Union(n1,n2);
    }
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;

    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            double dis=compute_dis(i,j);
            pq.push({dis,{i,j}});
        }
    }

    while(!pq.empty()){
        int n1=pq.top().second.first;
        int n2=pq.top().second.second;
        double dis=pq.top().first;
        pq.pop();

        if(Find(n1)!=Find(n2)){
            Union(n1,n2);
            answer+=dis;
        }
    }

    double tmp=round(answer*100)/100;
    cout<<fixed;
    cout.precision(2);
    cout<<tmp;
}