//datファイル関係あとでなおす
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

#define vector std::vector
#define string std::string

const long N           = 10000; //perticleの数
const long MAX_TIME    = 100;   //tの最大値
const long DEVIDE_TIME = 1000;  //tを何分割するか
const string FILE_NAME_INPUT  = "inputfile.dat";
const string FILE_NAME_OUTPUT = "outputfile.dat";

const double dt = (double)MAX_TIME / DEVIDE_TIME;

struct object {
    double x[2];
    double v[2];
    double a[2] = {0, 0};
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

void leapfrog(object obj1, object obj2, int axis);

int main() {
    vector<object> particle(N);
    //入力部 いらないかも
    std::ifstream inputfile(FILE_NAME_INPUT);
    for (int i = 0; i < N; i++) {
        inputfile >> particle[i].x[0] >> particle[i].x[1] >> particle[i].v[0] >> particle[i].v[1];
    }
    inputfile.close();

    for (int i = 0; i < DEVIDE_TIME; i++) {
        
        //入力部分 あとでかく
        initAcceralate(particle, 0);
        initAcceralate(particle, 1);
        
        
    }

    //出力
    std::ofstream outputfile(FILE_NAME_OUTPUT);
    double t = 0;
    for(int i = 0; i < N; i++){
    //書き込み
        outputfile << t << " " << particle[i].x[0] << " " << particle[i].x[1] << " " << particle[i].v[0] << " " << particle[i].v[1];
    
    //時間発展
        leapfrog(particle, i, 0);
        leapfrog(particle, i, 1);
        t += MAX_TIME/DEVIDE_TIME;
        outputfile.close();
    }
    
    
}

double distance(object obj1, object obj2) {
    return std::sqrt(pow(obj1.x[0] - obj2.x[0] , 2) + pow(obj1.x[1] - obj2.x[1] , 2));
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
void scanandthrow(int num, std::fstream &yomikaki) {
    string buf;
    for (int i = 0; i < num; i++) {
        std::getline(std::cin, buf);
    }
}

//leapfrogによる時間発展
void leapfrog(vector<object> p,int index, int axis){
    vector<object> np;
    double h = MAX_TIME/DEVIDE_TIME;
    double a = acceralateSum(p, index, axis);
    double newa;

    p.at(index).x[axis] += p.at(index).v[axis]*h + a*h*h*0.5;
    newa = acceralateSum(p, index, axis);
    p.at(index).v[axis] += (a + newa)*h*0.5;
}