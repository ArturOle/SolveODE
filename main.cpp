#include "SolveODE.cpp"

double function1( double x, double y ){
	return -5.8 * y + 4.7 * x - 0.9 * x * x;
}

double function2( double x, double y ){
	return 2 * x * y;
}

int main()
{
	double h = 0.2;
	ODE equation( function1, 1.9, 9, h );
	// std::vector<double> parameters = {-5.8, 4.7, -0.9, 1.9, 9};
	// // std::vector<double> parameters = {-5.8, 4.7, -0.9, 1, 3};

	// ODE equation(parameters, 0.2);
	std::cout << "Euler Method\n\nx; y; delta y;\n";
	equation.solve_euler();
	std::cout << "\n---------------------\n";
	std::cout << "Runge-Kutta Method\n\nx; y; delta y;\n";
	equation.solve_runge_kutta();
	std::cout << "\n---------------------\n";

}
