#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    // Lấy phần tử cuối cùng rồi mới pop_back
    cout << v.back() << endl;  // In phần tử cuối cùng
    v.pop_back();  // Xóa phần tử cuối

    vector<int> vv(10, 5);  // Tạo vector với 10 phần tử, mỗi phần tử có giá trị là 5
    vector<int>::iterator it;
    it = vv.begin();  // Iterator trỏ tới phần tử đầu tiên

    cout << vv[5] << endl;  // In phần tử thứ 6 (chỉ số 5)

    vector<vector<int>> vvv(5,vector<int>(10));
    vvv[4][9] = 8;
    cout<<vvv[4][9];
    vector <int>vvvv(10);
    vvvv.push_back(20);
    cout<<endl<<vvvv.back();
    return 0;
}
