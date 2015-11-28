#include <iostream>
#include <cmath>

using namespace std;

int main(){
  const int N = 2;//size of arrays
  double T = 20*M_PI;
  double dt = M_PI/100;
  double t;
  double f_0[N];//for Euler forward
  double f[N];
  double b_0[N];//for Euler backward
  double b[N];
  double a[N];//for analytic solution
  
  f_0[0] = 1;
  f_0[1] = 0;//initial conditions
  b_0[0] = 1;
  b_0[1] = 0;
  a[0] = 1;//valid for cosinus(t)
  a[1] = 0;
  
  for(t=dt; t<=T; t+=dt){
  f[0] = f_0[0] + dt*f_0[1];
  f[1] = f_0[1] - dt*f_0[0];
  
  f_0[0] = f[0];
  f_0[1] = f[1];
  
  
  b[0] = (b_0[0] + dt*b_0[1])/(1 + dt*dt);
  b[1] = (b_0[1] - dt*b_0[0])/(1 + dt*dt);
  
  b_0[0] = b[0];
  b_0[1] = b[1];
  
  a[0]=cos(t);//due to initial conditions, otherwise y-value would not be 1 for t=0!!
  a[1]=-sin(t);
  
  cout << t << "\t" << a[0] << "\t" << f[0] << "\t" << b[0] << endl;
  }
  
  return 0;
}