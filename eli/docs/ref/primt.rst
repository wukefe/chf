
Primitive Functions
-------------------


+--------+------------------+------------------------------------------+
| Name   | ``Description``  | ``Explanation``                          |
+========+==================+==========================================+
| L      | Left argument    | Any type of data (optional)              |
+--------+------------------+------------------------------------------+
| R      | Right argument   | Any type of data (mandatory)             |
+--------+------------------+------------------------------------------+
| Z      | Return value     | Always available even it is a nil value  |
+--------+------------------+------------------------------------------+

\! (iota,find)
~~~~~~~~~~~~~~~~~

* Monadic (``Z <- ! R``)

The type of R should be integer.

The shape of R should be a scalar or a one-item vector.

Examples:

.. code-block:: none
    
        !5
    1 2 3 4 5
        !2.3
    Error: domain error
        !2.3
        ^

* Dyadic (``Z <- L ! R``)


.. code-block:: none

        5 1 7 9 3 7 ! 5
    1
        5 1 7 9 3 7 ! 7
    3






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




