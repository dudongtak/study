#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,op,a,b;
int inf=1000000001;
vector<int> arr(100001,inf);
vector<int> tree(400004,inf);

int init(int node,int s,int e){
    if(s==e)return tree[node]=arr[s];

    int m=(s+e)/2;

    return tree[node]=min(init(node*2,s,m),init(node*2+1,m+1,e));
}

int Find(int node,int s,int e,int l,int r){
    if(e<l||r<s)return inf;

    if(l<=s&&e<=r)return tree[node];

    int m=(s+e)/2;

    return min(Find(node*2,s,m,l,r),Find(node*2+1,m+1,e,l,r));
}

void Update(int node,int s,int e,int idx, int v){
    if(idx<s||idx>e)return;
    
    if(s==idx&&e==idx){
        tree[node]=v;
        return;
    }

    int m=(s+e)/2;

    Update(node*2,s,m,idx,v);
    Update(node*2+1,m+1,e,idx,v);

    tree[node]=min(tree[node*2],tree[node*2+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i];

    init(1,1,N);

    cin>>M;

    while(M--){
        cin>>op>>a>>b;

        if(op==2){
            if(a<=b)cout<<Find(1,1,N,a,b)<<"\n";
            else cout<<Find(1,1,N,b,a)<<"\n";
        }
        if(op==1){
            arr[a]=b;
            Update(1,1,N,a,b);
        }
    }
}