CC=g++

main: parsertestmain.o defs.o lex.yy.o y.tab.o handler.o
	$(CC) parsertestmain.o defs.o lex.yy.o y.tab.o handler.o -o main
parsertestmain.o: parsertestmain.cpp
	$(CC) -c parsertestmain.cpp
defs.o: defs.cpp defs.h
	$(CC) -c defs.cpp
handler.o: handler.cpp handler.h
	$(CC) -c handler.cpp
lex.yy.o: lex.yy.c y.tab.h
	$(CC) -c lex.yy.c
y.tab.o: y.tab.c y.tab.h
	$(CC) -c y.tab.c
y.tab.c y.tab.h: Parser.y
	yacc -d Parser.y
lex.yy.c: lexer.l
	flex lexer.l
clean:
	rm *.o main main.exe y.tab.c lex.yy.c y.tab.h