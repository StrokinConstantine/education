#include <iostream>
#include <cmath>

double f( double x, double y )
{
	return std::sin( x * y );
}

int main()
{
	double x_0 = 0.1;
	double y_0 = 0.1;
	double d = 0.1;
	
	double dx[] = {d, -d, 0.0, 0.0};
	double dy[] = {0.0, 0.0, d, -d};
	
	double new_x;
	double new_y;
	
	bool best_found = false;
	
	double max_f = f(x_0, y_0);
	
	while ( !best_found )
	{
		best_found = true;
		
		for ( size_t i = 0; i < 4; ++i )
		{
			double new_f = f(x_0 + dx[i], y_0 + dy[i]);
			if ( new_f < max_f )
			{
				max_f = new_f;
				best_found = false;
				new_x = x_0 + dx[i];
				new_y = y_0 + dy[i];
			}
		}
		
		if ( !best_found )
		{
			x_0 = new_x;
			y_0 = new_y;
		}
	
	}
	

	
	std::cout << "minimum of f:" << max_f << "; x = " << x_0 << "; y = " << y_0 << std::endl;
}