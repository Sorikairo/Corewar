.name "walker"
.comment "just walkin', man"

	sti r1,%:live,%1
	ld %:walk,r3
	fork %:walk
live:	live %1
	and r2,%0,r2
	zjmp %:live
walk:	st r3,0
