/* 
Bài tập 3.6. Tìm ước chung lớn nhất của hai số nguyên a, b cho trước.
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b); //tính gcd theo giải thuật Euclid
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    while(b != 0){ //nếu b khác 0
        int tmp = a % b; //tìm số dư của a khi chia cho b
        a = b; //gán b vào a
        b = tmp;//gán tmp vào b
    }
    return a; //trả về a sau khi thực hiện giải thuật
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b); //in ra giá trị gcd
    return 0;
}  
