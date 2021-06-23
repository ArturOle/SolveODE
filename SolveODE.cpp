#include "SolveODE.h"

ODE::ODE(std::vector<double> parameters_in, double h_in)
{
	this->parameters = parameters_in;
	this->table.push_back({0, parameters[3], 0});
	this->h = h_in;
}

void ODE::solve_euler()
{
	int i = 0;
	double x;

	for(x = 0; x <= parameters[4]; x+=h)
	{
		table.push_back({0, 0, 0});
		table[i][0] = x;
		if (i)
		{
			table[i][1] = table[i-1][1] + table[i-1][2]; 
		}

		table[i][2] = h * rk_function(table[i][0], table[i][1]);

		for (int j = 0; j < table[i].size(); j++)
			std::cout << table[i][j] << ";"; 
		
		i++;
		std::cout << std::endl;
	}
}

void ODE::solve_runge_kutta()
{
	int i = 0;
	double x;
	
	for(x = 0.0; x <= parameters[4]; x += h)
	{
		table.push_back({0, 0, 0});
		table[i][0] = x;

		if (i)
		{
			table[i][1] = table[i-1][1] + table[i-1][2];
			// y_i      = y_{i-1}       + delta y_{i-1}
		}

		table[i][2] = rk_delta_y(i); 

		for (int j = 0; j < table[i].size(); j++)
			std::cout << table[i][j] << ";"; 

		i++;
		std::cout << std::endl;
	}
}

double ODE::rk_delta_y(int i)
{
	std::vector<double> k_values = {0, 0, 0, 0};

	k_values[0] = h * rk_function(table[i][0], table[i][1]);
	k_values[1] = h * rk_function(table[i][0] + h * 0.5, table[i][1] + k_values[0] * 0.5);
	k_values[2] = h * rk_function(table[i][0] + h * 0.5, table[i][1] + k_values[1] * 0.5);
	k_values[3] = h * rk_function(table[i][0] + h, table[i][1] + k_values[2]);
	
	// std::cout << "\t";
	// for (int j = 0; j < k_values.size(); j++)
	// {
	// 	std::cout << k_values[j] << ";";
	// }
	// std::cout << "\n";
	
	return (k_values[0] + 2*k_values[1] + 2* k_values[2] + k_values[3])/6;
}


double ODE::function(int i)
{
	return parameters[0]*table[i][1] + parameters[1]*table[i][0] + parameters[2]*table[i][0]*table[i][0];
	//	 a_1 * y(x)			   + b_1 * x			 + c_1 * x^2
}


double ODE::rk_function(double x, double y)
{
	// return 2 * x * y;
	return parameters[0] * y + parameters[1] * x + parameters[2] * x * x;
	//	 a_1 * y(x)		 + b_1 * x		   + c_1 * x^2
}
