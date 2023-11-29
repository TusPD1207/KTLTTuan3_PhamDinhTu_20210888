/*
Bài tập 3.5. Tính hệ số tổ hợp C(n, k)
*/
#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    //# Khử đệ quy
    long result = 1; //(nC0 = 1) //gán giá trị nC0 = 1
    for ( int i = 1; i <= k ; i++) 
    {
        result = result * n / i; //tính lại hệ số tổ hợp 
        n--; //giảm giá trị của n để tính các hệ số tiếp theo
    }
    return result;
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k)); // in ra n dòng hệ số tổ hợp
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));// in ra n dòng hệ số tổ hợp bằng cách 2
        printf("\n");
    }
    return 0;
}
