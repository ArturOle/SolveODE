# SolveODE

Numerical Methods task. Solve (first order) ordinary lineqr equations.

## Funcionality

Class ODE introduces two ways of calculating f(x) values on a set interval:

* Euler's Method
* Runge-Kutta Method

It returns a `.csv` file with `;` delimiter, containing columns:

| x  | y  | Δy  |
| -- | -- | --- |
| x0 | y0 | Δy0 |
| x1 | y1 | Δy1 |

## Usage

Creation of ODE object requires providing a pointer to a
`double function(double x, double y)`, as well as a known f(0) value, upper
bound of search and a step.

```cpp
double func( double x, double y ) {
	return 2 * x * y;
}

double y0 = 2;
double upper_bound = 3;
double h = 0.1;

ODE equation( func, y0, upper_bound, h );
equation.solve_euler();
```

In return, we will recieve a file called `euler_0.100000.csv`.
