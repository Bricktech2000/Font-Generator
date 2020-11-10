Font Generator
==============
A simple programming language benchmark


Overview
--------

Font Generator is a simple benchmark for programming languages. It evaluates amount of code required to complete simple tasks:
* evaluate command line arguments
* read text files
* get text inputs and print outputs
* support for classes, maps and arrays
* handle unexpected errors


Tasks to peform
---------------

Here is a list of tasks that the program must be able to perform for this benchmark:

1. Get the *font file* name from the second command line argument, for example:
    ```
    python python.py font.txt
    ```
2. Read and parse the contents of the *font file*, which looks like this:
    ```
    0
      __
     / /
    /_/ 

    1
    
     /
    / 

    2
      __
     __/
    /_  

    ...
    ```
3. Ask the user to input some text in the command line, for instance:
    ```
    54782
    ```
4. Use the parsed *font file* to generate a larger-font version of the text typed in by the user, which would look something like this:
    ```
      __     __  __  __
     /_  /_/  / /_/ __/
    __/   /  / /_/ /_  
    ```
5. Loop back to step 3


Contributing
------------

Feel free to contribute to this project by programming this benchmark in more programming languages! Here is a list of the ones currently implemented:
* Python
* HTML
* JavaScript
* C++
