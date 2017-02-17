CPPFILES = $(shell find -name '*.cpp')
FILES = $(CPPFILES:%.cpp=%.o)
EXE = app.exe

CPPFLAGS=
CXXFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c++11

all: $(FILES)
	g++ -ggdb -o $(EXE) $(FILES)
	
%.o: %.cpp
	g++ -Wall -Wextra -Werror -Wpedantic -std=c++11 -ggdb -c $< -o $@
	
clean:
	$(RM) $(FILES)
	$(RM) $(EXE)
	
rebuild: clean all

.PHONY: all clean rebuild