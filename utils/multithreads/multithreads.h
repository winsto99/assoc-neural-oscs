/*
	multithreads.h - header info for multithreading



*/

#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4 //NUMBER OF THREADS FOR MULTI-THREADING!!!

typedef struct {
    int id;		//Thread id number
    int a;		//Start pos
    int b;		//End pos
    int res;	        //Rows
    double *DATA;	//Vector of output data
    double *DATA_IN;    //Vector of input data
} THREAD_DAT_1D;

typedef struct {
	int id;		//Thread id number
	int a;		//Start pos
	int b;		//End pos
	int resr;	//Rows
	int resc;	//Columns
	double **DATA;	//2d-array
} THREAD_DAT_2D;

//waitfor_threads - waits for threads to join
void waitfor_threads(int n, pthread_t threadps[]);

//segment_threads - segments a loop for threading
void segment_threads(int n, int a, int b, int divs[]);

