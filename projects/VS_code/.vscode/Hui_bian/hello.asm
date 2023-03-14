
assume cs:codegs
codegs segment

     mov ax,0123H
	 mov bx,0456H
	 add ax,bx
	 add ax,ax 
	 
	 mov ax,4c00H
	 int 21h
	 
	 codegs ends
	 
	 end