.PHONY:setup,clean

CC = g++
FLAGS = -pedantic -g
INCLUDE = -I ./include

test: src/test.cpp \
	src/Vector3.cpp include/Vector3.h \
	src/Point3.cpp include/Point3.h	\
	src/Point2.cpp include/Point2.h	\
	src/Normal3.cpp include/Normal3.h	\

	$(CC) $(FLAGS) $(INCLUDE) src/test.cpp src/Vector3.cpp src/Point3.cpp src/Point2.cpp src/Normal3.cpp -o ./bin/$@



setup:
	mkdir -p ./bin ./include ./src

clean:
	rm ./bin/*