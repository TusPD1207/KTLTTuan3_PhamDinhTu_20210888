/*
Bài tập 3.9. Lập lịch cho y tá
Một y tá cần lập lịch làm việc trong N ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi. Một lịch làm việc 
là tốt nếu không có hai ngày nghỉ nào liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp đều có số ngày thuộc
đoạn [k1, k2]. Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra trên một dòng một xâu nhị phân độ dài
n với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu phải được in ra theo thứ tự từ điển.
*/
#include<bits/stdc++.h>
using namespace std;
const int  MAX = 1000;
const int du = 1000000000 + 7;
int n, k1, k2;
int x[MAX];
int cnt = 0; //biến cnt để đếm số lượng kết quả
int so0 = 0, so1 = 0; //khai báo các biến cần thiết

void inputData(){
    cin >> n >> k1 >> k2;//nhập dữ liệu k1, k2 là số ngày nghỉ cho phép
}

bool check(int  a, int  i){
    if(a==1) return true; //Kiểm tra xem a có phải ngày làm việc không
    else {
        //Nếu a không phải ngày làm việc, tức a là ngày nghỉ, ngày kế tiếp và trước đó không thể là ngày nghỉ
        if(i==0){
            if(x[a-1] == 0) return false;
            else { //ngày trước đó không là ngày nghỉ
                if(so1<k1) return false;
            }
        } else { // i==1
            if(x[a-1] == 0){
                if(n-a+1 < k1) return false;
            } else {
                if(so1>=k2) return false;
            }
        }

        return true;
    }
}

void solution(){
    /*
    khai báo int so1 = 0;
    chạy for cho đến khi so1 khác 0 và nhỏ hơn k1 
    */

    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
    cnt++;
    //nếu (cnt == du) cnt = 0;
}

void TRY(int  a){
    for(int  i=0; i<=1; i++){
        if(check(a,i)){
            x[a] = i; // ngày thứ a có thể là làm việc hoặc không làm việc
            int pre = so1;//gán biến
            if(i == 1){
                if(x[a-1] == 1) so1++;
                else so1 = 1;
            } else {
                so1 = 0;
            }

            if(a==n) solution();
            else TRY(a+1);
            so1 = pre;
        }
    }
}

int main(){
    inputData();
    TRY(1);
    //cout << cnt % du;
    return 0;
}