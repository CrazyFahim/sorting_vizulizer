FILE=C1.cpp
STD=-std=c++20
SDL=-lSDL2
OUT=$(FILE:.cpp=)

all:
	g++ $(STD) $(FILE) -o  $(OUT) $(SDL)
	./$(OUT)

clear:
	rm $(OUT)
