Debug Code
----------

Insert breaks
~~~~~~~~~~~~~

::

	->'break line'
	

Trace errors
~~~~~~~~~~~~

``)trace`` or ``)TRACE`` is designed for printing error messages after
a runtime error occurs.

::
	
	//after an error occurs
	)trace
	//if more lines should be printed
	)trace 50
	
An example
~~~~~~~~~~

Add a break line ``->'stop after while'`` into the script ``TSORT.esf``
under the ``ws`` folder.

::

	@.Z<-TSORT G;N;ML
	L<-!0
	S<-(0=+/.G)/GL<-!1^.#G
	while(0<#S){
	L<-L,N<-S[1]
	S<-1!.S
	ML<-G[N;]/GL
	G[N;ML]<-0
	S<-S,(0=+/.G[;ML])/ML
	}
	->'stop after while'
	if(0<+/+/G)Z<-'Graph G is not a cyclic'
	else Z<-L
	@.


After the script is saved, it can be executed in interpreter environment.

- ``TSORT G`` triggers an error, then the program is terminated.
- ``)TRACE`` prints the error messages as follows.

::

		  )fload tsort
	saved 2015.11.19 00:32:06 (gmt-5)
		  TSORT G
	stop after while
	Error: 
	TSORT[12]  ->'stop after while'
                     ^
		  )TRACE
	name[ 100]: TSORT
	total lines:  18 step    line  content
	[  53]  [  5]  S<-1!.S
	[  54]  [  6]  ML<-G[N;]/GL
	[  55]  [  7]  G[N;ML]<-0
	[  56]  [  8]  S<-S,(0=+/.G[;ML])/ML
	[  57]  [  9]  
	[  58]  [ 10]  ->L0
	[  59]  [  3]  L0:->(~0<#S)/L1
	[  60]  [  4]  L<-L,N<-S[1]
	[  61]  [  5]  S<-1!.S
	[  62]  [  6]  ML<-G[N;]/GL
	[  63]  [  7]  G[N;ML]<-0
	[  64]  [  8]  S<-S,(0=+/.G[;ML])/ML
	[  65]  [  9]  
	[  66]  [ 10]  ->L0
	[  67]  [  3]  L0:->(~0<#S)/L1
	[  68]  [ 11]  L1:
	[  69]  [ 12]  ->'stop after while'
	--trace--version--0.02a--
      

