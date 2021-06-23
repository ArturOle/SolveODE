#include "SolveODE.cpp"

int main()
{
    std::vector<double> parameters = {-5.8, 4.7, -0.9, 1.9, 9};
    // std::vector<double> parameters = {-5.8, 4.7, -0.9, 1, 3};

    ODE equation(parameters, 0.2);
    std::cout << "Euler Method\n\nx; y; delta y;\n";
    equation.solve_euler();
    std::cout << "\n---------------------\n";
    std::cout << "Runge-Kutta Method\n\nx; y; delta y;\n";
    equation.solve_runge_kutta();
    std::cout << "\n---------------------\n";

}
