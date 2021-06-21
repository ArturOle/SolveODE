#include "SolveODE.h"

ODE::ODE(std::vector<double> parameters_in, double h_in)
{
    this->parameters = parameters_in;
    this->table.push_back({0, parameters[3], 0, 0});
    this->h = h_in;
}

std::vector<double> ODE::solve_euler()
{
    int i = 0;
    double x;
    for(x = 0; x < parameters[4]; x+=h)
    {
        i++;

    }
}

double ODE::function(int i)
{

    std::cout<< table[i][1] << std::endl ;//+ parameters[1]*table[i][0] + parameters[2]*table[i][0]*table[i][0];
    return parameters[3];
}
