/* 
Bài tập 3.10. Khoảng cách Hamming
Khoảng cách Hamming giữa hai xâu cùng độ dài là số vị trí mà ký tự tại vị trí đó là khác nhau trên hai xâu. Cho 
S là xâu gồm n ký tự 0. Hãy liệt kê tất cả các xâu nhị phân độ dài n, có khoảng cách Hamming với S bằng H. Các 
xâu phải được liệt kê theo thứ tự từ điển.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
int N, H;
int x[MAX];
int S[MAX]; //Xâu mẫu để so sánh
int cnt = 0;

void input(){
    cin >> N >> H;
    for(int i=0; i<N; i++)
        S[i] = 0; //Khởi tạo xâu mẫu ban đầu bằng 0
    for(int i=0; i<N; i++)
        x[i] = 0; //Khởi tạo x ban đầu bằng 0
}

// Kiểm tra khoảng cách Hamming giữa hai xâu
int checkHamming(int str1[], int str2[]){
    int lens = N;
    int cnt = 0;
    for(int i=0; i<lens; i++){
        if(str1[i] != str2[i]) cnt++; //nếu phần tử i khác nhau, cộng cnt thêm 1
    }
    return cnt;
}

bool check(int a, int i){
    return true;
}

void solution(){
    if(checkHamming(x,S) == H){ //nếu khoảng cách Hamming bằng H
        for(int i=0; i<N; i++)
            cout << x[i];//liệt kê tất cả các xâu thoả mãn, theo thứ tự từ điển
        cout << endl;
    }
}

void TRY(int a){
    for(int i=0; i<=1; i++){
        x[a] = i; //thử gán giá trị i cho phần tử x[a]
        if(a == N-1) solution(); //nếu đã gán đủ hết các giá trị, in ra solution
        else
            TRY(a+1); //nếu chưa gán đủ, thì gán cho giá trị tiếp theo
    }
}

int main(){
    int T;
    cin >> T;
    while(T > 0){
        input();
        TRY(0);//Bắt đầu TRY phần tử đầu tiên với vòng while T>0
        T--;
    }
}