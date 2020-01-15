//速度と質量はとりあえず固定
//仕様にそって一直線出力に
#include <iostream>
#include <random>
#include <fstream>

const long        MAX_POINT          = 10000;
const long        INITIAL_VELOCITY_X = 100;
const long        INITIAL_VELOCITY_Y = 100;
//const long        INITIAL_MASS       = 10000;
const long        N                  = 100;
const std::string FILE_NAME          = "inputfile.dat";

long upSqrt(long num); //sqrtとったやつを切り上げ

int main() {
    long lines, x, y, dx, dy, count;
    lines = std::ceil(std::sqrt(N));
    dx = dy = MAX_POINT/lines;
    x = y = 0;
    count = 0;
    std::ofstream output(FILE_NAME);
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            output << x << " " << y << " ";
            output << INITIAL_VELOCITY_X << " " << INITIAL_VELOCITY_Y << " ";
            //output << INITIAL_MASS;
            count++;
            if (count == N) break;
            //output << " ";
            x += dx;
        }
        x = 0;
        y += dy;
    }
    output.close();
    return 0;
}
