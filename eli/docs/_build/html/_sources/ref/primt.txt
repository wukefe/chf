
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




