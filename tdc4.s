.name 		"dtonc v1.0pl4"
.comment	"ta mere elle fait du rodeo sur les kfar"



debut:	
	
	
	ld	%100, r4
	ld	%4, r6
	ld	%0, r3
li1:	
	live	%1
	
cp:	
	ldi	%:debut, r3, r2
	sti	r2, %400, r3
	add	r3, r6, r3
	sub	r3, r4, r5
li2:	
	live	%1

	ld	%0, r5
	zjmp	%:cp
