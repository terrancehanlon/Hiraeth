exeName = mainp

sfmlFlags = -lsfml-graphics -lsfml-window -lsfml-system

g = g++ -std=c++11 -c

link = target/Imports.o \
target/Animation.o \
target/AnimatedSprite.o \
target/Writer.o \
target/Passenger.o \
target/Train.o \
target/Game.o \
target/Main.o

game:
	$(g) core/Game.cpp -o target/Game.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;
all:
	$(g) Lib/Imports.cpp -o target/Imports.o
	$(g) Lib/Animation.cpp -o target/Animation.o
	$(g) Lib/AnimatedSprite.cpp -o target/AnimatedSprite.o
	$(g) core/Writer.cpp -o target/Writer.o
	$(g) core/Passenger.cpp -o target/Passenger.o
	$(g) core/Train.cpp -o target/Train.o
	$(g) core/Game.cpp -o target/Game.o
	$(g) core/Main.cpp -o target/Main.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

clean:
	rm -rf target/*/