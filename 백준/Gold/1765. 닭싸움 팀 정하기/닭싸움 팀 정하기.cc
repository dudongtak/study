#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n,m;
vector<int> f;
vector<vector<int>> e;

int Find(int a){
    if(f[a]==a)return a;
    return f[a]=Find(f[a]);
}

void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);

    if(x==y)return;

    if(x>y)f[y]=x;
    else f[x]=y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    f.resize(n);
    e.resize(n);
    for(int i=0;i<n;i++)f[i]=i;
    for(int i=0;i<m;i++){
        char r;
        int p,q;
        cin>>r>>p>>q;
        if(r=='E'){
            e[p-1].push_back(q-1);
            e[q-1].push_back(p-1);
        }
        if(r=='F'){
            Union(p-1,q-1);
        }
    }
    for(int i=0;i<n;i++){
        for(auto enemy:e[i]){
            for(auto F:e[enemy]){
                Union(i,F);
            }
        }
    }
    set<int> answer;
    for(int i=0;i<n;i++)answer.insert(Find(i));
    cout<<answer.size();
}