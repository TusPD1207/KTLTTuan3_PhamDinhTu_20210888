/*
Bài tập 3.11. Lịch trình chụp ảnh
Superior là một hòn đảo tuyệt đẹp với n địa điểm chụp ảnh và các đường một chiều nối các điểm chụp ảnh với nhau. 
Đoàn khách tham quan có r người với sở thích chụp ảnh khác nhau. Theo đó, mỗi người sẽ đưa ra danh sách các địa 
điểm mà họ muốn chụp. Bạn cần giúp mỗi người trong đoàn lập lịch di chuyển sao cho đi qua các điểm họ yêu cầu 
đúng một lần, không đi qua điểm nào khác, bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng trong danh sách
mà họ đưa ra, và có tổng khoảng cách đi lại là nhỏ nhất.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_price;
int sum_price;
int start, destination, numberOfPoint; 
//Khai báo các biến cần thiết để đánh dấu giá tiền, tổng tiền, các địa điểm đã thăm, điểm bắt đầu
void input(){
    cin >> n >> r; //Nhập số lượng địa điểm và số lượng người
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> price[i][j]; //nhập dữ liệu về giá giữa hai địa điểm i và j
        }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(price[x[a-1]][vt[i]] == 0) return false; //kiểm tra xem có thể đi từ x[a-1] đến vt[i] không
    return true;
}

void solution(){
    if(price[x[numberOfPoint-2]][destination] == 0) return;
    min_price = min(min_price, sum_price + price[x[numberOfPoint-2]][destination]); 
    //kiểm tra và lưu trữ giá tiền nhỏ nhất dựa trên tổng số điểm và địa điểm
}

void TRY(int a){ //Thử nghiệm phương án tối ưu nhất
    for(int i=1; i<numberOfPoint-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sum_price += price[x[a-1]][vt[i]];;//nếu đã đi qua vt[i], cộng thêm tiền đi lại giữa 2 vị trí

            x[a] = vt[i];//gán tiếp x[a] thành vt[i]
            if(a == numberOfPoint-2) solution(); //nếu đã đi đủ các địa điểm, in ra chi phí
            else TRY(a+1);//nếu chưa, thử tiếp phương án kế tiếp

            visited[vt[i]] = false; //gán là chưa thăm quan vt[i]
            sum_price -= price[x[a-1]][vt[i]];//trừ đi chi phí thăm quan vt[i]
        }
    }
}

int main(){
    string str;
    input(); getline(cin,str);//input lịch di chuyển
    while(r > 0){
        min_price = INT_MAX;
        sum_price = 0;
        getline(cin, str);
        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); //Cập nhật lịch di chuyển
            }
        }
        //Khởi tạo các input cần thiết
        start = vt[0]; // điểm bắt đầu
        destination = vt[vt.size()-1]; // điểm đích
        numberOfPoint = vt.size(); // số điểm cần đi qua
        x[0] = start; x[numberOfPoint-1] = destination;
        for(int i=0; i<n; i++)
            visited[i] = false; //chạy thử đi qua các vị trí

        TRY(1);

        //In ra kết quả
        if(min_price == INT_MAX) cout << "0" << endl;
        else cout << min_price << endl;
        //Xoá vector khách đang thử, chạy sang khách tiếp theo
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}