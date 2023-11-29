/*
Bài tập 3.7. Sử dụng phương pháp khử đệ quy bằng stack, hãy liệt kê các xâu nhị phân độ dài n không có k bit 1 nào liên tiếp.
*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};//trường state

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        if(top.j>0) L = top.old_L; 
        //nếu giá trị của top.j lớn hơn 0, thì L sẽ được gán giá trị trên
        
        if(top.j>1){ //nếu top.j > 1
            s.pop();//loại bỏ một phần tử khỏi đỉnh ngăn xếp
            continue;//vòng lặp tiếp tục
        }
        if(L+1<k || top.j==0){
            x[top.i] = top.j;//gán giá trị của top.i cho phần tử top.j
            top.old_L = L;//lưu giá trị
            if(top.j){ //nếu top.j khác 0
                L = L + 1;//tăng giá trị của 0
            } else {L = 0;}//nếu không, L = 0 
            s.push(state(top.i+1,0)); 
            //thêm một trạng thái mới vào ngăn xếp, top.i tăng 1, top.j về 0
        }
        top.j++; //tăng giá trị top.j lên 1
    }
    return 0;
}