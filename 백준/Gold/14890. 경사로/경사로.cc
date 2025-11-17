#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> map(100, vector<int>(100, 0));

int check_row(int n, int l) {
    int cnt = n;

    for (int i = 0; i < n; i++) {
        vector<bool> visit(n, false);
        int seq = 1;
        int h = map[i][0];
        bool flag = false;

        for(int j=1;j<n;j++){
            if(h==map[i][j]){
                seq++;
            }
            else if(h-map[i][j]==-1){
                if(seq<l){
                    cnt--;
                    break;
                }
                if(j-l<0){
                    cnt--;break;
                }
                for(int k=j-1;k>=j-l;k--){
                    if(visit[k]||h!=map[i][k]){
                        cnt--;flag=true;break;
                    }
                    visit[k]=true;
                }
                seq=1;
            }
            else if(h-map[i][j]==1){
                if(j+l>n){
                    cnt--;
                    break;
                }
                for(int k=j;k<j+l;k++){
                    if(visit[k]||h-1!=map[i][k]){
                        cnt--;flag=true;break;
                    }
                    visit[k]=true;
                }
                j+=l-1;
            }
            else{
                cnt--;
                flag=true;
            }
            if(flag==true)break;
            h=map[i][j];
        }
    }
    return cnt;
}

int check_line(int n, int l) {
    int cnt = n;

    for (int i = 0; i < n; i++) {
        vector<bool> visit(n, false);
        int seq = 1;
        int h = map[0][i];
        bool flag = false;

        for(int j=1;j<n;j++){
            if(h-map[j][i]==0){
                seq++;
            }
            else if(h-map[j][i]==-1){
                if(seq<l){
                    cnt--;
                    break;
                }
                if(j-l<0){
                    cnt--;break;
                }
                for(int k=j-1;k>=j-l;k--){
                    if(visit[k]||h!=map[k][i]){
                        cnt--;flag=true;break;
                    }
                    visit[k]=true;
                }
                seq=1;
            }
            else if(h-map[j][i]==1){
                if(j+l>n){
                    cnt--;
                    break;
                }
                for(int k=j;k<j+l;k++){
                    if(visit[k]||h-1!=map[k][i]){
                        cnt--;flag=true;break;
                    }
                    visit[k]=true;
                }
                j+=l-1;
            }
            else{
                cnt--;
                flag=true;
            }
            if(flag==true)break;
            h=map[j][i];
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int answer = check_row(n, l);
    answer += check_line(n, l);
    
    cout << answer;
}
