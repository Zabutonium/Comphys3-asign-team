#include <iostream>
#include <random>
#include <fstream>

const long        MAX_POINT    = 1;
const long        MAX_VELOCITY = 1;
const long        N            = 100;
const std::string FILE_NAME    = "Initialplot_circle.dat";

int randomSign(int input); //乱数の入力を1or-1で返すだけ

long getSuitableRnd(std::mt19937 &output, std::mt19937 &rnd, long max); //pかvかきめて範囲内の乱数に整えて返す

int main() {
    std::random_device seed;
    std::mt19937 rnd_p(seed());
    std::mt19937 rnd_v(seed());
    std::ofstream ofs(FILE_NAME);
    ofs << 0 << " ";
    for (int i = 0; i < N; i++) {
        ofs << getSuitableRnd(rnd_p, rnd_v, MAX_POINT) << " ";
        ofs << getSuitableRnd(rnd_p, rnd_v, MAX_POINT) << " ";
        ofs << getSuitableRnd(rnd_v, rnd_p, MAX_VELOCITY) << " ";
        ofs << getSuitableRnd(rnd_v, rnd_p, MAX_VELOCITY) << " ";
    }
    return 0;
}

int randomSign(int input) {
    return (input%2) ? 1 : -1;
}

long getSuitableRnd(std::mt19937 &output, std::mt19937 &rnd, long max) {
    return randomSign(rnd())*(output()%(max+1));
}
