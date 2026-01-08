#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int n,l;
typedef pair<int,int> pii;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l;
    deque<pii> dq;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    for(int i=0;i<n;i++){
        if(!dq.empty()){
            if(dq.front().second<i-l+1)dq.pop_front();
        }
        while(!dq.empty()&&dq.back().first>v[i])dq.pop_back();
        dq.push_back({v[i],i});
        cout<<dq.front().first<<" ";
    }
}