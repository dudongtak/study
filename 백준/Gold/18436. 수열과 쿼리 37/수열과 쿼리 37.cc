#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> arr(100001,0);
pair<int,int> tmp={0,0};
vector<pair<int,int>> tree(400004,tmp);//first는 짝수 second는 홀수

pair<int,int> init(int node,int s,int e){
    if(s==e){
        if(arr[s]%2==0)tree[node].first=1;
        else tree[node].second=1;
        return tree[node];
    }

    int m=(s+e)/2;
    pair<int,int> l=init(node*2,s,m);
    pair<int,int> r=init(node*2+1,m+1,e);

    pair<int,int> cur;cur.first=l.first+r.first;cur.second=l.second+r.second;

    return tree[node]=cur;
}

pair<int,int> find(int node,int s,int e,int l,int r){
    if(e<l||r<s)return tmp;

    if(l<=s&&e<=r)return tree[node];

    int m=(s+e)/2;
    pair<int,int> left=find(node*2,s,m,l,r);
    pair<int,int> right=find(node*2+1,m+1,e,l,r);

    pair<int,int> cur;cur.first=left.first+right.first;cur.second=left.second+right.second;

    return cur;
}

void update(int node,int s,int e,int idx,int v){
    if(idx<s||idx>e)return;

    if(s==e){
        tree[node].first=(v%2==0);
        tree[node].second=(v%2==1);
        return;
    }

    int m=(s+e)/2;
    update(node*2,s,m,idx,v);
    update(node*2+1,m+1,e,idx,v);

    tree[node].first=tree[node*2].first+tree[node*2+1].first;
    tree[node].second=tree[node*2].second+tree[node*2+1].second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i];

    init(1,1,N);

    cin>>M;

    while(M--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            if(arr[l]%2!=r%2){
                update(1,1,N,l,r);
            }
            arr[l]=r;
        }
        else if(op==2){
            cout<<find(1,1,N,l,r).first<<"\n";
        }
        else{
            cout<<find(1,1,N,l,r).second<<"\n";
        }
    }
}