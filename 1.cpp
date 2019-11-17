#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

const double W = M_PI;

void euler(std::vector<double> & data, double t, double h);
void rk4(std::vector<double> & data, double t, double h);
double f(int idx, double t, const std::vector<double> & y);

int main()
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double TO = 0.0; 
  const double TF = 3*2*M_PI/W;
  const int DIM = 2;
  std::vector<double> data {3.21, 0.0}; // {X0, V0}
  
  for (double h = 1.0; h >= 1/std::pow(2, 14); h *= 0.5) {
     int N = TF/h;
     for (int M = 0; M <= N; ++M) {
       double t = TO + M*h;
       if (t == TF) {
	 rk4(data, t, h);
 	 //euler(data, t, h);
    std::cout << h << "\t" << data[0] << std::endl;
       }
     }
  }
  
  return 0;
}

double f(int idx, double t, const std::vector<double> & y)
{
  if (0 == idx) {
    return y[1];
  }
  else if (1 == idx) {
    return -W*W*y[0];
  }
  else {
    std::cerr << "ERROR! id doesn't exist: " << idx << std::endl;
    exit(1);
  }
}

void euler(std::vector<double> & data, double t, double h)
{
  std::vector<double> datatmp = data; 
  for (int ii = 0; ii < data.size(); ++ii) {
    data[ii] = datatmp[ii] + h*f(ii, t, datatmp);
  }
}

void rk4(std::vector<double> & data, double t, double h)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(data.size());
  k2.resize(data.size());
  k3.resize(data.size());
  k4.resize(data.size());
  aux.resize(data.size());

  //k1
  for(int ii = 0; ii < data.size(); ++ii) {
    k1[ii] = h*f(ii, t, data);
  }

  //k2 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k1[ii]/2;
  }
  //k2
  for(int ii = 0; ii < data.size(); ++ii) {
    k2[ii] = h*f(ii, t + h/2, aux);
  }

  //k3 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k2[ii]/2;
  }

  //k3
  for(int ii = 0; ii < data.size(); ++ii) {
    k3[ii] = h*f(ii, t + h/2, aux);
  }

  //k4 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k3[ii];
  }

  //k4
  for(int ii = 0; ii < data.size(); ++ii) {
    k4[ii] = h*f(ii, t + h, aux);
  }  

  // write new data
  for(int ii = 0; ii < data.size(); ++ii) {
    data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
  }
}
