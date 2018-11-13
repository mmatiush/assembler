.name "Not A Chosen One"
.comment "Just another regular comment..."

code: sti r1, %:live, %1 

live: live %1

replicate: 	ldi %:live, %1, r3
			xor r1, r3, r5 
			fork %:code

jump: zjmp %:replicate

