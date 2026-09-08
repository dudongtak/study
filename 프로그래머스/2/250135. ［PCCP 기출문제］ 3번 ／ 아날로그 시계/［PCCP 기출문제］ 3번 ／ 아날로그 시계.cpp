#include <string>
#include <vector>

using namespace std;
//00:00:00에 시분초 겹침.
vector<int> make_hms(int s){
    return {s/3600,s%3600/60,s%3600%60};
}
vector<double> make_d(int s){
    vector<int> hms=make_hms(s);
    return {hms[0]%12*30+hms[1]*0.5+hms[2]/120.0,hms[1]*6+hms[2]*0.1,hms[2]*6.0};
}
int solution(int h1, int m1, int s1, int h2, int m2, int s2){ 
    int answer=0;
    
    int s=h1*60*60+m1*60+s1;
    int e=h2*60*60+m2*60+s2;
    if(s%3600==0)answer++;
    
    for(int i=s;i<e;i++){
        vector<double> cur=make_d(i);
        vector<double> next=make_d(i+1);
        if((i+1)%60==0)next[2]=360;
        if(cur[0]>cur[2]&&next[0]<=next[2])answer++;
        if(cur[1]>cur[2]&&next[1]<=next[2])answer++;
        if((i+1)%43200==0)answer--;
    }
    
    return answer;
}