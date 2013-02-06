/*
	single_PING_group - Simulates a single PING oscillator

	Simulates a single PING oscillator with simple rate models.  The 
	system consists of a single excitatory neuron group coupled to a 
	single inhibitory neuron group.  The rate model used is the simple 
	rate model described in Ch. 7.5 of "Theoretical Neuroscience", by 
	Peter Dayan and L. F. Abbott.


	Copyright 2012
	Brendan Hasz
	bhasz@brandeis.edu
	www.cs.brandeis.edu/~bhasz/main.php
	Brandeis University, Waltham, MA, USA

	This work is licensed under a Creative Commons NonCommercial 3.0 Unported
	License.  You can use it and modify it any way you like as long as you
	aren't commercially making money off it - if you are, I want some too!

*/

#include <stdio.h>
#include "../utils/neuro/rateN.h"
#include "../utils/fileIO/fileIO.h"

int main(void)
{

	int g = 2;          //Number of groups
	int n = 9999;       //Timesteps
	double dt=0.0001;   //Duration of timestep
    
	double R[n][g];     //Rate vectors
    
	double R_i[g];      //Initial rates
		R_i[0] = 30; //Excitatory
		R_i[1] = 20; //Inhibitory
        
	double W[g][g];     //Synaptic weights
		W[0][0]=2;		W[0][1]=2.873;	//EE	EI
		W[1][0]=-2.873;	W[1][1]=-2;		//IE	II
        
	double gamma[g];    //External input
		gamma[0] = 10;      //->E cells
		gamma[1] = -10;     //->I cells
        
	double tau[g];      //Time constants
		tau[0] = 0.002; //AMPA (excitatory)
		tau[1] = 0.010;	//GABA_A (inhibitory)
	
    
    //Simulate
	rateN(g, n, R, R_i, W, gamma, tau, dt); //Simulate
	
    //Save data
	char * filename = "single_PING_group.dat";
	asave(n, g, R, filename);
	
	printf("Done!  Data saved as %s\n", filename);

	return 0;

}
