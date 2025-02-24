#include<iostream>
#include<vector>
using namespace std;

long long initTree(vector<long long> &arr,vector<long long> &tree,int node,int start,int end){
    if(start==end)return tree[node]=arr[start];

    int mid=(start+end)/2;

    return tree[node]=initTree(arr,tree,node*2,start,mid)+initTree(arr,tree,node*2+1,mid+1,end);
}

void update(vector<long long> &tree,int node,int start,int end,int idx,long long diff){
    if(idx<start||idx>end)return;
    tree[node]+=diff;

    if(start!=end){
        int mid=(start+end)/2;
        update(tree,node*2,start,mid,idx,diff);
        update(tree,node*2+1,mid+1,end,idx,diff);
    }
}

long long sum(vector<long long> &tree,int node, int start,int end,int l,int r){
    if(l>end||r<start)return 0;
    if(l<=start&&end<=r)return tree[node];

    int mid=(start+end)/2;
    return sum(tree,node*2,start,mid,l,r)+sum(tree,node*2+1,mid+1,end,l,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    vector<long long> num(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    vector<long long> tree((n+1)*4,0);

    initTree(num,tree,1,1,n);

    int opCnt=m+k;
    
    for(int i=0;i<opCnt;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;

        if(a==1){
            long long diff=c-num[b];
            num[b]=c;
            update(tree,1,1,n,b,diff);
        }
        else{
            cout<<sum(tree,1,1,n,b,c)<<"\n";
        }
    }
}