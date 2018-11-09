.name	"Leeloo"
.comment "Multipass"
	
begin:	ld %0,r6
jump:	zjmp %:deb
	
pare:	

toto:
deb:	

	st r16,:jump


hop:	live %1
	fork %:decal2
	live %1
	ld %0,r2
	zjmp %:decal

toto1:	zjmp %:toto	
pare1:	ld %0,r16
	zjmp %:pare	
decal2: live %1
	fork %:suite
	live %1
	ld %57672448,r5
	ld %67334147,r6

	ld %57673214,r9
	ld %201551878,r10
	ld %4262136318,r11
	ld %33554432,r12

	ld %57674238,r15
	ld %369324042,r4
	ld %4262790000,r7
	ld %201200643,r8
	ld %1879899667,r13
	ld %167641600,r14
	
	fork %:separ2
	live %4

	ld %0,r2
	zjmp %:toto
separ2:	live %3

	xor r2,r2,r2
	zjmp %:toto
	
padec2:	live %1
	fork %:suite
	live %1
	ld %0,r2
	zjmp %:decal

catch1:	zjmp %:catch
	
suite:	live %1
	fork %:hop
	live %1
	fork %:just
just:	live %3
	fork %:just2
just2:	live %3
	fork %:just3
just3:	live %3
	fork %:just4
	live %3
just4:	live %3
	fork %:just5
	live %3
just5:	fork %:middle
suitb:	live %3
	live %3
	live %3
live1:	live %3
live2:	live %3
lastlive1: live %1
	ld %0,r6
lastlive2: live %1
	zjmp %:suitb
middle:	live %3

	live %3

	live %3

live3:	live %3

live4:	live %4
lastlive3: live %1
	ld %0,r6
lastlive4: live %1
	zjmp %:middle

	
decal:	live %1
	fork %:pare1
	live %1
	fork %:fuite
	live %1







	
	fork %:sepa
	live %4

	ld %0,r2
	zjmp %:tot
sepa:	live %3

	xor r2,r2,r2
	zjmp %:tot
catch:	
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	ld %0,r16
	zjmp %:catch
	
fuite:	live %1
	fork %:separe
	live %4

	ld %0,r2
	zjmp %:debut
separe:	live %3

	xor r2,r2,r2
	zjmp %:debut
	
		
tot:	st r15,488
	st r4,487
	st r7,486
	st r8,485
	st r13,484
	st r14,483
	zjmp %458
	
debut:	st r3,4
fin:

avant:	

#	075103700370075103700771

arriere:

#       08 F4 03 70 03 70 08 F4 03 70


