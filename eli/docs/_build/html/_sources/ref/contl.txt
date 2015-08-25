Control Structures
------------------

ELI supports control structures with seven researved words

``if`` , ``else`` , ``case`` , ``for`` , ``while`` , ``break`` , ``continue``



for
~~~

::

	@.test_for n
	for(i:1;n){
	  []<-i
	}
	@.
	
	      test_for 5
	1
	2
	3
	4
	5


if-else
~~~~~~~

::

	@.p<-rprime n;i
	p<-2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
	if (n<=100) p<-(n>=p)/p
	else {pl<-#p<-rprime _.n*.0.5
	  b<-n#0
	  for (i:1;pl) b<-b&n#(-p[i])^.1
	  p<-p,1!.(~b)/!n
	}
	@.
	
	      rprime 300
	2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151
	157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293


while
~~~~~

::

	@.L<-TSORT G;N;ML
	L<-!0
	S<-(0=+/.G)/GL<-!1^.#G
	while (0<#S) {
	L<-L,N<-S[1]
	S<-1!.S
	ML<-G[N;]/GL
	G[N;ML]<- 0
	S<-S,(0=+/.G[;ML])/ML
	}
	if (0<+/+/G) []<-'Graph G is not acyclic.'
	@.

	      G
	0 1 0 1 0 1 0 0
	0 0 0 0 0 0 0 0
	0 0 0 1 0 0 0 1
	0 0 0 0 0 0 0 0
	1 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	1 0 0 0 0 0 0 1
	0 0 0 0 0 1 0 0

	      TSORT G
	3 5 7 1 8 2 4 6



case
~~~~

::

   @.z<-tst_cas x
   case (:x) {
    0,1:z<-x+10
    2:z<-x*10
    3:z<-x
    5:case (x) {
    `select:z<-'SELECT'
    `exec:z<-'EXEC'
    else z<-'***'
    }
    else z<-x+100
   }
   @.
   // execute
         tst_cas 9
   19
         tst_cas 1.2
   12
         tst_cas 'ABC'
   ABC
         tst_cas `ABC
   ***
         tst_cas 20:55
   22:35
   
