#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(){

    }
    make_Pair (const T1 a, const T2 b){
        first = a;
        second = b;
    }
    Pair& operator= (const Pair& copied){
        first = copied.first;
        second = copied.second;
    }
    Pair (const Pair& copied){
        first = copied.first;
        second = copied.second;
    }
    void Min (Pair a, Pair b){
        if (a.first < b.first){
            return a;
        }
        else if (a.first == b.first && a.second < b.second){
            return a;
        }
        return b;
    }
};

template<typename T>
void mySort(vector<T>& a) {
    Pair j;
    for (int i = 0; i < a.size() - 1; ++i){
        for (int k = 1; k < a.size(); ++k){
            if (Min(a[k - 1], a[k]) == a[k]){
                j = a[k - 1];
                a[k - 1] = a[k];
                a[k] = j;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }
    }
}
