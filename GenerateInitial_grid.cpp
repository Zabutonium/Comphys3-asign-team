//速度と質量はとりあえず固定
//仕様にそって一直線出力に
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>

const long        MAX_POINT          = 10000;
const long        INITIAL_VELOCITY_X = 0;
const long        INITIAL_VELOCITY_Y = 0;
const long        N                  = 10000;
const std::string FILE_NAME          = "inputfile.dat";

int main() {
    long lines, x, y, dx, dy, count;
    lines = std::ceil(std::sqrt((double)N));
    dx = dy = MAX_POINT/lines;
    x = y = 0;
    count = 0;
    std::ofstream output(FILE_NAME);
    output << 0 << " ";
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            output << x << " " << y << " ";
            output << INITIAL_VELOCITY_X << " " << INITIAL_VELOCITY_Y << " ";
            count++;
            if (count == N) break;
            x += dx;
        }
        x = 0;
        y += dy;
    }
    output.close();
    return 0;
}
