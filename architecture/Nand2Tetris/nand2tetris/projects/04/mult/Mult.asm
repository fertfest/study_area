// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.
	@R0
	D=M
	@a
	M=D //a=R0

	@R1
	D=M
	@b
	M=D //b=R1

	@sum
	M=0 //sum=0

(LOOP)
	@b
	D=M //D=b
	@ENDLOOP	
	D;JEQ //if (b==0) goto ENDLOOP

	@sum
	D=M //D=sum

	@a	
	D=D+M //D=D+a

	@sum
	M=D	//sum=D

	@b
	M=M-1 //b--

	@LOOP
	0;JMP //unconditionally goto LOOP

(ENDLOOP)
	@sum
	D=M //D=sum
	@R2
	M=D //R2=sum

(END)
	@END
	0;JMP	
