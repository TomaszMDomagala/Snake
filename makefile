#Makefile

OBJS = main.o board.o reader.o mfsl.o snake.o menu.o endscreen.o
CXX = clang++
CXXFLAGS = -Wall -std=c++11
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

MS: $(OBJS)
	$(CXX) -o snake $(OBJS) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) MS $(OBJS)
