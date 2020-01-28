//座標半径MAX_POINTの円の中
//速度x,yそれぞれ[-MAX_VEROCITY,MAX_VEROCITY]
//x,y独立じゃない乱数になっちゃったのでΘ,rの乱数を座標変換するかんじで作り直したほうがいいかも
//一応出力の形式をゆーたんのgridにあわせました
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>

const long        MAX_POINT     = 1;
const long        MAX_VELOCITY  = 1;
const long        N             = 100;
const long        DECIMAL_DEGIT = 8;
const std::string FILE_NAME     = "Initialplot_circle.dat";

int sign(int input); //乱数の入力を1or-1で返すだけ

double get0toMaxRnd(std::mt19937 &rnd, double max);

void outputCircleRnd(std::ofstream &ofs, std::mt19937 &output, std::mt19937 &rnd, long max);

int main() {
    std::random_device seed;
    std::mt19937 rnd_p(seed());
    std::mt19937 rnd_v(seed());
    std::ofstream ofs(FILE_NAME);
    for (int i = 0; i < N; i++) {
        outputCircleRnd(ofs, rnd_p, rnd_v, MAX_POINT);
        ofs << sign(rnd_p())*get0toMaxRnd(rnd_v, MAX_VELOCITY) << " ";
        ofs << sign(rnd_p())*get0toMaxRnd(rnd_v, MAX_VELOCITY) << " ";
        ofs << std::endl;
    }
    return 0;
}

int sign(int input) {
    return (input%2) ? 1 : -1;
}


//0からmaxまで,小数第DECIMAL_DEGIT位までの乱数
double get0toMaxRnd(std::mt19937 &rnd, double max) {
    long pow10digit  = std::pow(10, DECIMAL_DEGIT);
    long maxInteger = max*pow10digit;
    return (double)(rnd()%maxInteger)/pow10digit;
}

void outputCircleRnd(std::ofstream &ofs, std::mt19937 &output, std::mt19937 &rnd, long radius) {
    double x    = sign(rnd())*get0toMaxRnd(output, 1);
    double ymax = std::sqrt(1 - x*x);
    double y    = sign(rnd())*get0toMaxRnd(output, ymax);
    ofs << x << " " << y << " ";
}