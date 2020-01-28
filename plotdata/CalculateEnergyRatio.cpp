//K/|W|を標準出力に出す奴
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>

#define vector std::vector
#define string std::string

const int    N         = 100;
const double GRAVITY   = 6.67430;
const string FILE_NAME = "Initialplot_circle.dat";

struct object {
    double x[2];
    double v[2];
    double a[2];

    object(double x0, double x1, double v0, double v1) {
        this->x[0] = x0; this->x[1] = x1;
        this->v[0] = v0; this->v[1] = v1;
    }

    object(void) {}
};

void inputFromFile(vector<object> &per);

double distance(object obj1, object obj2);

double Norm(double* vec);

double GravityEnergy(vector<object> per);

double KineticEnergy(vector<object> per);

/////////////////////////////////////////////////////////////////////////
int main() {
    vector<object> perticles(N);
    inputFromFile(perticles);
    double ratio = KineticEnergy(perticles) / std::abs(GravityEnergy(perticles));
    std::cout << "K/|W| = " << ratio << std::endl;
    return 0;
}
/////////////////////////////////////////////////////////////////////////

void inputFromFile(vector<object> &per) {
    std::cout << "start reading ..." << std::endl;
    std::ifstream ifs(FILE_NAME);
    for (int i = 0; i < N; i++) {
        double x[2], v[2];
        ifs >> x[0] >> x[1] >> v[0] >> v[1];
        per[i] = object(x[0], x[1], v[0], v[1]);

    }
    ifs.close();
    std::cout << "reading succeed." << std::endl;;
}

double distance(object obj1, object obj2) {
    return std::sqrt(pow(obj1.x[0] - obj2.x[0] , 2) + pow(obj1.x[1] - obj2.x[1] , 2));
}

//二次元限定
double Norm(double* vec) {
    return std::sqrt(vec[0]*vec[0]+vec[1]*vec[1]);
}

double GravityEnergy(vector<object> per) {
    double res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            res += 1/(2*distance(per[i], per[j]));
        }
    }
    return res;
}

double KineticEnergy(vector<object> per) {
    double res = 0;
    for (int i = 0; i < N; i++) {
        res += std::pow(Norm(per[i].v), 2)/2*GRAVITY;
    }
    return res;
}