# Hack Assembler
This is a simple Hack assembler written in C language. The assembler converts Hack assembly language code into binary machine code that can be executed on the Hack computer platform.

## Table of Contents
- [Installation](#Installation)
- [Usage](#Usage)
- [Examples](#Examples)
- [Contributing](#Contributing)
- [License](#License)

### Installation
To use this library in your project, you can clone this repository or download the necessary files.

    git clone https://github.com/MohamedGalal-2/Hack-Assembler.git
    
Afterwards, you need to include the string.h header file in your C code and link with the library during compilation.

    #include "Assembler.h"
  
### Usage
To use the assembler, you need to have a Hack assembly language file (.asm extension). Then, follow these steps:

Navigate to the repository folder: cd hack-assembler
Compile the source code: gcc -o assembler assembler.c
Run the assembler: ./assembler yourfile.asm
After executing the assembler command with your assembly file, a new binary code file (yourfile.hack) will be generated in the same folder.

### Examples
Let's see an example of using the assembler. Suppose you have an assembly file named addition.asm with the following code:

// This program adds two numbers together and stores the result in R2
<pre>
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
