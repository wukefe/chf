System Functions and Variables
------------------------------

``[]CR`` Display Function
~~~~~~~~~~~~~~~~~~~~~~~~~

Given a function name as right parameter, ``[]CR`` returns the source code
of the function in a character matrix.  The extra space in a line will be
filled with blanks.

::

	[]CR 'function name' //two quotes are required


``[]open`` and ``[]close``
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 2
   
   * - h<-[]open v
     - Open a file and start file stream
   * - t<-[]close h
     - Close file stream with specified file handler
   * - v
     - String, presents the path of the designated file
   * - h
     - File handler with integer value greater equal than 1000

Usually, ``[]open`` and ``[]close`` are used in pairs.
``[]open`` opens a file and saves a handler for file streaming and
``[]close`` safely closes the file stream at the end of writing.
``[]open`` allows multiple file open on a same file, but a different
file handler will be returned.  ``[]close`` checks the file handler
before it is closed.  If it is a valid one, it will be closed
immediately with return value 0. Otherwise, an integer 1 should be returned.

``[]RL`` Random Link
~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 2
   
   * - []RL
     - Output the current random seed
   * - []RL<-v
     - Set random seed for random number generator 
   * - v
     - Positive integer scalar
   * - Default value
     - 16807

::

         []RL
   16807
         ?.100
   14
         []RL
   282475249
         ?.100
   76

::

         []RL
   16807
         5?.100
   14 76 46 54 22
         []RL
   470211272
         5?.100
   5 68 94 39 52
   

After the random number is generated with a random seed ([]RL),
[]RL is reset for next computation.

::

         []RL<-16807
         []RL
   16807
         ?.100
   14



``[]PP`` Printing Precision
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - []PP<-V
     - Set the precision of printing for floating point and complex number
   * - V
     - Positive integer scalar
   * - Default value
     - 10

[]PP is a system variable and its value should be greater than 0.
On the other words, the minimal value of []PP is 1.  []PP controls
the output precision of the floating point and complex number.

::

         []PP
   10
         1%3
   0.3333333333
         []PP<-6
         1%3
   0.333333

::

         []PP
   10
         2j3%3
   0.6666666667j1
         []PP<-6
         2j3%3
   0.666667j1

Except floating point and complex number, []PP does not take effect
on integer and any other types.

::

         []PP<-1
         333
   333
         333.0
   3e2









