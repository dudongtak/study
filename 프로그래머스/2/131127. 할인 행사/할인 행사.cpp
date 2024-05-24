#include <string>
#include <vector>
#include <map>

using namespace std;
//매일 1가지 할인 -> 할인은 하루에 1개 구매
//10 일 연속 일치시 회우너가입

bool check(map<string,int> m,vector<string> d,int s,int e){
    for(int i=s;i<e;i++){
        if(m[d[i]]>0){
            m[d[i]]--;
        }
        else{
            return false;
        }
    }
    
    bool c=true;
    
    for(auto i:m){
        if(i.second!=0){return false;}
    }
    
    return c;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> m;
    
    for(int i=0;i<want.size();i++){
        m[want[i]]=number[i];
    }
    bool flag=true;
    for(int i=0;i<10;i++){
        m[discount[i]]--;
    }
    for(int i=0;i<want.size();i++){
        if(m[want[i]]!=0){
            flag=false;break;
        }
    }
    if(flag==true)answer++;
    for(int i=1;i<discount.size()-9;i++){
        int s=i;
        int e=s+9;
        m[discount[s-1]]++;
        m[discount[e]]--;
        flag=true;
        for(int j=0;j<want.size();j++){
            if(m[want[j]]!=0){
                flag=false;break;
            }
        }
        if(flag==true)answer++;
    }
    return answer;
}