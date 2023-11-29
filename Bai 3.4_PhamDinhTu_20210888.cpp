/*
Bài tập 3.4. Cho dãy a có n phần tử. Một dãy con của  a là dãy thu được bằng cách xóa đi một số phần tử của  a và giữ nguyên thứ tự các phần tử còn lại (có thể không xóa phần tử nào). Hãy tìm dãy con tăng dài nhất của a.
*/
#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy hoạch động,
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    mem[0] = 1; 
    for(int i=1; i<n; i++){
        mem[i] = 1; 
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){ //nếu a[j] < a[i]
                if(mem[i] < mem[j] + 1){ //nếu mem[i] < mem[j] + 1
                    mem[i] = mem[j] + 1; //thì ta sẽ cộng 1 vào giá trị mem[j]
                }
            }
        }
    }
    return mem[i]; //trả về mem[i]
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        } //hàm for để xác định dãy tăng, đặt lại vị trí để đếm số lượng phần tử
    }
    cout << res << endl;
    trace(pos);
    return 0; 