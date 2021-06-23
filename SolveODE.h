#pragma once

#include <vector>
#include <iostream>

class ODE
{
	// std::vector<double> parameters;
	std::vector<std::vector<double>> table;

	double h;
	double upper_bound;

	double (*function)( double, double );

public:
	// ODE(std::vector<double> parameters_in, double h_in);
	ODE(
		double (*in_function)( double, double ),
		double in_y0,
		double in_upper_bound,
		double in_h
	);

	void solve_euler();
	void solve_runge_kutta();
	double rk_delta_y(int i);
	// double function(int i);
	// double rk_function(double x, double y);

};
