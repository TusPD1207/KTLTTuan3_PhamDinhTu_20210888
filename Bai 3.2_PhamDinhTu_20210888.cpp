/*
Bài tập 3.2: Trên bàn cờ vua kích thước n*n có một quân mã đang ở ô (1, 1). 
Hãy đưa ra một dãy các di chuyển của mã sao cho mỗi ô trên bàn cờ đều được đi qua đúng 1 lần (ô (1, 1) được xem là đã đi qua).
*/
#include <iostream>
using namespace std;
int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if((!mark[xx][yy]) && (1<=xx) && (xx<=n) && (1<=yy) && (yy<=n)){
        X[k]=xx;//Lưu toạ độ của quân mã
        Y[k]=yy;//Lưu toạ độ của quân mã
        mark[xx][yy] = 1; //Đánh dấu vị trí này là ô mã đã đi qua
        if(k==n*n) print_sol();//nếu đã đi qua hết đủ n*n ô thì in ra sol
        else TRY(k+1); //nếu chưa đi qua hết thì thử tiếp với k+1
        mark[xx][yy] = 0; //đánh dấu vị trí này là ô mã chưa đi qua
        }
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
