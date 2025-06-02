#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int N;
vector<vector<pair<int,int>>> tree(100000);
vector<int> dis(100000,0);
int node;

void dfs(int idx){
    stack<pair<int,int>> s;
    vector<bool> visit(N,false);
    s.push({idx,0});

    while(!s.empty()){
        int cur=s.top().first;
        int w=s.top().second;
        visit[cur]=true;
        s.pop();

        dis[cur]=max(dis[cur],w);

        for(int i=0;i<tree[cur].size();i++){
            int next=tree[cur][i].first;
            int d=tree[cur][i].second;

            if(visit[next])continue;
            s.push({next,w+d});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    for(int i=0;i<N;i++){
        int v,n,w;
        cin>>v;
        do{
            cin>>n;
            if(n==-1)break;
            cin>>w;
            tree[v-1].push_back({n-1,w});
            tree[n-1].push_back({v-1,w});
        }while(true);
    }
    dfs(0);

    node=max_element(dis.begin(),dis.end())-dis.begin();
    dfs(node);

    cout<<*max_element(dis.begin(),dis.end());
}