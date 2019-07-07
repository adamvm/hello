main: 
	g++ main.cpp -o main -o main -Wall -Werror -Wpedantic -O3 --std=c++11

debug:
	g++ main.cpp -o main.dbg -o main -Wall -Werror -Wpedantic -O3 --std=c++11 -g
	
test:
	echo Executing tests

clean:
	rm -f main main.dbg
