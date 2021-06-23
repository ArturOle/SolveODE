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
    for(x = 0; x <= parameters[4]; x+=h)
    {
        table.push_back({0,0,0,0});
        table[i][0] = x;
        if (i)
        {
            table[i][1] = table[i-1][1]+table[i-1][3]; 
        }

        table[i][2] = function(i);
        table[i][3] = h*table[i][2];


        for (int j =0; j < table[i].size(); j++)
            std::cout << table[i][j] << ";"; 
        
        
        i++;
        std::cout << std::endl;

    }
}

double ODE::function(int i)
{
    return parameters[0]*table[i][1] + parameters[1]*table[i][0] + parameters[2]*table[i][0]*table[i][0];
}
