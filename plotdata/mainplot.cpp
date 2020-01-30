#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>

#define vector std::vector
#define string std::string

const long N           = 5000;  //particleの数
const double MAX_TIME    = 5;   //tの最大値
const long DEVIDE_TIME = 100;  //tを何分割するか =n
const double SOFTING_FORCE    = 0.01;  //力のsofting parameter
const double CORRECT_VELOCITY = 0.6;     //速度の補正値
const double MOVE_x             = 0.0;    //初期条件の座標をずらす
const double MOVE_y             = 0.0;
const double MOVE_Vx             = 0.0;    //初期条件の速度をずらす
const double MOVE_Vy             = 0.0;
const string FILE_NAME = "Initialplot_circle.dat";

const double dt = (double)MAX_TIME / DEVIDE_TIME;

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

void MoveCollision(vector<object> &per);

void correctVelocity(vector<object> &per);

void inputFromFile(vector<object> &per);

void outputToFile(vector<object> &per, double time, int i);

double distance(object obj1, object obj2);

//obj1がobj2からうける力
//axis = 0でx　１でｙ
double acceralate(object obj1, object obj2, int axis); 

//一方向分のperticle[i]がうける力の総和
//axis = 0でx　１でｙ
double acceralateSum(vector<object> p, int index, int axis);

void initAcceralate(vector<object> &p);

void leapfrog(vector<object> &p);

//////////////////////////////////////////////////////////////////////////////////////////
int main() {
    vector<object> particle(N);
    inputFromFile(particle);
    correctVelocity(particle);
    MoveCollision(particle);
    for (int i = 0; i <= DEVIDE_TIME; i++) {
        double t = i*dt;
        outputToFile(particle, t,i);
        leapfrog(particle);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////


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

void outputToFile(vector<object> &per, double time, int i) {
    std::cout << "t = " << time << ", writing now ..." << std::endl;
    std::ostringstream name; name << i;
    string dataname = "plot_i=" + name.str() + ".dat";
    std::ofstream datafile(dataname);

    for (int i = 0; i < N; i++) {
        datafile << per[i].x[0] << " " << per[i].x[1] << std::endl;
    }

    std::cout <<"t = " << time << ", Writing succeed." << std::endl;
}

void correctVelocity(vector<object> &per){
    for (int i = 0; i < N; i++) {
        per[i].v[0] *= CORRECT_VELOCITY;
        per[i].v[1] *= CORRECT_VELOCITY;
    }
}

void MoveCollision(vector<object> &per){
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            per[i].x[0] += MOVE_x;
            per[i].x[1] += MOVE_y;
            per[i].v[0] -= MOVE_Vx;
            per[i].v[1] -= MOVE_Vy;
        }else if(i % 2 == 1){
            per[i].x[0] -= MOVE_x;
            per[i].x[1] -= MOVE_y;
            per[i].v[0] += MOVE_Vx;
            per[i].v[1] += MOVE_Vy;
        }
    }
}


double distance(object obj1, object obj2) {
    return std::sqrt(pow(obj1.x[0] - obj2.x[0] , 2) + pow(obj1.x[1] - obj2.x[1] , 2));
}

double acceralate(object obj1, object obj2, int axis) {
    return (obj2.x[axis] -obj1.x[axis]) / std::pow(distance(obj1, obj2) + SOFTING_FORCE, 3);
}

double acceralateSum(vector<object> p, int index, int axis) {
    double res = 0;
    for (int i = 0; i < N; i++){
        if (i == index) continue;
        res += acceralate(p[index], p[i], axis);
    }
    return res;
}

//p(perticleの配列)の座標から全部の加速度を初期化
void initAcceralate(vector<object> &p) {
    for (int i = 0; i < N; i++) {
        p[i].a[0] = acceralateSum(p, i, 0);
        p[i].a[1] = acceralateSum(p, i, 1);
    }
}

//leapfrogによる時間発展
//pの位置から加速度をセット(initAcceralate)
//vMidlle = v_1/2
//vMiddle -> xの順で更新
//更新されたxからaを新たにせっと(a_i+1)
//vを更新
void leapfrog(vector<object> &p){
    vector<vector<double> > vMiddle(N, vector<double>(2));
    initAcceralate(p);
    for (int i = 0; i < N; i++) {
        vMiddle[i][0] = p[i].v[0] + p[i].a[0]*dt/2;
        vMiddle[i][1] = p[i].v[1] + p[i].a[1]*dt/2;
    }
    for (int i = 0; i < N; i++) {
        p[i].x[0] = p[i].x[0] + vMiddle[i][0]*dt;
        p[i].x[1] = p[i].x[1] + vMiddle[i][1]*dt;
    }
    initAcceralate(p);
    for (int i = 0; i < N; i++) {
        p[i].v[0] = vMiddle[i][0] + p[i].a[0]*dt/2;
        p[i].v[1] = vMiddle[i][1] + p[i].a[1]*dt/2;
    }
}
