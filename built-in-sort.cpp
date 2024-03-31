#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;  // vector chứa số nguyên
vector<pair<int, int>> pv;  // vector chứa cặp số nguyên
int n;  // số phần tử


// Hàm phát sinh ngẫu nhiên vector v
void generate()
{
    int x;
    for (int i = 0; i < n; ++i)
    {
        x = rand() % 10;
        v.push_back(x);
    }    
}


// Hàm in ra màn hình vector v
void show(string message)
{
    cout << message << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}


// Hàm phát sinh ngẫu nhiên vector pv
void generate_pairs()
{
    int x;
    int y;
    for (int i = 0; i < n; ++i)
    {
        x = rand() % 13;
        y = rand() % 13;
    
        pv.push_back(make_pair(x, y));
    }
}


// Hàm in ra màn hình vector pv
void show_pairs(string message)
{
    cout << message << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << '(' << pv[i].first << ", " << pv[i].second << ") ";
    }
    cout << endl;
}


// Hàm so sánh dùng cho việc sắp xếp các cặp số
// giảm dần đối với thành phần thứ nhất 
bool compare1(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first > b.first;
}


// Hàm so sánh dùng cho việc sắp xếp các cặp số
// tăng dần đối với thành phần thứ nhất, giảm dần đối với thành phần thứ hai 
bool compare2(const pair<int, int>& a, const pair<int, int>& b)
{
    // Nếu thành phần thứ nhất khác nhau thì so sánh thành phần thứ nhất
    if (a.first != b.first)
    {
        return a.first < b.first;
    }

    // Ngược lại, nếu thành phần thứ nhất bằng nhau
    // thì so sánh thành phần thứ hai
    return a.second > b.second;
}


int main()
{
    n = 13;
    generate();
    show("Vector ban đầu:");

    sort(v.begin(), v.begin() + 5);
    show("Sắp xếp 5 phần tử đầu tiên tăng dần:");

    sort(v.begin(), v.end());
    show("Sắp xếp toàn bộ vector tăng dần:");
    
    sort(v.begin(), v.end(), greater<int>());
    show("Sắp xếp toàn bộ vector giảm dần:");

    generate_pairs();
    show_pairs("Vector ban đầu:");

    sort(pv.begin(), pv.end(), compare1);
    show_pairs("Sắp xếp giảm dần theo thành phần thứ nhất:");

    sort(pv.begin(), pv.end(), compare2);
    show_pairs("Sắp xếp tăng dần thành phần thứ nhất, giảm dần thành phần thứ hai:");

    return 0;
}
