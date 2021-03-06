/* std - Calculate the standard deviation of a vector

	Arguments
		int n			Length of the vector
		double A[]		Vector for which to find the standard deviation
		
	Returns
		double thestd	The standard deviation of the vector

        
	Copyright 2012
	Brendan Hasz
	bhasz@brandeis.edu
	www.cs.brandeis.edu/~bhasz/main.php
	Brandeis University, Waltham, MA, USA

	This work is licensed under a Creative Commons NonCommercial 3.0 Unported 
	License.  You can use it and modify it any way you like as long as you 
	aren't commercially making money off it - if you are, I want some too!

*/

double
std(int n, double A[])
{
	return sqrt(var(n,A));
}
