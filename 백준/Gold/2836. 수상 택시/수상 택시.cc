#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
typedef pair<int,int> pii;
vector<pii> rev;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    
    long long answer=0;
    int cur=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a>b)rev.push_back({b,a});
    }
    sort(rev.begin(),rev.end());

    int l=0,r=0;

    for(int i=0;i<rev.size();i++){
        if(rev[i].first>r){
            answer+=2*(r-l);
            l=rev[i].first;
            r=rev[i].second;
        }
        else{
            r=max(r,rev[i].second);
        }
    }
    answer+=2*(r-l)+m;

    cout<<answer;
}