# c_compiler
c_compiler for UNR Compilers CS 660. This program takes in a .c file and returns a MIPS program. The MIPS program is intended to be passed into the SPIM program for execution. This repository was created to compile and run on a Linux machine with SPIM, g++, flex, and bison. The repository Wiki is [here](https://github.com/ahpalmerUNR/c_compiler/wiki)

## Table Of Contents

[Installation](#installation)

[Usage](#usage)

[Team Mate Contributions](#contributions)

[Things We Can Do](#cando)

[Things We Can't Do](#cantdo)

## Installation
Installation is done through the terminal.

If you do not have SPIM you can get it [here](https://sourceforge.net/projects/spimsimulator/files/).

To install g++, flex, or bison, perform a sudo apt-get install.
```
sudo apt-get install flex bison g++
```
First, navigate to the intended destination for the repo folder. By default, we use the Desktop.
```
cd ~/Desktop
```
The just copy the repo, and navigate into it.
```
git clone https://github.com/ahpalmerUNR/c_compiler.git
cd c_compiler
```
## Usage
To make the compiler, just type make in the top folder of the repository. 
```
make
```
You can optionally clear out the build folder via:
```
make clean
```

To compile a c program, run the program with the last argument the source file.
```
./build/c_compiler [args] testCases/t1.c
```
The above code would compile the t1.c test case. All resulting files are saved alongside the testcases.

The c_compiler accepts commandline arguments.
```
	-o [filename] sets the output file name. Defaults to out.s 
	Note: currently -o creates the parse file and defaults to parseFile.txt
	
	-t [filename] sets the token file name. Defaults to tokenFile.txt
	-l [filename] sets the log file name. Defaults to compilerLog.txt
	Note: currently log file only holds symbol table dumps and error messages.
	
	-d[lsp]* sets the debug levels for scanner, symbol table, and parser.
	
	-a Output the ast to a file.
	
```

The following are the commandline debug levels.

* Symbol Table:

   : no debug (1)
   
   s: print current scope (2)
   
   ss: print enter and leave scopes (3)
   
   sss: print search keys (5)

* Scanner:

   : no debug (1)
   
   l: print token (2)
   
   ll: print yytext (3)
   
   lll: print symbol table commands (5)**In Progress

* Parser:
	: no debug (1)
	
	p: print productions (2)
	
	pp: print $$,$1,$2... (3)**In Progress
	
	ppp: set yydebug=1 for built in debug (5)
	
	pppp: print 3 address code (7)**In Progress
	
	ppppp: print parse tree passing (11)**In Progress
	
An example call with max debugging set, and file names set would be:
```
./build/c_compiler -o testCases/t1Out.txt -t testCases/t1TokenFile.txt -l testCases/t1LogFile.txt -dlllpppppsss testCases/t1.c
```
	
Inside the .c file, there are commands to turn on/off debug options. Unlike the command line settings, the levels are not progressive (you can pick just the ones you want and not everything less than the given level).

```
	!!D 			Dumps symbol table to log file.
	!!L [number]	Sets scanner debug level.
	!!S [number]	Sets symbol table debug level.
	!!Y [number]	Sets parser debug level.
```

To allow for just the specific levels wanted, the [number] argument is an integer determined by the multiplication of the numbers in parenthesis in the above debug levels.

So if we want to set the scanner debug to have just `print symbol table commands` and `print token` then we multiply 5*2=10. 

Likewise if we want to set symbol table debug to `print search keys` and `print enter and leave scopes` then we multiply 5*3=15.

In code this can be placed anywhere with whitepace on either side.
```
int main()
{
	int j !!D = 1;
	char p !!L 10 ='p';
	
	!!L 1
	!!Y 6
	j = 10;
	if(j == 14)
	{
		return 1;
	}
	!!Y 1
	
	return 0;
}
```
## AST
To view the AST if graphviz is not installed you can use the website [http://www.webgraphviz.com/](http://www.webgraphviz.com/) by copying the text in the .gv file produced.
## Contributions
* Zachary Young

	Symbol table
	
	Converting token names to custom token names in given grammar
	
	Insert and lookup mode flag setting
	
	Wiki
	
	Symbol table driver
	
	Regular expressions for Lex
	
	Solving various errors
	README.md
	

* Andrew Palmer

	Scanner
	
	Command line args
	
	Regular expressions for Lex
	
	Print function for productions
	
	Test cases t1,t2,t3,t4
	
	README.md
	
	Makefile
	
	Solving various errors


* Nathan Yocum

	Symbol table updates

	Symbol table test cases

	Tree Output

	Type Nodes

	Declaration Specifier Nodes

	Solving various errors

## Can Do

* Bubble Sort
	* Loops (`for, do-while, while, if`)
	* 1-D Arrays
	* If statements

* Matrix Multiplication
	* Arrays (2D)

* Recursive Factorial
	* Functions
	* If statements

* Simple Assignments
	* `a = b + c;`

* Supported Types
	* `int`
	* `char`
		* char's can't be '\n', use 10 instead
	* `float`
		* Maybe.

* Invalid C Types won't generate.

* Nested if statements

## Can't Do

* Array Initalization Lists (i.e. `int a[2] = {1,2};`)
* Files without a new line at the end of the file
* If you have a compound statement, put an empty statement to get out of insert mode i.e. 
	```C
	int fact(int k){
		;
		if (k == 1) { return 1; }
	}
	```
* Can't use expressions as parameters
* Need spaces between operations
* Postfix expressions
* Some types:
	* `short`
	* `long`
	* `string/char*`
	* Valid C Types that aren't in the supported types list won't be supported
* Pointers
* Structs
* Function parameter checking
* `const, static, volatile, dynamic, auto` etc.
* enums