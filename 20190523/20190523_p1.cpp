/*
 * D2
 * 1954. 달팽이 숫자
 */
#include <iostream>
using namespace std;

int main() {
    int T, N, num, x, y, inc, dir;

    cin>>T;

    for(int time = 1; time<T+1; time++){
        cin>>N;
//        initialize
        int map[11][11];
        bool isFirst = true;
        num = N;
        inc = 1;
        dir = 1;
        x = 1;
        y = 0;

        while(num!=0){
            if(!isFirst){
                for(int i = 0; i < num; i++){
                    x += dir;
                    map[x][y] = inc++;
                }
                dir *= -1;

            }

            for(int i = 0; i<num; i++){
                y += dir;
                map[x][y] = inc++;
            }

            isFirst = false;
            num--;
        }

        cout<<"#"<<time<<endl;
        for(int i=1; i<= N; i++){
            for(int j=1; j<= N; j++){
                cout<<map[i][j]<<' ';
            }
            cout<<"\n";
        }
    }
   return 0;
}