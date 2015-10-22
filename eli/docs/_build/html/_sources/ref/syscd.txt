System Commands
---------------

``)off`` Close All
~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - Parameter
     - Description
   * - ---
     - Close and exit Eli interpreter



``)fns`` List Functions
~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - Parameter
     - Description
   * - ---
     - List all functions in the current workspace
   * - Name
     - List the functions match the provided name as prefix in the current workspace
	 
Example:

::

         )fload rprime
         rprime 120
   2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113
   saved 2012.03.26 22:21:14 (gmt-4)
         )fns
   rprime
         )fns r
   rprime



``)vars`` List Variables
~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - Parameter
     - Description
   * - ---
     - List all variables in the current workspace
   * - Name
     - List the variables match the provided name as prefix in the current workspace

	 
Example:

::

         day1<-2011.11.22
         day2<-day1+1
         year1<-2012
         year2<-2=year1+1
         )vars
   day1   day2   year1   year2
         )vars d
   day1   day2
         )vars y
   year1   year2
	

	
``)lib`` List Libraries
~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - Parameter
     - Description
   * - ---
     - List all script files in the current workspace
   * - Name
     - List the script files match the provided name as prefix in the current workspace

.. )dir/)ls Print Directory
.. (pending function)

``)si`` Print Error Stack
~~~~~~~~~~~~~~~~~~~~~~~~~

``)clear`` Clear Workspace
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - Parameter
     - Description
   * - ---
     - Clear workspace as the beginning of interpreter starts

`Note:` All functions and variables are wiped out from the current workspace.
Moreover, all system variables are reset.
	 
``)wsid`` Rename workspace
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :widths: 5 20
   :header-rows: 1
   
   * - Parameter
     - Description
   * - ---
     - Returns the current name of workspace if it has been set up. Otherwise, ``CLEAR WS`` is returned.
   * - Name
     - Set the name of the current workspace

Example:

::

         )wsid
   CLEAR WS
         )wsid earth
   was CLEAR WS
         )wsid
   earth
	 
``)save`` Save workspace
~~~~~~~~~~~~~~~~~~~~~~~~

``)load`` Load Workspace
~~~~~~~~~~~~~~~~~~~~~~~~

``)fload`` Load script
~~~~~~~~~~~~~~~~~~~~~~

``)fcopy`` Copy script
~~~~~~~~~~~~~~~~~~~~~~
