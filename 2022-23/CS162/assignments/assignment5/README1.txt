Hi Caden Burke!

1. Harry Yu, ONID: yuhar

2. fractals.cpp is a program that prints out fractals using recursion. The user will 
be asked how many stars they want to print on the longest line, which is located in the 
middle. Then, the user will be asked how many spaces they want the fractal to be shifted 
to the right. After that, the fractal will be printed in the terminal.

3. There is no Makefile for part 1. In order to run this program, type g++ fractals.cpp -o fractals 
in the terminal. Then, type ./fractals. (Don't include the last period.) The user should type what 
they want n to be. n is the number of stars on the longest line. Then, the user should type how many 
columns they want the fractal to be shifted to the right. Remember, just typing the number is not enough; 
the user must press enter after typing the number. For example, if the user chooses 3 as the number of stars 
and 2 as the number of columns, this is what should be printed out:

      *
    * * *
      *

4. The number of stars on the longest line must be a positive odd integer. In other words, n must be 1, 3, 
5, 7, etc. The number of columns should be a nonnegative integer. In addition, if the user types something very 
big for n or col, such as 1 million, the program won't work because 1 million stars is way too long.