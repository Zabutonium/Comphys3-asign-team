//速度はとりあえず固定
//-MAX_POINT<=x,y<=MAX_POINT
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include <string>

const long        MAX_POINT          = 100;
const long        INITIAL_VELOCITY_X = 0;
const long        INITIAL_VELOCITY_Y = 0;
const long        N                  = 100;
const std::string FILE_NAME          = "Initialplot_grid.dat";

int main() {
    long lines, count;
    double x, y, dx, dy;
    lines = std::ceil(std::sqrt((double)N));
    dx = dy = 2*MAX_POINT/lines;
    x = y = -MAX_POINT;
    count = 0;
    std::ofstream output(FILE_NAME);
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            output << x << " " << y << " ";
            output << INITIAL_VELOCITY_X << " " << INITIAL_VELOCITY_Y << std::endl;
            count++;
            if (count == N) break;
            x += dx;
        }
        x = -MAX_POINT;
        y += dy;
    }
    output.close();
    return 0;
}
