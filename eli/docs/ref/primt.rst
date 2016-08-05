
Primitive Functions
-------------------

.. .. Note::
..   This section introduces the basics of primitive functions.

.. role::strike

Testing :strike:`what`.


.. include:: primt/bigtable.txt
.. include:: primt/monadic.txt
.. include:: primt/dyadic.txt
.. include:: primt/mixed.txt

Convensions
===========

+--------+------------------+------------------------------------------+
| Name   |     Description  |   Explanation                            |
+========+==================+==========================================+
|PF(X,Y) |Primitive function| X: monadic; Y: dyadic                    |
+--------+------------------+------------------------------------------+
| L      | Left argument    | Any type of data (optional)              |
+--------+------------------+------------------------------------------+
| R      | Right argument   | Any type of data (mandatory)             |
+--------+------------------+------------------------------------------+
| Z      | Return value     | Always available even it is a nil value  |
+--------+------------------+------------------------------------------+
| RHO    | Return shape     | The shape of a variable                  |
+--------+------------------+------------------------------------------+
| TYPE   | Return type      | The type of a variable                   |
+--------+------------------+------------------------------------------+


\! (iota,find)
~~~~~~~~~~~~~~

* Monadic (``Z <- ! R``)

1. RHO(Z) = VECTOR, RHO(R) = VECTOR or SCALAR
2. TYPE(R) = TYPE(Z) = INTEGER

Examples:

.. code-block:: none
    
        !5
    1 2 3 4 5
        !2.3
    Error: domain error
        !2.3
        ^

* Dyadic (``Z <- L ! R``)

1. RHO(Z) = RHO(R)
2. If TYPE(L) and TYPE(R) are NUMERIC, return the index of R in L if found or 0 otherwise
3. Else always return 0

.. code-block:: none

        5 1 7 9 3 7 ! 5
    1
        5 1 7 9 3 7 ! 7
    3


-----



\#  (Rho,Reshape)
~~~~~~~~~~~~~~~~~

* Monadic (``Z <- # R``)

Examples:

.. code-block:: none

        #1 2 3
   3
        #(1 2 3;'life';`symbol;2j3)
   4



* Dyadic (``Z <- L # R``)


-----

\< \<=  (Great_up,Less)
~~~~~~~~~~~~~~~~~~~~~~~

* Monadic (``Z <- <R``)

.. code-block:: none

          a
    54 22 5 68 94 39 52 84 4 6
          <a  //returns index
    9 3 10 2 6 7 1 4 8 5
          a[<a]
    4 5 6 22 39 52 54 68 84 94

* Dyadic (``Z <- L<R``)

.. code-block:: none

          a
    54 22 5 68 94 39 52 84 4 6
          a < 50
    0 1 1 0 0 1 0 0 1 1

-----

\> \>= (Great_down,Greater)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

* Monadic (``Z <- >R``)

.. code-block:: none

          a
    54 22 5 68 94 39 52 84 4 6
          >a //returns index
    5 8 4 1 7 6 2 10 3 9
          a[>a]
    94 84 68 54 52 39 22 6 5 4

* Dyadic (``Z <- L>R``)

.. code-block:: none

          a
    54 22 5 68 94 39 52 84 4 6
          a > 50
    1 0 0 1 1 0 1 1 0 0

-----

\^ (Count,And)
~~~~~~~~~~~~~~

* Monadic (``Z <- ^R``)

.. code-block:: none

          ^ 1 0 1
    3

* Dyadic (``Z <- L^R``)

.. code-block:: none

          1 0 1 ^ 0 1 1
    0 0 1

-----

\& (--,Or)
~~~~~~~~~~

* Monadic (N/A)

* Dyadic (``Z <- L&R``)

.. code-block:: none

          1 0 1 & 0 1 1
    1 1 1

-----

\!. (Execute,Drop)
~~~~~~~~~~~~~~~~~~

* Monadic (``Z <- !.R``)

.. code-block:: none

          !.'2 + 3'
    5

* Dyadic (``Z <- L!.R``)

.. code-block:: none

          1 !. 1 2 3
    2 3

-----

\^. (Take1,Take)
~~~~~~~~~~~~~~~~

* Monadic (``Z <- ^.R``)

* Dyadic (``Z <- L^.R``)


-----

\, (Ravel,Concatenate)
~~~~~~~~~~~~~~~~~~~~~~

* Monadic (``Z <- ,R``)

* Dyadic (``Z <- L,R``)

-----

\+ (Sign,Plus)
~~~~~~~~~~~~~~

* Monadic (``Z <- +R``)

* Dyadic (``Z <- L+R``)

-----

\- (Negative,Minus)
~~~~~~~~~~~~~~~~~~~

* Monadic (``Z <- -R``)

* Dyadic (``Z <- L-R``)

-----

\* (xxxx,Mutiply)
~~~~~~~~~~~~~~~~~

* Monadic (``Z <- *R``)

* Dyadic (``Z <- L*R``)

-----

\% (Single divide,Divide)
~~~~~~~~~~~~~~~~~~~~~~~~~

* Monadic (``Z <- %R``)

* Dyadic (``Z <- L%R``)

-----

\$ (Rotate)
~~~~~~~~~~~

* Monadic (``Z <- $R``)

* Dyadic (``Z <- L$R``)

-----

\&. (transpose)

-----

\*.


