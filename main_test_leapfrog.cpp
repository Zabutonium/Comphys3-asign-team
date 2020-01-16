//datファイル関係あとでなおす
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>

#define vector std::vector
#define string std::string

const long N           = 10000; //perticleの数
const long MAX_TIME    = 100;   //tの最大値
const long DEVIDE_TIME = 1000;  //tを何分割するか
const string FILE_NAME = "inputfile.dat";

const double dt          = (double)MAX_TIME / DEVIDE_TIME;

struct object {
    double x[2];
    double v[2];
    double a[2];
};

double distance(object obj1, object obj2);

//obj1がobj2からうける力
//axis = 0でx　１でｙ
double acceralate(object obj1, object obj2, int axis); 

//一方向分のperticle[i]がうける力の総和
//axis = 0でx　１でｙ
double acceralateSum(vector<object> p, int index, int axis);

void initAcceralate(vector<object> p, int axis);

void scanandthrow(int num, std::fstream yomikaki);

void inputFromFile(vector<object> &per, std::fstream &yomikaki, int counter);

int main() {
    vector<object> perticle(N);
    std::fstream yomikaki;
    yomikaki.open(FILE_NAME);
    int fileLineCounter = 0;
    for (int i = 0; i < DEVIDE_TIME; i++) {
        //入力部分 あとでかく
        inputFromFile(perticle, yomikaki, fileLineCounter);
        initAcceralate(perticle, 0);



    }
}

double distance(object obj1, object obj2) {
    return std::sqrt((obj1.x[0] - obj2.x[0])*(obj1.x[0] - obj2.x[0]) + (obj1.x[1] - obj2.x[1])*(obj1.x[1] - obj2.x[1]));
}

double acceralate(object obj1, object obj2, int axis) {
    return (obj2.x[axis] -obj1.x[axis]) / std::pow(distance(obj1, obj2), 3);
}

double acceralateSum(vector<object> p, int index, int axis) {
    double res = 0;
    for (int i = 0; i < N; i++){
        if (i = index) continue;
        res += acceralate(p[index], p[i], axis);
    }
    return res;    
}

void initAcceralate(vector<object> p) {
    for (int i = 0; i < N; i++) {
        p[i].a[0] = acceralateSum(p, i, 0);
        p[i].a[1] = acceralateSum(p, i, 1);
    }
}    

//あとで直す
void scanAndThrow(std::fstream &yomikaki, int counter) {
    string buf;
    for (int i = 0; i < counter; i++) {
        std::getline(yomikaki, buf);
    }
}

void inputFromFile(vector<object> per, std::fstream &yomikaki, int counter) {
    scanAndThrow(yomikaki, counter);
    
}