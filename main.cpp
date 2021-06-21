#include "SolveODE.cpp"

int main()
{
    std::vector<double> parameters = {-5.8, 4.7, -0.9, 1.9, 9};

    ODE *equation = new ODE(parameters, 0.2);
    std::cout<< equation->function(0)<<std::endl;
    delete equation;

}