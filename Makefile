all: main board_test

main: bin/main.o bin/Board.o bin/BoardView.o
    g++ -o main bin/main.o bin/Board.o bin/BoardView.o -Wall -Werror -std=c++11

bin/main.o: src/main.cpp | bin/
    g++ -c src/main.cpp -o bin/main.o -I include/ -Wall -Werror -std=c++11

bin/Board.o: src/Board.cpp | bin/
    g++ -c src/Board.cpp -o bin/Board.o -I include/ -Wall -Werror -std=c++11

bin/BoardView.o: src/BoardView.cpp | bin/
    g++ -c src/BoardView.cpp -o bin/BoardView.o -I include/ -Wall -Werror -std=c++11

board_test: bin/autotesting.o bin/Test.o bin/BoardTest.o bin/Board.o
    g++ -o board_test bin/autotesting.o bin/Test.o bin/BoardTest.o bin/Board.o -Wall -Werror -std=c++11

bin/autotesting.o: test/autotesting.cpp | bin/
    g++ -c test/autotesting.cpp -o bin/autotesting.o -I include/ -Wall -Werror -std=c++11

bin/Test.o: test/Test.cpp | bin/
    g++ -c test/Test.cpp -o bin/Test.o -I include/ -Wall -Werror -std=c++11 

bin/BoardTest.o: test/BoardTest.cpp | bin/
    g++ -c test/BoardTest.cpp -o bin/BoardTest.o -I include/ -Wall -Werror -std=c++11

clean: | bin/
    rm -rf bin/

bin/:
    mkdir bin/