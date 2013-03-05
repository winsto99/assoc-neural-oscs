# Associative Neural Oscillators
`assoc-neural-oscs` is a collection of programs which simulate and explore the ability of [neural oscillators](http://en.wikipedia.org/wiki/Neural_oscillation) to "remember" phase associations amongst themselves.  Specifically, the programs study [Pyramidal-Interneuron gamma-frequency oscillators](http://www.ncbi.nlm.nih.gov/pubmed/15802007) (PING oscillators), which resemble networks found in the cortex and hippocampus.  For more information on the neuroscience behind the project, see the [literature review](http://www.cs.brandeis.edu/~bhasz/files/HaszMiller2012_Associative_Neural_Oscillators_Review.pdf) which discusses the theory which inspired the code.


# Usage
## Compiling
The project is written in C, so `gcc` and `make` are required to compile the code.  Generally each leaf directory will have a makefile, so you can simply navigate into any leaf directory and run

```bash
$ make
```

to compile the code in that directory.

## Running the code
Navigate into each of the main folders (numbered folders) and follow the directions of the README files in each.  Usually you can just navigate into a folder and execute the code by running the command

```bash
$ ./run.sh
```

There are also many math and neuroscience-related utilities in the `/utils` folder, which are used by the functions in the main folders, but which may be useful individually.

## Plotting
The routines output data into ascii text files, so you can use your preferred graphing utility.  Alternatively, you can use the provided python plotting tools in `/graphing`.  To use these tools you will need python installed, along witht the python packages [`numpy`](http://www.numpy.org/) and [`matlibplot`](http://matplotlib.org/)

The data produced by the routines in the main numbered folders can be plotted by running that folder's plot routine:

```bash
$ python plotter.py
```

## Multithreading
Some of the routines are multithreaded to take advantage of multiprocessor machines.  By default, the multithreaded routines run with 4 threads.  However, if you would like to optimize for your machine(s), you can change the number of threads by changing the value of NUM_THREADS in `/utils/multithreads/multithreads.h`.

# Copyright
Copyright (C) 2012 Brendan Hasz

[bhasz@brandeis.edu](mailto:bhasz@brandeis.edu)

[www.cs.brandeis.edu/~bhasz/main.php](http://www.cs.brandeis.edu/~bhasz/main.php)

[Brandeis University](http://www.brandeis.edu/), Waltham, MA, USA

