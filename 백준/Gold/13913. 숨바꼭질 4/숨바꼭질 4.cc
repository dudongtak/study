#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,k,Max=100000;
vector<int> line(Max+1,-1),parent(Max+1,-1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    if(n>=k){
        cout<<n-k<<"\n";
        for(int i=n;i>=k;i--)cout<<i<<" ";
        return 0;
    }

    queue<int> q;
    q.push(n);
    line[n]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(cur==k)break;
        int next[]={cur*2,cur-1,cur+1};

        for(auto nx:next){
            if(nx<0||nx>Max)continue;
            if(line[nx]!=-1)continue;

            line[nx]=line[cur]+1;
            parent[nx]=cur;
            q.push(nx);
        }
    }

    cout<<line[k]<<'\n';
    vector<int> path;
    for(int i=k;i!=-1;i=parent[i])path.push_back(i);
    for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<' ';
}