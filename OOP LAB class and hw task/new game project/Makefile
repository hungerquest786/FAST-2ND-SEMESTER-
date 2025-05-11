all: main.exe

INCLUDES = -I"D:/2nd semester/libraries/SFML-2.6.2/include" -I"D:/2nd semester/new game project/headers"
CFLAGS = -DSFML_STATIC
LIBS = -L"D:/2nd semester/libraries/SFML-2.6.2/lib" \
       -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main \
       -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

SRCS = main.cpp headers/Game.cpp headers/Player.cpp headers/Tile.cpp headers/TileMap.cpp headers/Coin.cpp
OBJS = main.o

main.exe: $(OBJS)
	g++ $(SRCS) $(INCLUDES) $(CFLAGS) -o $@ $(LIBS)

main.o: main.cpp
	g++ -c $< $(INCLUDES) $(CFLAGS)

clean:
	rm -f *.exe *.o
