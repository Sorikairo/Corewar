.name "watestv2"
.comment "becuz testin is even moar fnu"

init:	sti r1,%:live,%1
	ld %8,r3
	
fork:	fork %:fkinit

fkinit:	ld %:end,r2
	
attack:	sti r1,r2,%0
	add r2,r3,r2
	
live:	live %1
	sti r1,%0,%21
	and r4,%0,r4
	zjmp %:attack
end:	
