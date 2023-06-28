# The Monty Language Interpreter

[![Generic badge](https://img.shields.io/badge/Maintained-Yes-green.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/Made%20With-C-blue.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/contributors-1-green.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/release-1.0.0-green.svg)](https://shields.io/)

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files. The `monty` interpreter is designed to execute instructions in a Monty ByteCode file.

<details>
<summary>Installation and uninstalling: How to install the program</summary>

1. First, clone this repository:
	```
	vagrant@ubuntu:~$ git clone https://github.com/Ebuube/monty.git
	```

2. Then run the `Makefile`
	> #Note: Ensure you have `gcc` and `make` installed on your system before running the Makefile.
	```
	vagrant@ubuntu:~$ make
	```

	If you don't have `make` utility installed, check out how to install it. For Ubuntu, you can look at this documentation [How to install make on Ubuntu](https://linuxhint.com/install-make-ubuntu/)

3. Confirm installation by running the monty command on a sample bytecode file and expect the result shown below. Example:
	```
	vagrant@ubuntu:~$ cat bytecode.m
	push 1
	push 2
	push 3
	add
	pint
	push 4
	pall
	vagrant@ubuntu:~$ monty bytecode.m
	5
	4
	5
	1
	vagrant@ubuntu:~$
	```


> #Note: Once installed, you can use monty anywhere in your machine :).

### To Uninstall
Run the `clean` target of **make** thus:
	```
	vagrant@ubuntu:~$ make clean
	```

</details>

<details>
<summary>Execution: How to use the monty program</summary>

## The monty program

* Usage: `monty file`
	* where `file` is the path to the file containing Monty byte code

* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`

* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
	* where `<file>` is the name of the file

* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
	* where `line_number` is the line number where the instruction appears.
	* Line numbers always start at 1

* The monty program runs the byte codes line by line and stop if either:
	* it executed properly every line of the file
	* it finds an error in the file
	* an error occurred

* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.

* You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)


Example: Given a monty byte code file named `00.m` in the `bytecodes` directory, we can execute it thus...

```
vagrant@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vagrant@ubuntu:~/monty$ monty bytecodes/00.m
3
2
1
vagrant@ubuntu:~/monty$
```
</details>

<details>
<summary>opcodes: Available opcodes</summary>

* **push**: Usage: `push <int>`
	- This pushes an (integer) element to the stack.

* **pall**: Usage: `pall`
	- This prints all the values on the stack, starting from the top of the stack.

* **pint**: Usage: `pint`
	- This prints the value at the top of the stack, followed by a new line.

* **pop**: Usage: `pop`
	- This removes the top element of the stack, but doesn't print or return it.

* **swap**: Usage: `swap`
	- This swaps the top two elements of the stack.

* **add**: Usage: `add`
	- This adds the top two element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		* The top element of the stack contains the result
		* The stack is one element shorter

* **nop**: Usage: `nop`
	- This opcode does **not** do anything.

> Warning: Values outside INT\_MIN - INT\_MAX (both exclusive) can't be used as data values for the stack

</details>

<details>
<summary>File format: Monty instruction file format</summary>

## Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

Given a directory name `bytecodes` that contains Monty byte codes.
```
vagrant@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
vagrant@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
vagrant@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
vagrant@ubuntu:~/monty$
```
</details>


## Dependencies
* You must have the [make](https://www.gnu.org/software/make/) utility  installed on your system
* You must have [gcc](https://gcc.gnu.org/) compiler on your system

## Further Reading
[Creating an Interpreter for Monty Byte codes Using C Programming Language](https://medium.com/@mr_robertamoah/creating-an-interpreter-for-monty-bytecodes-using-c-programming-language-287a2c2aa706?source=rss------programming-5)
<br>
[Monty Language: Implementing Stacks & Queues](https://micahondiwa.hashnode.dev/monty-language-implementing-stacks-queues)


## Acknowledgements
[![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)](https://git-scm.com/) [![GITHUB](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/) [![Generic badge](https://img.shields.io/badge/ALX-AFRICA-white.svg)](https://www.alxafrica.com/)

