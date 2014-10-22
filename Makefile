.PHONY: main Doxyfile html test judge clean
SRC_DIR = ./source
TOOLS_DIR = $(SRC_DIR)/tools
JUDGE_DIR = ./judge

all: main

Doxyfile:
	doxygen -g

html: Doxyfile $(SRC_DIR)/Ribbon.h $(SRC_DIR)/Ribbon.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/UnitTests.cpp
	doxygen Doxyfile

testfile: main
	./main < $(TOOLS_DIR)/test.txt > $(TOOLS_DIR)/validOutput.txt

diff: main $(TOOLS_DIR)/validOutput.txt
	./main < $(TOOLS_DIR)/test.txt > temp.txt
	diff $(TOOLS_DIR)/validOutput.txt temp.txt

main: $(SRC_DIR)/Ribbon.h $(SRC_DIR)/Ribbon.cpp $(SRC_DIR)/main.cpp
	g++ -pedantic -std=c++11 -Wall $(filter %.cpp, $^) -o main

test: $(SRC_DIR)/Ribbon.h $(SRC_DIR)/Ribbon.cpp $(SRC_DIR)/UnitTests.cpp
	g++ -pedantic -std=c++11 -Wall $(filter %.cpp, $^) -o test -lgtest -lgtest_main -lpthread

judge: $(SRC_DIR)/main.cpp $(SRC_DIR)/Ribbon.cpp
	@mkdir -p judge
	@sed -e '/#include "prints.h"/d' $(SRC_DIR)/Ribbon.cpp > $(JUDGE_DIR)/Ribbon.cpp
	@grep -A500 "int main" $(SRC_DIR)/main.cpp >> $(JUDGE_DIR)/Ribbon.cpp

other: ./other.cpp
	g++ -pedantic -std=c++11 -Wall $(filter %.cpp, $^) -o other

clean:
	rm -f ./main
	rm -f ./test
	rm -f -r ./judge
	rm -f ./temp.txt
