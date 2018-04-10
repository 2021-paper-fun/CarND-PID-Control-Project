#include "PID.h"

using namespace std;


PID::PID(double Kp, double Ki, double Kd) : Kp(Kp), Ki(Ki), Kd(Kd) {
    d_error = 0;
    p_error = 0;
    i_error = 0;
};

PID::~PID() {}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  return -Kp*p_error - Ki*i_error - Kd*d_error;
}

