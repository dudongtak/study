#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer=0;
    sort(targets.begin(),targets.end(),cmp);
    int n=0;
    int e=0;
    while(n<targets.size()){
        if(targets[n][0]>=e){
            answer++;
            e=targets[n][1];
        }
        n++;
    }
    return answer;
}