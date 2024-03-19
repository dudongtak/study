#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int>> noc;
vector<int> a;
vector<int> b;

void makeNoc(int i,int n,vector<int> v){
    v.push_back(i);
    if(v.size()==n/2){
        noc.push_back(v);
        return;
    }
    for(int j=i+1;j<n;j++){
        makeNoc(j,n,v);
    }
    return;
}
void makeA(int i,vector<vector<int>> d,int n,int num){
    if(n==d.size()/2){
        a.push_back(num);
        return;
    }
    for(int j=0;j<6;j++){
        makeA(i,d,n+1,num+d[noc[i][n]][j]);
    }
}
void makeB(int i,vector<vector<int>> d,int n,int num,vector<int> c,int j){
    if(n==d.size()/2){
        b.push_back(num);
        return;
    }
    for(j;j<c.size();j++){
        if(c[j]==0){
            for(int k=0;k<6;k++){
                makeB(i,d,n+1,num+d[j][k],c,j+1);
            }
            break;
        }
    }
    
}

int rate(vector<int> a,vector<int> b){
    int rate=0;
    for(int i=0;i<a.size();i++){
        int goal=a[i];
        int s=0;
        int e=b.size()-1;
        int mid;
        int flag=0;
        while(s<=e){
            mid=(s+e)/2;
            if(a[i]>b[mid]){
                s=mid+1;
            }
            else if(a[i]<=b[mid]){
                e=mid-1;
            }
        }
        if(a[i]<=b[mid]){
            rate+=(mid-1);
        }
        else{
            rate+=mid;
        }
    }
    return rate;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n=dice.size();
    vector<int> winRate;
    for(int i=0;i<n/2+1;i++){
        vector<int> v;
        makeNoc(i,n,v);
    }
    for(int i=0;i<noc.size();i++){
        a.clear();
        b.clear();
        vector<int> c(dice.size(),0);
        for(int j=0;j<noc[i].size();j++){
            c[noc[i][j]]=1;
        }
        makeA(i,dice,0,0);
        makeB(i,dice,0,0,c,0);
        sort(b.begin(),b.end());
        winRate.push_back(rate(a,b));
    }
    auto it=max_element(winRate.begin(),winRate.end());
    int maxIndex=distance(winRate.begin(),it);
    for(int i=0;i<noc[maxIndex].size();i++)
        answer.push_back(noc[maxIndex][i]+1);
    return answer;
}