
BUILD_CMD=g++ -c -g
LINK_CMD=g++ 

objects=ball.o game.o main.o paddle.o userinput.o 

default: clean build

compile: 
	$(BUILD_CMD) -o ball.o Ball.cpp
	$(BUILD_CMD) -o game.o Game.cpp
	$(BUILD_CMD) -o main.o main.cpp
	$(BUILD_CMD) -o paddle.o Paddle.cpp
	$(BUILD_CMD) -o userinput.o UserInput.cpp

build: compile $(objects)
	$(LINK_CMD) -o pong $(objects) -lncurses

clean:
	rm -rf *.o
	rm -rf pong

