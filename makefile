prog: etablissement.o etablissement_main.o
	gcc etablissement.o etablissement_main.o -o prog -g

etablissement.o: etablissement.c etablissement.h
	gcc -c etablissement.c -g

etablissement_main.o: etablissement_main.c etablissement.h
	gcc -c etablissement_main.c -g
