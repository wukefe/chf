
Semantics
---------

Basic built-in functions
~~~~~~~~~~~~~~~~~~~~~~~~

User defined functions
~~~~~~~~~~~~~~~~~~~~~~


Short functions
~~~~~~~~~~~~~~~
The format of short functions is
``{foo:line0;...;lineN}`` where
``{foo}`` is the function name and
``{line0;...;lineN}`` is the body of the function. There
are some implicit rules defined as follows.

-  If ``x`` appears, it is the right argument of the
   function

-  If ``y`` appears, it is the left argument of the
   function

-  If ``z`` appears, it is the return value of the
   function

-  Other names appear other than functions are localized as variables

-  If the last line (lineN) is not empty, the result of the line is
   returned

-  If the last line (lineN) is empty, nothing will be returned if
   ``z`` does not appear

A large program usually consists of many small functions which operate
basic computation, such as ``avg`` (See the equation below) which
returns the average of a vector or an array.
For example, ``avg !20`` takes a vector
consists of twenty numbers from 1 to 20. The expected result should be
10.5.

|eq_avg|

.. |eq_avg| image:: avg.gif
.. math equation in latex
   \displaystyle avg = (\sum_{i=1}^{N} v_i) \div N

The function ``avg`` can be defined in ELI interpreter
quickly and easily as follows.

::

          {avg: (+/x)%#x}
    avg
          avg !20
    10.5
          {avg}  //check code
    ---------avg--------
    [0]   z<-avg x
    [1]   z<-(+/x)%#x
    --------------------

The short functions usually are defined for these functions with one
line code. It provides more feasibility for fast programming to
implement bright ideas. Ideally, it reduces the time cost to create a
normal script files to load to active workspace.

