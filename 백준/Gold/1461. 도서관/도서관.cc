#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> neg,pos;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>0)pos.push_back(num);
        else{
            neg.push_back(-num);
        }
    }
    
    int answer=0;
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    for(int i=neg.size()-1;i>=0;i-=m){
        answer+=2*neg[i];
    }
    for(int i=pos.size()-1;i>=0;i-=m){
        answer+=2*pos[i];
    }
    if(neg.size()>0&&pos.size()>0){
        if(neg[neg.size()-1]>pos[pos.size()-1])answer-=neg[neg.size()-1];
        else answer-=pos[pos.size()-1];
    }
    else if(neg.size()>0){
        answer-=neg[neg.size()-1];
    }
    else{
        answer-=pos[pos.size()-1];
    }

    cout<<answer;
}