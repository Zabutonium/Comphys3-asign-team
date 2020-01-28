//座標半径radiusの円の中
//速度x,yそれぞれ[-MAX_VEROCITY,MAX_VEROCITY]
//一応出力の形式をゆーたんのgridにあわせました
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include <math.h>

#define PI 3.14159265359

const long        MAX_RADIUS    = 1;
const double      MAX_THETA     = 2*PI;
const long        MAX_VELOCITY  = 1;
const long        N             = 100;
const long        DECIMAL_DEGIT = 6;
const std::string FILE_NAME     = "Initialplot_circle.dat";

int sign(int input); //乱数の入力を1or-1で返すだけ

double get0toMaxRnd(std::mt19937 &rnd, double max);

void outputCircleRnd(std::ofstream &ofs, std::mt19937 &output);

int main() {
    std::random_device seed;
    std::mt19937 rnd_p(seed());
    std::mt19937 rnd_v(seed());
    std::ofstream ofs(FILE_NAME);
    for (int i = 0; i < N; i++) {
        outputCircleRnd(ofs, rnd_p);
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

void outputCircleRnd(std::ofstream &ofs, std::mt19937 &output) {
    double r     = get0toMaxRnd(output, MAX_RADIUS);
    double theta = get0toMaxRnd(output, MAX_THETA);
    double x = r*std::cos(theta);
    double y = r*std::sin(theta);
    ofs << x << " " << y << " ";
}