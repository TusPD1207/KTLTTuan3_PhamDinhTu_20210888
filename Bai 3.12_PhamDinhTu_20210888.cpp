/*
Bài tập 3.12. Đếm đường đi
Cho đồ thị vô hướng G, hãy đếm số đường đi đi qua k cạnh và không đi qua đỉnh nào quá một lần.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, k;
int m;
vector<vector<int> > vt; // chuyển các cạnh sang lưu trữ dưới dạng danh sách kề
int x[MAX];
bool visited[MAX];
int res;

void input(){ //Nhập dữ liệu n, m, k
    cin >> n >> k; 
    cin >> m;
    vt.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2; //nhập vào hai đỉnh để tham chiếu

        vt[tmp1-1].push_back(tmp2-1); // thêm phần tử mới vào ngăn xếp là tmp2, kề với tmp1
        vt[tmp2-1].push_back(tmp1-1); // thêm phần tử mới vào ngăn xếp là tmp1, kề với tmp2
    }

    for(int i=0; i<n; i++){
        visited[i] = false; 
    }
    res = 0;
}

bool check(int a, int i){
    if(a == 0) return true; //Đỉnh xuất phát, visited luôn bằng true
    if(visited[i]) return false; //Nếu đỉnh đã được thăm, vi phạm bài toán, trả về false

    int index = 0; 
    for(int j=0; j<vt[x[a-1]].size(); j++){ //kiểm tra xem có cạnh nối giữa 2 đỉnh hay không
         if(i == vt[x[a-1]][j]) index++; //nếu có, index cộng 1
    }
    if(index == 0) return false; //không thì trả về false


    return true;
}

void solution(){
    res++; //khi thoả mãn, cộng 1 vào res, in ra solution
}

void TRY(int a){ //Thử tất cả các khả năng chọn đỉnh, chọn cạnh
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;//nếu đã thăm đỉnh i
            x[a] = i; //gán i vào x[a]

            if(a == k) solution(); //nếu đã có đủ k cạnh thì in ra solution
            else TRY(a+1);//chưa đủ thì thử tiếp trường hợp tiếp theo
            visited[i] = false; //trả lại về false
        }
    }
}

int main(){
    input();
    TRY(0); //thử bắt đầu từ đỉnh xuất phát
    cout << res / 2; //in ra số lượng đường đi cần tìm
}