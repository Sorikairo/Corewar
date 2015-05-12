.name "Dr. Hax"
.comment "HAAAAAAAAAAAAAAX"

	zjmp %:init
bckjmp:	st r10,-4
	and r8,%0,r8
	zjmp %:bckjmp
	
init:	sti r1,%:live,%1
	sti r1,%:slive,%1
	sti r1,%:fkatt,%1
	sti r1,%:attack,%1
	ld %:live,r2
	ld %:walk,r3
	ld %0,r4
	ld %-16,r5
	ld %8,r6
	ld %:end,r7
	ld %0,r10
	fork %:forker
	
live:	live %1
	and r8,%0,r8
	zjmp %:live
	
slive:	live %1
	and r8,%0,r8
	zjmp %:slive
	
forker:	fork %:slive
	fork %:walkbf
	fork %:attack
	fork %:fkatt
	
shield:	sti r2,%:live,%0
	and r8,%0,r8
	zjmp %:shield

fkatt:	live %1
	fork %:fkbmb
	add r7,r7,r7
	fork %:fkatt
	
attack:	live %1
	sti r2,r7,r4
	sti r2,%:init,r5
	add r4,r6,r4
	sub r5,r6,r5
	and r8,%0,r8
	zjmp %:attack

fkbmb:	add r10,r6,r10
	lfork %:fkbmb
	zjmp %:fkbmb
	
walkbf:	fork %:bckjmp
walk:	st r3,0
	
end:	
