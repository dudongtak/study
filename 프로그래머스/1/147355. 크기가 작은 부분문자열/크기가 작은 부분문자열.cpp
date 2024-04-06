#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n=p.length();
    int i=0;
    long long num=stoll(p);
    for(;i<t.length()-n+1;i++){
        long long tmp=stoll(t.substr(i,n));
        if(num>=tmp){
            answer++;
        }
    }
    return answer;
}