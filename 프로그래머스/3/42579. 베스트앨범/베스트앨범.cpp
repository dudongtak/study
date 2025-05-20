#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first==b.first)return a.second>b.second;
        return a.first<b.first;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<pair<int,string>> v;
    map<string,priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>> m;
    
    for(int i=0;i<plays.size();i++){
        bool flag=false;
        int idx=0;
        for(int j=0;j<v.size();j++)
            if(v[j].second==genres[i]){
                flag=true;
                idx=j;
                break;
            }
        if(!flag)v.push_back({plays[i],genres[i]});
        else v[idx].first+=plays[i];
        m[genres[i]].push({plays[i],i});
    }
    sort(v.begin(),v.end(),greater<>());
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<2;j++){
            if(m[v[i].second].empty())break;
            answer.push_back(m[v[i].second].top().second);
            m[v[i].second].pop();
        }
    }
    
    return answer;
}