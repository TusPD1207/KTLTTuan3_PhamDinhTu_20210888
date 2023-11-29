/*
Bài tập 3.1. Dãy Lucas được định nghĩa bởi Ln = Ln-1+ Ln-2 với L0 = 2, L1 = 1. Hãy viết hàm tính số Lucas thứ n.
*/
#include<stdio.h>
int lucas(int n) {
    if(n<=1) return 2-n; //Tinh L0 va L1
    return lucas(n-1) + lucas(n-2); //De quy de tinh Ln voi n>=2
}
int main(){
    int n;
    scanf("%d",&n);
    printf("L[%d] = %d\n", n, lucas(n));
    return 0;
}//Ham main de tinh lucas(n)


