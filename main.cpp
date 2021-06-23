#include "SolveODE.cpp"

double function1( double x, double y ){
	return -5.8 * y + 4.7 * x - 0.9 * x * x;
}

double function2( double x, double y ){
	return 2 * x * y;
}

int main()
{
	std::vector<double> steps = {0.01, 0.1, 0.2};
	for( auto& h: steps ) {
		std::cout << "### Current step: " << h << " ###\n";
		ODE equation( function1, 1.9, 9, h );

		std::cout << "Euler Method\n\n";
		equation.solve_euler();
		std::cout << "\n---------------------\n";

		std::cout << "Runge-Kutta Method\n\n";
		equation.solve_runge_kutta();
		std::cout << "\n---------------------\n";
	}
}
