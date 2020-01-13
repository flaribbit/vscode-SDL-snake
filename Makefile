CC=gcc
INC=./include
CFLAGS=-I $(INC) -s -O2 -DNDEBUG -mwindows

a.exe: main.c res.o lodepng.o sprite.o
	$(CC) main.c SDL2.dll res.o lodepng.o sprite.o $(CFLAGS) -o a.exe

res.o: res.rc manifest.xml
	windres res.rc -o res.o

lodepng.o: lodepng.c
	$(CC) -c lodepng.c $(CFLAGS)

sprite.o: sprite.c
	$(CC) -c sprite.c $(CFLAGS)
