#include <string>
#include <vector>
#include<bit>
using namespace std;

int qn;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    qn=q.size();
    vector<int> bits(qn,0);
    for(int i=0;i<qn;i++)for(int j=0;j<5;j++)bits[i]|=1<<q[i][j];
    int answer = 0;
    
    for(int a=1;a<=n-4;a++){
        for(int b=a+1;b<=n-3;b++){
            for(int c=b+1;c<=n-2;c++){
                for(int d=c+1;d<=n-1;d++){
                    for(int e=d+1;e<=n;e++){
                        int bit=1<<a|1<<b|1<<c|1<<d|1<<e;
                        bool flag=true;
                        for(int i=0;i<qn;i++){
                            if(__popcount(bits[i]&bit)!=ans[i]){
                                flag=false;
                                break;
                            }
                        }
                        if(flag)answer++;
                    }
                }
            }
        }
    }
    
    return answer;
}