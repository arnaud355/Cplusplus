EXE = main
OBJ = Jeu.o Main.o Objet.o Moteur.o Menu.o IA.o Rand.o

LIBS = `sdl-config --libs` 
OPT = -O3 `sdl-config --cflags` -Wall -Wextra

$(EXE):	$(OBJ)
	g++ -o $(EXE) $(OBJ) $(OPT) $(LIBS)

$(OBJ):%.o: %.cpp %.h Define.h
	g++ -c $< $(OPT)

clean:
	rm $(OBJ) $(EXE)
