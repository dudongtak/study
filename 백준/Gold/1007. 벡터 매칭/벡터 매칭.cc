#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
int t;
double Min;
vector<pii> vec;
vector<bool> used(20);

double vec_sum(int n){
    pii v={0,0};
    for(int i=0;i<n;i++){
        if(used[i]){
            v.first-=vec[i].first;
            v.second-=vec[i].second;
        }
        else{
            v.first+=vec[i].first;
            v.second+=vec[i].second;
        }
    }
    return sqrt(pow(v.first,2)+pow(v.second,2));
}

void make_num(int idx,int cnt,int n){
    if(cnt==n/2){
        Min=min(Min,vec_sum(n));
        return;
    }
    for(int i=idx;i<n;i++){
        used[i]=true;
        make_num(i+1,cnt+1,n);
        used[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        int n;
        Min=1e9;
        vec.clear();
        cin>>n;
        for(int i=0;i<n;i++)used[i]=false;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            vec.push_back({a,b});
        }
        
        make_num(0,0,n);
        cout.precision(16);
        cout<<Min<<"\n";
    }
}