#include <iostream>
#include <random>
#include <fstream>

const long        MAX_POINT    = 10000;
const long        MAX_VELOCITY = 100;
const long        MAX_MASS     = 10000;
const long        N            = 10000;
const std::string FILE_NAME    = "inputfile.dat";

int randomSign(int unnti); //乱数の入力を1or-1で返すだけ

long getSuitableRnd(std::mt19937 &output, std::mt19937 &unnti, long max); //pかvかきめて範囲内の乱数に整えて返す

int main() {
    std::random_device seed;
    std::mt19937 rnd_p(seed());
    std::mt19937 rnd_v(seed());
    std::mt19937 rnd_m(seed());
    std::ofstream ofs(FILE_NAME);
    for (int i = 0; i < N; i++) {
        ofs << getSuitableRnd(rnd_p, rnd_v, MAX_POINT) << " ";
        ofs << getSuitableRnd(rnd_p, rnd_v, MAX_POINT) << " ";
        ofs << getSuitableRnd(rnd_v, rnd_m, MAX_VELOCITY) << " ";
        ofs << getSuitableRnd(rnd_v, rnd_m, MAX_VELOCITY) << " ";
        ofs << rnd_m()%(MAX_MASS+1) << " ";
        ofs << std::endl;
    }
    return 0;
}

int randomSign(int unnti) {
    return (unnti%2) ? 1 : -1;
}

long getSuitableRnd(std::mt19937 &output, std::mt19937 &unnti, long max) {
    return randomSign(unnti())*(output()%(max+1));
}
