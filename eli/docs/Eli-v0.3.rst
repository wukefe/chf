Release Note (v0.3)
===================

Overview
--------

Version :sup:`0.3`
~~~~~~~~~~~~~~~~~~~~

ELI version 0.3 |ELI New| has been released on August 10, 2015. In this new
version, ELI system has been greatly improved by adding several useful
functions for database systems. The debut of ELI Studio shows a
preliminary, but productive IDE for developers, especially for
beginners. Moreover, ELI Studio is a cross-platform version for Windows,
Linux and MacOS.

Prior Version :sup:`0.2a`
~~~~~~~~~~~~~~~~~~~~~~~~~~~

The last stable ELI interpreter was released on November 30, 2013. At
the time, it supported most of the functionality of the ISO APL
standard. Moreover, we introduced **dictionaries**, **tables** and
**SQL-like statements** to enhance ELI system. Compared with a compiled
language, an interpreted language is more attractive to users by
providing an interactive environment. Two tutorials have been released
since the last update: <`Programming with arrays`_\ > and <`ELI for
Kids`_\ >. Moreover, `ELI primer`_ and other documents also have been
updated and can be found in `online documents`_.

Highlights
----------
Many new features are introduced in this newly released
version; we also fixed several old bugs and made effort to improve the
ELI system.

ELI Studio
~~~~~~~~~~

-  New IDE support for ELI

Like
~~~~

-  ``like`` is similar to the classic database string pattern matching
   and regular expression search

   ::

       'name.cpp'  like '%.cpp'    //1
       'eli1.esf'  like 'eli_.esf' //1
       'eli23.esf' like 'eli_.esf' //0

Match
~~~~~

-  New primitive function match (``~``) checks the value of two
   variables, returns either same (1) or not (0). Usually, match is used
   in debugging programs to check the variable value.
   
   |Measure Match|

Printing Precision Control
~~~~~~~~~~~~~~~~~~~~~~~~~~

-  ``[]PP`` controls the precision of the output of floating point

   |Control Floating Precision|

Performance Measurement
~~~~~~~~~~~~~~~~~~~~~~~

-  ``)time`` is able to measure the one line execution time

   |Measure Time|

Standard Input
~~~~~~~~~~~~~~

-  ``[]`` with standard input from users

   |Standard Input|
   |Input Result|

Date-Time Attributes
~~~~~~~~~~~~~~~~~~~~

-  Temporal attributes for date & time types (i.e. d.year)

   |Date Time|

File Handle
~~~~~~~~~~~

-  To output to afile, ELI provides\ ``[]open`` and ``[]close`` which
   open and close a file handle respectively. With a ``[]open``, a file
   handle will be returned for further output. The syntax looks like
   C++'s stream output (``std::out<<'text'``).
-  *Save value in a **file1.txt.** *

   |File Handler Code|
-  *Find the saved file under the current directory*

   |Saved File|
-  In Input, ``[]get`` imports data from 'text files' as lists. In each
   item of the list, it is one line string. On the other words, the size
   of the list is the number of rows in the designated file.
   
   |image0|

-  A table can be output by ``[]write`` with four kinds of format
   support so far. They are ``csv``, ``xml``, ``json`` and ``txt``. The
   default format is ``txt``. The designated format is defined by the
   suffix of the output filename. \*\* *Note* \*\*: == The file name
   should be the same as the table's name. ==
-  Create a table in interpreter and save it as a csv file. The output
   file can be found in the current workspace directory.
   
   |Save CSV|
-  Try extra three formats.

   |Other 3 formats|
-  A screenshot of the csv file

   |image3|
-  A screenshot of the xml file

   |image4|
-  A screenshot of the json file

   |image5|
-  A screenshot of the txt file

   |image6|

Semi Colon (``;``)
~~~~~~~~~~~~~~~~~~

-  In most programming languages (C, Java and etc.), the semicolon is
   popular to be used at the end of one statement. It also enables
   multiple statements written in single line. In ELI, one line may
   contain multiple statements which are executed from *left to right*.
   However, the execution order inside the statements follows ELI native
   order: *from right to left*.
   
   |Semi Colon|

More Data types
~~~~~~~~~~~~~~~

-  +---------------+--------------+----------+---------------------------+
   | Type          | Type Value   | Symbol   | Example                   |
   +===============+==============+==========+===========================+
   | Boolean       | 0            | B        | 0,1                       |
   +---------------+--------------+----------+---------------------------+
   | Integer       | 1            | I        | 123                       |
   +---------------+--------------+----------+---------------------------+
   | Float         | 2            | E        | 2.5                       |
   +---------------+--------------+----------+---------------------------+
   | Char          | 3            | C        | 'abc'                     |
   +---------------+--------------+----------+---------------------------+
   | Complex       | 4            | X        | 1.5j2                     |
   +---------------+--------------+----------+---------------------------+
   | Symbol        | 5            | S        | \`ibm                     |
   +---------------+--------------+----------+---------------------------+
   | List          | 6            | L        | (\`chen \`wu;10 20)       |
   +---------------+--------------+----------+---------------------------+
   | Month         | 7            | M        | 2012.08m                  |
   +---------------+--------------+----------+---------------------------+
   | Date          | 8            | D        | 2012.08.15                |
   +---------------+--------------+----------+---------------------------+
   | Datetime      | 9            | Z        | 2012.08.15T13:25:17.357   |
   +---------------+--------------+----------+---------------------------+
   | Minute        | 10           | U        | 13:25                     |
   +---------------+--------------+----------+---------------------------+
   | Second        | 11           | V        | 13:25:17                  |
   +---------------+--------------+----------+---------------------------+
   | Time          | 12           | T        | 13:25:17.357              |
   +---------------+--------------+----------+---------------------------+
   +---------------+--------------+----------+---------------------------+
   | Enumeration   | 21           | N        | ...                       |
   +---------------+--------------+----------+---------------------------+
   +---------------+--------------+----------+---------------------------+
   | Dictionary    | 91           | Y        | ...                       |
   +---------------+--------------+----------+---------------------------+
   | Keyed Table   | 91           | K        | ...                       |
   +---------------+--------------+----------+---------------------------+
   | Table         | 92           | A        | ...                       |
   +---------------+--------------+----------+---------------------------+
   

   
Improvement
~~~~~~~~~~~

-  Short function is able to define recursive functions (call itself)
-  Better support for control structure
-  Fix some trivial bugs

ELI Studio
----------
The main reason we introduce ELI studio is to offer a consistent
release for cross-platform ELI system. Because in prior versions we
only support GUI on Windows, people with Linux and Mac OS have to use
command line input In fact, popular Linux versions (i.e. Ubuntu) and Mac OS
have an excellent GUI interface for users. With an integrated
development environment (IDE), newbies have less stress to learn a new
programming language.

The ELI Studio has two parts: main window and code editor. The main
window is a terminal window which enables developers to test their code
easily. Since ELI provides scripting facilities (eli script file, called
``esf``), a code editor is a good addition for developers to build and
test scripts efficiently.

Main Window
~~~~~~~~~~~

Inherited from previous ELI version on Windows, the main window accepts the
basic layouts with normal six spaces ahead of an input line to clearly
differentiate with the following line of system response. Also, the multiple
line editing (see example 1) is enabled.

There are some new features as follows.

-  Paste with multiple lines can be handled just like executing line by line
   except the last line
-  Three widgets monitor functions and variables in the workspace, ELI
   scripts in the current directory and command history respectively
-  Click on the ELI script widget, then the selected script will be
   automatically loaded into the workspace
-  Click on a line in the command history widget, then the selected command
   will be copied into the main window and executed
-  Additional functionalities that can be found on menus are workspace load and
   save, workspace path setting and offline documentation support

Code Editor
~~~~~~~~~~~

Code Editor is an option for users to easily write and test code in ELI
interpreter environment. It is designed for fast loading of scripts and line-by-line
execution. Other than basic operations such as editing (i.e. load, save,
undo and redo), it provides the following additional features for ELI developers.

-  A symbol table (CTRL+T) that helps newbies to easily remember and
   understand primitive symbols.
-  |fload| Loading scripts into workspace. The scripts should be in esf
   format which has been saved somewhere on your computer. It has the
   same effect as you type ``)fload yourscript`` in the main window if
   you have saved the scripts under the current workspace path.
-  |fcopy| Copying scripts into the workspace. Unlike the loading
   scripts into workspace, it does not clear the whole workspace before
   loading the saved content. Therefore, it is a safe way to load your
   scripts without clearing out the existing workspace.
-  |code copy| Executing selected blocks of code as a script. It is
   useful for loading functions, variables and multiple lines of code.
   Since the function and variable definitions (with ``@.`` and ``&``)
   are not accepted in interpreter input, this facility eases the work
   of saving scripts every time.
-  |oneline| One line where the current cursor stays will be executed
   and the cursor doesn't move after the execution.
-  |oneline2| One line will be executed and the cursor will
   automatically move to the following line. It is a debugging tool to
   test code one by one line.

.. _Programming with arrays: http://fastarray.appspot.com/res/ProgELI.pdf
.. _ELI for Kids: http://fastarray.appspot.com/res/ELI4Kids.pdf
.. _ELI primer: http://fastarray.appspot.com/res/Eli_Primer.pdf
.. _online documents: http://fastarray.appspot.com/document.html

.. |ELI New| image:: http://fastarray.appspot.com/pic/new_flag.gif
.. |Measure Match| image:: http://fastarray.appspot.com/releasenote/image/qt-match.png
.. |Control Floating Precision| image:: http://fastarray.appspot.com/releasenote/image/qt-pp.png
.. |Measure Time| image:: http://fastarray.appspot.com/releasenote/image/qt-time.png
.. |Standard Input| image:: http://fastarray.appspot.com/releasenote/image/qt-quad-input.png
.. |Input Result| image:: http://fastarray.appspot.com/releasenote/image/qt-quad-result.png
.. |Date Time| image:: http://fastarray.appspot.com/releasenote/image/qt-time-attr.png
.. |File Handler Code| image:: http://fastarray.appspot.com/releasenote/image/fh-code.png
.. |Saved File| image:: http://fastarray.appspot.com/releasenote/image/fh-save.png

.. |image0| image:: http://fastarray.appspot.com/releasenote/image/quad-get.png
.. |Save CSV| image:: http://fastarray.appspot.com/releasenote/image/table-out.png
.. |Other 3 formats| image:: http://fastarray.appspot.com/releasenote/image/table-format3.png
.. |image3| image:: http://fastarray.appspot.com/releasenote/image/table-csv.png
.. |image4| image:: http://fastarray.appspot.com/releasenote/image/table-xml.png
.. |image5| image:: http://fastarray.appspot.com/releasenote/image/table-json.png
.. |image6| image:: http://fastarray.appspot.com/releasenote/image/table-txt.png
.. |Semi Colon| image:: http://fastarray.appspot.com/releasenote/image/semicolon.png

.. |fload| image:: http://fastarray.appspot.com/releasenote/image/load-script.png
.. |fcopy| image:: http://fastarray.appspot.com/releasenote/image/copy-script.png
.. |code copy| image:: http://fastarray.appspot.com/releasenote/image/copy2-code.png
.. |oneline| image:: http://fastarray.appspot.com/releasenote/image/exec.png
.. |oneline2| image:: http://fastarray.appspot.com/releasenote/image/exec-step.png
