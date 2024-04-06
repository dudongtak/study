#include <string>
#include <vector>
#include<map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int,long long> w;
    map<int,long long>m;
    for(int i=0;i<weights.size();i++){
        int n=weights[i];
        answer+=w[n*2]+w[n*3]+w[n*4];
        w[n*2]+=1;
        w[n*3]+=1;
        w[n*4]+=1;
        m[n]+=1;
        if(m[n]>1){
            answer-=2*(m[n]-1);
        }
    }
    return answer;
}