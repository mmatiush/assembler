.name "zork"
.comment "I'M ALIIIIVE"

l7:
l2:		sti r1, %:live, %1
		and r1, %0, r1
l5:
l6:
live:	live %1
		zjmp %:live

l3:
l4:
