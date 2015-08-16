# Demo Code

## Arithmetic Computation

```
      1+5
6
      1 + 5 6 7     // scalar and vector
6 7 8
      2 * 3 + 9     // right to left execution
24
      2 * ( 3 + 9 ) // parenthesis last
24
      (2 * 3) + 9   // parenthesis first
15
```

## Matrix and Array

```
      !25
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
      5 5#!25   //5x5 matrix
 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
      2 3 4#!25 //2x3x5 array
 1  2  3  4
 5  6  7  8
 9 10 11 12

13 14 15 16
17 18 19 20
21 22 23 24
```

## Workspace and Scripts
- A workspace is a file with extension `.eli`
- A script is a file with extension `.esf`

`)save demo1`   //save to demo1.eli
`)load demo1`   //load demo1
`)fload script` //load script

## Code Editor
Code Editor is an option for users to easily write and test code in ELI interpreter.  It is designed with fast loading scripts and line-by-line execution.  Other than basic operations as an editor (i.e. load, save, undo and redo), it provides additional features for ELI developers.

- A symbol table (CTRL+T) helps newbies to easily remember and understand primitive symbols.
- ![fload](http://fastarray.appspot.com/releasenote/image/load-script.png) Loading scripts into workspace.  The scripts should be in esf format which has been saved somewhere on your computer.  It has the same effect as you type `)fload yourscript` in the main window if you have saved the scripts under the current workspace path.
- ![fcopy](http://fastarray.appspot.com/releasenote/image/copy-script.png) Copying scripts into the workspace.  Unlike the loading scripts into workspace, it does not clear the whole workspace before loading the saved content.  Therefore, it is a safe way to load your scripts without clearing out the existing workspace.
- ![code copy](http://fastarray.appspot.com/releasenote/image/copy2-code.png) Executing selected blocks of code as a script.  It is useful for loading functions, variables and multiple lines of code.  Since the function and variable definitions (with `@.` and `&`) are not accepted in interpreter input, this facility eases the work of saving scripts every time.
- ![oneline](http://fastarray.appspot.com/releasenote/image/exec.png) One line where the current cursor stays will be executed and the cursor doesn't move after the execution.
- ![oneline2](http://fastarray.appspot.com/releasenote/image/exec-step.png) One line will be executed and the cursor will automatically move to the following line.  It is a debugging tool to test code one by one line.


