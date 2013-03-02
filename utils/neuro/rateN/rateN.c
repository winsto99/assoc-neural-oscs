/*
	rateN - Simulates a system of coupled neurons using simple rate models
    
	rateN(g, n, R[g][n], R_i[g], W[g][g], gamma[g], tau[g], dt)

	Simulates a system of coupled groups of neurons using the simple rate
    model described in Ch. 7.5 of "Theoretical Neuroscience", by Peter Dayan
    and L. F. Abbott.

	INPUTS
	int g			Number of groups to simulate
	int n			Number of timesteps to simulate
	double R[g][n]	Rate vectors of each group over time
	double R_i[g]	Initial rates for each group
	double W[g][g]	Synaptic weight matrix between groups (W[i][j]: i->j)
	double gamma[g]	Constant input to each group
	double tau[g]	Time constant of each group
	double dt		Timestep duration
	
	
	Copyright 2012
	Brendan Hasz
	bhasz@brandeis.edu
	www.cs.brandeis.edu/~bhasz/main.php
	Brandeis University, Waltham, MA, USA

	This work is licensed under a Creative Commons NonCommercial 3.0 Unported 
	License.  You can use it and modify it any way you like as long as you 
	aren't making money off it - if you are, I want some too!

*/

#include <stdio.h>

#ifndef MAX
#define MAX(x,y) (x > y ? x : y)
#endif

void rateN(int g, int n, double R[n][g], double R_i[], double W[g][g], double gamma[], double tau[], double dt)
{
    
	//Variables
	int t,i,j,l;  //counters
	double s; //sum of weights

    //PRINT INPUTS
    printf("g=%d\tn=%d\tdt=%f\n", g, n, dt);
    for (i=0; i<g; i++){ for (j=0; j<g; j++){ printf("W[%d][%d]=%f\n", i, j, W[i][j]); }}
    for (i=0; i<g; i++){  printf("[%d]\tR_i=%f\tg=%f\tt=%f\n", i, R_i[i], gamma[i], tau[i]); }

	//Initial rates
	for (i=0; i<g; i++){
		R[0][i] = R_i[i];
	}
	
	//Simulate
	for (t=1; t<=n; t++){  //for each timestep,
		l = t-1; //find last timestep
		for (i=0; i<g; i++){ //update each rate model
			s = 0;  //Reset sum
			for (j=0; j<g; j++){ //sum synaptic inputs
				s += W[j][i]*R[l][j];
			}
			R[t][i]=R[l][i]+dt/tau[i]*(-R[l][i]+MAX(0,s+gamma[i])); //integrate
		}
	}
}
