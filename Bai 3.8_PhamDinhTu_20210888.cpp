/*
Bài tập 3.8. Cân đĩa
Bạn đang muốn kiểm tra xem một vật cho trước có đúng nặng M như người ta nói hay không. Có một cân thăng bằng và n 
quả cân. Quả thứ i nặng mi. Hãy chỉ ra một cách cân thỏa mãn. Quy cách in ra đã được tích hợp trong mã nguồn dưới.
*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, s;
    state(int _i = 0, int _j = 0, int _s=0): i(_i), j(_j), s(_s){}
};//khai báo cấu trúc state để xử lý các đối tượng

int main() {
    int n, M;
    cin >> n >> M; //nhập các giá trị đầu vào của các cân
    int m[n+1];//khai báo mảng m có n + 1 giá trị
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1, -m[1])); //đưa vào ngăn xếp state để bắt đầu duyệt
    s.push(state(1, 0, 0)); //đưa vào ngăn xếp một state khác để tiếp tục duyệt
    s.push(state(1, 1, m[1]));//đưa vào ngăn xếp một state khác để tiếp tục duyệt
    while (!s.empty()){ //lặp đến khi ngăn xếp trống
        state top = s.top();//lấy phần tử đầu tiên của ngăn xếp gắn cho top
        if (top.i >= n){ //kiểm tra độ lớn của top.i
            if (top.s == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];//in ra kết quả của bài toán
                    if (x[i] == 1) cout << '+' << m[i];//in ra kết quả của bài toán
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue; //nếu vòng lặp đúng, loại bỏ phần tử ở trên đỉnh, và tiếp tục
        }

        //# Khử đệ quy
        s.pop();//loại bỏ phần tử đỉnh
        x[top.i]=top.j;//gắn giá trị top.j cho x[top.i]
        s.push(state(top.i+1, -1, top.s-m[top.i+1]));
        s.push(state(top.i+1, 0,top.s));
        s.push(state(top.i+1, 1,top.s+m[top.i+1])); //thực hiện quá trình thêm phần tử vào đỉnh ngăn xếp
    }
    cout << -1; //in ra -1 nếu không có kết quả đúng

    return 0;
}