// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(LOOP) //listen infinitely

	@i
	M=0 //i=0

	@8192
	D=A //D=A
	@n
	M=D //n=8192

	@KBD
	D=-1
	D=D&M

	@WHITE
	D;JEQ //if (D==0) goto WHITE

(LOOP1)
	@i
	D=M //D=i
	@n
	D=M-D //D=n-i
	@LOOP
	D;JEQ //if (i == n) goto LOOP

	@i
	D=M //D=i
	@SCREEN
	A=A+D //A=16384 + i
	M=-1 //RAM[A]=11111111
	

	@i
	M=M+1 //i++

	@LOOP1
	0;JMP
	
(WHITE)

(LOOP2)
	@i
	D=M //D=i
	@n
	D=M-D //D=n-i
	@LOOP
	D;JEQ //if (i == n) goto LOOP

	@i
	D=M //D=i
	@SCREEN
	A=A+D //A=16384 + i
	M=0 //RAM[A]=00000000
	
	

	@i
	M=M+1 //i++

	@LOOP2
	0;JMP 
