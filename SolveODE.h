#pragma once

#include <vector>
#include <iostream>

class ODE
{
    std::vector<double> parameters;
    std::vector<std::vector<double>> table;
    double h;

public:
    ODE(std::vector<double> parameters_in, double h_in);

    std::vector<double> solve_euler();
    std::vector<double> solve_runge_kutta();
    double rk_delta_y(int i);
    double function(int i);
    double rk_function(double x, double y);

};