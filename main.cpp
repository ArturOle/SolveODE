#include "SolveODE.cpp"

int main()
{
    std::vector<double> parameters = {-5.8, 4.7, -0.9, 1.9, 9};

    ODE equation(parameters, 0.2);
    // equation.solve_euler();
    equation.solve_runge_kutta();

}
