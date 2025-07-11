#include<iostream>
#include<vector>
using namespace std;

int N,K,a,b;
char op;
vector<int> arr(100001);
vector<int> tree(400004);

int init(int node,int s,int e){
    if(s==e)return tree[node]=arr[s];

    int m=(s+e)/2;

    return tree[node]=init(node*2,s,m)*init(node*2+1,m+1,e);
}

int find(int node,int s,int e,int l,int r){
    if(l>e||r<s)return 1;

    if(l<=s&&e<=r)return tree[node];

    int m=(s+e)/2;

    return find(node*2,s,m,l,r)*find(node*2+1,m+1,e,l,r);
}

void update(int node,int s,int e,int idx,int v){
    if(idx>e||idx<s)return;

    if(s==e){
        tree[node]=v;
        return;
    }
    int m=(s+e)/2;
    update(node*2,s,m,idx,v);
    update(node*2+1,m+1,e,idx,v);
    tree[node]=tree[node*2]*tree[node*2+1];
}

int sign(int x){
    if(x == 0) return 0;
    return x > 0 ? 1 : -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>N>>K){
        for(int i=1;i<=N;i++){
            cin>>arr[i];
            arr[i]=sign(arr[i]);
        }

        init(1,1,N);

        for(int i=1;i<=K;i++){
            cin>>op>>a>>b;
            if(op=='C'){
                int v=sign(b);
                arr[a]=v;
                update(1,1,N,a,v);
            }
            else{
                int tmp=find(1,1,N,a,b);
                if(tmp==1)cout<<"+";
                else if(tmp==-1)cout<<"-";
                else cout<<0;
            }
        }
        cout<<"\n";
    }
}