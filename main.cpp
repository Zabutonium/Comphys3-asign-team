#include<iostream>
#include<cmath>
#include<fstream>
#include<stdlib.h>
#include<vector>
using namespace std;

const int N = 10000;
double fx(double t, double x[], double v[]){

  double r = sqrt(x[0]*x[0] + x[1]*x[1]);

  return -x[0]/(r*r*r);
}

double fy(double t, double x[], double v[]){

  double r = sqrt(x[0]*x[0] + x[1]*x[1]);

  return -x[1]/(r*r*r);
}

double runge_kutta(double dt, double t, double x[], double v[]){

  double xk1, xk2, xk3, xk4, yk1, yk2, yk3, yk4,
    vxk1, vxk2, vxk3, vxk4, vyk1, vyk2, vyk3, vyk4;
  double tx[2], tv[2];

  tx[0] = x[0];
  tx[1] = x[1];
  tv[0] = v[0];
  tv[1] = v[1];
  xk1 = dt*tv[0];
  yk1 = dt*tv[1];
  vxk1 = dt*fx(t, tx, tv);
  vyk1 = dt*fy(t, tx, tv);

  tx[0] = x[0] + 0.5*xk1;
  tx[1] = x[1] + 0.5*yk1;
  tv[0] = v[0] + 0.5*vxk1;
  tv[1] = v[1] + 0.5*vyk1;
  xk2 = dt*tv[0];
  yk2 = dt*tv[1];
  vxk2 = dt*fx(t + 0.5*dt, tx, tv);
  vyk2 = dt*fy(t + 0.5*dt, tx, tv);

  tx[0] = x[0] + 0.5*xk2;
  tx[1] = x[1] + 0.5*yk2;
  tv[0] = v[0] + 0.5*vxk2;
  tv[1] = v[1] + 0.5*vyk2;
  xk3 = dt*tv[0];
  yk3 = dt*tv[1];
  vxk3 = dt*fx(t + 0.5*dt, tx, tv);
  vyk3 = dt*fy(t + 0.5*dt, tx, tv);

  tx[0] = x[0] + xk3;
  tx[1] = x[1] + yk3;
  tv[0] = v[0] + vxk3;
  tv[1] = v[1] + vyk3;
  xk4 = dt*tv[0];
  yk4 = dt*tv[1];
  vxk4 = dt*fx(t + dt, tx, tv);
  vyk4 = dt*fy(t + dt, tx, tv);

  x[0] += (xk1 + 2.0*(xk2 + xk3) + xk4)/6.0;
  x[1] += (yk1 + 2.0*(yk2 + yk3) + yk4)/6.0;
  v[0] += (vxk1 + 2.0*(vxk2 + vxk3) + vxk4)/6.0;
  v[1] += (vyk1 + 2.0*(vyk2 + vyk3) + vyk4)/6.0;
}

double distance(){

}

double gravity(double G){


}

int main(){


    return 0;
}