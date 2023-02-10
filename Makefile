all: client.exe server.exe 
client.exe: client.c
	cc client.c -o client.exe
server.exe: server.o func.o
	cc server.o func.o -o server.exe 
server.o: server.c
	cc -c server.c
func.o: func.c
	cc -c func.c
clean:
	rm -f *.o build #*.a *.out