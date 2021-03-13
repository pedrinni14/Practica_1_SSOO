DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CC := gcc

all : manager pa pb pc pd demonio 

manager: 
	gcc ./src/manager.c -o ./exec/manager 

pa: 
	gcc ./src/pa.c -o ./exec/pa

pb: 
	gcc ./src/pb.c -o ./exec/pb
pc:
	gcc ./src/pc.c -o ./exec/pc
pd:
	gcc ./src/pd.c -o ./exec/pd
demonio:
	gcc ./src/demonio.c -o ./exec/demonio
test: 
	./exec/manager

clean:
	rm -R estudiantes_copia_seguridad
	rm -R estudiantes

