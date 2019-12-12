# Julia Zeng
# EC 327 PA 3
# Makefile

# included compiler flag for C++11 in GCC definition
GCC = g++ -std=c++11

#TestCheckpoint1.cpp

pa: main.cpp Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o
	$(GCC) main.cpp Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o -o pa

# TestCheckpoint1.o: TestCheckpoint1.cpp
# 	$(GCC) -c TestCheckpoint1.cpp

main.o: main.cpp
	$(GCC) -c main.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp 

PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp

PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp

Pokemon.o: Pokemon.cpp 
	$(GCC) -c Pokemon.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

Rival.o: Rival.cpp
	$(GCC) -c Rival.cpp

BattleArena.o: BattleArena.cpp
	$(GCC) -c BattleArena.cpp

Input_Handling.o: Input_Handling.h
	$(GCC) -c Input_Handling.h

clean: 
	rm main.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o pa 


