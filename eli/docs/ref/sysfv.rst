System Functions and Variables
------------------------------

``[]open`` and ``[]close``
~~~~~~~~~~~~~~~~~~

+-------------+---------------------------------------------------------+
| h<-[]open v | Open a file and start file stream                       |
+-------------+---------------------------------------------------------+
|t<-[]close h | Close file stream with specified file handler           |
+-------------+---------------------------------------------------------+
| v           | String, presents the path of the designated file        |
+-------------+---------------------------------------------------------+
| h           | File handler with integer value greater equal than 1000 |
+-------------+---------------------------------------------------------+

Usually, ``[]open`` and ``[]close`` are used in pairs.
``[]open`` opens a file and saves a handler for file streaming and
``[]close`` safely closes the file stream at the end of writing.
``[]open`` allows multiple file open on a same file, but a different
file handler will be returned.  ``[]close`` checks the file handler
before it is closed.  If it is a valid one, it will be closed
immediately with return value 0. Otherwise, an integer 1 should be returned.

``[]RL`` Random Link
~~~~~~~~~~~~~~~~

``[]PP`` Printing Precision
~~~~~~~~~~~~~~~~~~~~~~~



