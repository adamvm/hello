main: 
	g++ main.cpp -o main -o main -Wall -Werror -Wpedantic -O3 --std=c++17

debug:
	g++ main.cpp -o main.dbg -o main -Wall -Werror -Wpedantic -O3 --std=c++17 -g

clean:
	rm -f main main.dbg
