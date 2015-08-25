GUI Interface
-------------

When back to the early 2000, ELI was designed with GUI interface and
developed with Microsoft MFC. It provided interactive user input and
allowed programmers to write up ELI scripts within the integrated
environment. At that time, ELI could not process scripts written in ELI
while it maintained ELI workspace which contained variables, functions,
run-time stacks and system configurations. And ELI only runs on Windows.

From 2011 to 2013, we extended ELI to support more features. It was more
flexible for programmers to quickly test their code. Some of the new
features are highlighted on Windows as follows.

-  multi-line editions

-  short function

-  interactively input function

With the expansion from Windows to Linux and MacOS, we provided terminal
versions for both platforms. Without GUI interface, it seemed hard for
beginners to start ELI in a friendly environment. Especially, when
Wai-Mee was writing `ELI for kids`_, we realized that a good integrated
development environment (IDE) can attract more attention from beginners.

At present, we redesign and implement the GUI part of ELI based on `Qt
development`_. Except those existing features, we introduce some
intuitive design to ease the pain of the invisibility of the ELI
interpreter, such as variables, functions and libraries.

-  monitors for variables, functions, libraries and history commands

-  fast typing to copy/delete variable and functions

-  a well-designed code editor for learning to write ELI code easily

Because Qt is a cross-platform development tool, it can be an effortless
work to port the GUI part to popular platforms, including Windows, Linux
and MacOS.

Main window
===========

-  store three dock widgets (or more) location for next login

-  complete functions in the tool bar

-  setup wizard for automatically installing software on Windows

Code editor
===========

-  line display

-  syntax highlight

-  semantics help

-  a look-up table for ELI-APL table

Debug mode (Developing)
=======================

-  set/cancel break points (manageable)

-  while debugging, no edit is allowed

-  check temp variables and run-time stack

.. _ELI for kids: http://fastarray.appspot.com/document.html
.. _Qt development: https://en.wikipedia.org/wiki/Qt_(software)