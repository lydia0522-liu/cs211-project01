build:
	rm -f ./a.out
	g++ -std=c++20 -g -Wall -pedantic -Werror main.cpp set.cpp -lm -Wno-unused-variable -Wno-unused-function

run:
	./a.out

valgrind:
	rm -f ./a.out
	g++ -std=c++20 -g -Wall -pedantic -Werror main.cpp set.cpp -lm -Wno-unused-variable -Wno-unused-function
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./a.out

submit:
	/gradescope/gs submit 1396807 8852468 *.cpp *.h
  
commit:
	git add .
	git commit -m "$(msg)"

push:
	git push origin main