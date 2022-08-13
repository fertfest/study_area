@SCREEN
D=A
@addr
M=D

@8191
D=A
@n
M=D

@i
M=0


(LOOP)
	@i
	D=M
	@n
	D=M-D
	@END
	D;JEQ

	@i
	D=M //D=i
	@SCREEN
	D=A+D //D=i+SCREEN
	A=D
	M=-1	
	
	@i
	M=M+1

	@LOOP
	0;JMP	
(END)




