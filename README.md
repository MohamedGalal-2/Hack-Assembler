# Hack Assembler
This is a simple Hack assembler written in C language. The assembler converts Hack assembly language code into binary machine code that can be executed on the Hack computer platform.

![Header image](https://th.bing.com/th/id/R.b932f9faa777205cc4e157dad45ffa95?rik=%2fXUD3SYrwQ4nyw&pid=ImgRaw&r=0&sres=1&sresct=1)

## Table of Contents
- [Installation](#Installation)
- [Usage](#Usage)
- [Functions](#Functions)
- [Supported Instructions](#Supported-Instructions)
- [Examples](#Examples)
- [Contributing](#Contributing)
- [License](#License)

### Installation
To use any function from this code in your projects, you can clone this repository or download the necessary files.

    git clone https://github.com/MohamedGalal-2/Hack-Assembler.git
    
Afterwards, you need to include the string.h header file in your C code and link with the library during compilation.

    #include "Assembler.h"
  
### Usage
To use the assembler, you need to have a Hack assembly language file (.asm extension). Then, follow these steps:

Navigate to the repository folder: cd hack-assembler
Compile the source code: gcc -o assembler assembler.c
Run the assembler: ./assembler yourfile.asm
After executing the assembler command with your assembly file, a new binary code file (yourfile.hack) will be generated in the same folder.

### Functions
<pre>
1. void removeComments(FILE*, FILE*);
Removes single lined comments from a file.
</pre>

### Supported Instructions
The Hack Assembler supports the following types of instructions:

* A-instructions: Instructions that refer to memory addresses (e.g., @123).
* C-instructions: Instructions that perform computations and control flow (e.g., D=M;JNE).
The assembler ignores whitespace and comments in the assembly code.

### Examples
Let's see an example of using the assembler. Suppose you have an assembly file named addition.asm with the following code:

<pre>
// This program adds two numbers together and stores the result in R2
@2
D=A
@3
D=D+A
@2
M=D
</pre>
After running the assembler, a file named addition.hack will be generated with the following binary code:
<pre>
0000000000000010
1110110000010000
0000000000000011
1110000010010000
0000000000000010
1110001100001000
</pre>

### Contributing
Contributions to this library are always welcome! If you have any suggestions, bug fixes, or additional functions to add, please feel free to create a pull request.

### License
This project contains my own implementation for the hack Assembler in C. Feel free to use for any purpose.
