Type and Shape
--------------

Even though ELI does not require explicit type in front of variables, it needs
types for every computation as well.  A variable with a specific type at one time
also has a shape.  Since ELI is designed for array based computation, it is
necessary to remember the shape of an array that can be a scalar, a vector or
an array.

Basic Types
~~~~~~~~~~~

+---------------+---------+----------+--------+---------------------------+
| Type          | Value   | Symbol   | Null*  | Example                   |
+===============+=========+==========+========+===========================+
| Boolean       | 0       | B        | 0n     | 0,1                       |
+---------------+---------+----------+--------+---------------------------+
| Integer       | 1       | I        | 0n     | 123                       |
+---------------+---------+----------+--------+---------------------------+
| Float         | 2       | E        | 0nf    | 2.5                       |
+---------------+---------+----------+--------+---------------------------+
| Char          | 3       | C        | "      | 'abc'                     |
+---------------+---------+----------+--------+---------------------------+
| Complex       | 4       | X        | 0nx    | 1.5j2                     |
+---------------+---------+----------+--------+---------------------------+
| Symbol        | 5       | S        | \`     | \`ibm                     |
+---------------+---------+----------+--------+---------------------------+
| List          | 6       | L        | ()     | (\`chen\`wu;10 20)        |
+---------------+---------+----------+--------+---------------------------+
| Month         | 7       | M        | 0nm    | 2012.08m                  |
+---------------+---------+----------+--------+---------------------------+
| Date          | 8       | D        | 0nd    | 2012.08.15                |
+---------------+---------+----------+--------+---------------------------+
| Datetime      | 9       | Z        | 0nz    | 2012.08.15T13:25:17.357   |
+---------------+---------+----------+--------+---------------------------+
| Minute        | 10      | U        | 0nu    | 13:25                     |
+---------------+---------+----------+--------+---------------------------+
| Second        | 11      | V        | 0nv    | 13:25:17                  |
+---------------+---------+----------+--------+---------------------------+
| Time          | 12      | T        | 0nt    | 13:25:17.357              |
+---------------+---------+----------+--------+---------------------------+
| Enumeration   | 13      | N        | 0ne    | ...                       |
+---------------+---------+----------+--------+---------------------------+
| Dictionary    | 14      | Y        | 0ny    | ...                       |
+---------------+---------+----------+--------+---------------------------+
| Keyed Table   | 15      | K        | 0nk    | ...                       |
+---------------+---------+----------+--------+---------------------------+
| Table         | 16      | A        | 0na    | ...                       |
+---------------+---------+----------+--------+---------------------------+

\* Note: Currently, null value is only available in *Boolean*, *Integer*, *Float*,
*Char*, *Symbol* and *List*.
   
The types can be classified into the following two groups.

1. Basic types:
    boolean, integer, float, char, complex, symbol, month, date,datetime, minute
    second, time
2. Advanced types:
    list, enumeration, dictionary, keyed table and table


Type Inference
~~~~~~~~~~~~~~

ELI follows some conventional type rules while new type rules because of
new advanced types.  ELI does not implicitly do casting for the result
after one computation.  Instead, ELI leaves it to developers that makes
the system more consistant.

- The arithmatic operations between boolean, int and double are the same as 
  common languages such as C and Java.
- Primitive functions like circle can generate complex numbers even input
  data is not a complex number.  For example, ``_1*.0.5`` (equivalent
  to sqrt(-1)) is 0j1 in ELI.
- Table and dictionary can be transformed from each other if conditions are
  satisfied. (Check the primitive function ``transpose &.``)


Shape
~~~~~

There are 7 basic shapes for basic types.

+-----------------+------------------------------+
| Shape           | Example                      |
+=================+==============================+
| scalar          | x <- 2                       |
+-----------------+------------------------------+
| one-item vector | x <- ,2                      |
+-----------------+------------------------------+
| vector          | x <- 1 2 3                   |
+-----------------+------------------------------+
| matrix          | x <- 2 2#1 2 3 4             |
+-----------------+------------------------------+
| high-dimension  | x <- 2 2 2#!8                |
+-----------------+------------------------------+
| list            | x <- (1 2; 2.5 9; 'hello')   |
+-----------------+------------------------------+
| table           | x <- ([]int<-1 2;flt<-2.3 5) |
+-----------------+------------------------------+

\* Note: For advanced types, they are formed by list and table shapes.
And the two shapes are based on other basic types.




