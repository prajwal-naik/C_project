a.exe: RPSbeta.o the_game.o
	gcc RPSbeta.o the_game.o
RPSbeta.o: RPSbeta.o header.h
	gcc -c RPSbeta.c
the_game.o: the_game.o header.h
	gcc -c the_game.c