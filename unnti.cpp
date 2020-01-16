#include <vector>
#include <iostream>
using namespace std;

struct unnti {
    double x[2];
    double v[2];
    double a[2];
};

int main() {
    vector<unnti> buri(20000);
    for (int i = 0; i < 10000; i++) {
        buri[i].x[0] = i;
        buri[i].x[1] = i;
        buri[i].v[0] = i;
        buri[i].v[1] = i;
        buri[i].a[0] = i;
        buri[i].a[1] = i;
    }

    cout << buri[500].x[1] << endl;
}