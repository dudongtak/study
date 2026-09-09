#include <string>
#include <vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
void d_p(vector<pii> &d,vector<pii> &p,int &d_idx,int &p_idx,int cap){
    int tmp=cap;
    while(d_idx!=-1&&tmp!=0){
        if(tmp>=d[d_idx].second){
            tmp-=d[d_idx].second;
            d_idx--;
        }
        else{
            d[d_idx].second-=tmp;
            tmp=0;
        }
    }
    tmp=0;
    while(p_idx!=-1&&tmp<cap){
        if(cap>=p[p_idx].second+tmp){
            tmp+=p[p_idx].second;
            p_idx--;
        }
        else{
            int diff=cap-tmp;
            tmp+=p[p_idx].second;
            p[p_idx].second-=diff;
        }
    }
}
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<pii> d,p;
    for(int i=0;i<n;i++){
        if(deliveries[i]!=0)d.push_back({i,deliveries[i]});
        if(pickups[i]!=0)p.push_back({i,pickups[i]});
    }
    int d_idx=d.size()-1,p_idx=p.size()-1;

    while(!(d_idx==-1&&p_idx==-1)){
        int far=-1;
        if(d_idx!=-1)far=max(far,d[d_idx].first);
        if(p_idx!=-1)far=max(far,p[p_idx].first);
        answer+=(far+1)*2;
        d_p(d,p,d_idx,p_idx,cap);
    }
    return answer;
}