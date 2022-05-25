.PHONY:setup,clean

CC = g++
FLAGS = -pedantic -g
INCLUDE = -I ./include

rayTracer: src/rayTracer.cpp \
	src/Vector3.cpp include/Vector3.h \
	src/Point3.cpp include/Point3.h	\
	src/Point2.cpp include/Point2.h	\
	src/Normal3.cpp include/Normal3.h	\
	src/World.cpp include/World.h \
	src/Camera.cpp include/Camera.h \
	src/ViewPlane.cpp include/ViewPlane.h \
	src/GeometricObject.cpp include/GeometricObject.h \
	src/Sphere.cpp include/Sphere.h \
	src/Light.cpp include/Light.h src/Plane.cpp include/Plane.h

	$(CC) $(FLAGS) $(INCLUDE) src/rayTracer.cpp src/Light.cpp src/Plane.cpp src/Sphere.cpp src/GeometricObject.cpp  src/ViewPlane.cpp src/World.cpp src/Camera.cpp src/RGBColor.cpp src/Vector3.cpp src/Point3.cpp src/Point2.cpp src/Normal3.cpp src/Ray.cpp -o ./bin/$@



setup:
	mkdir -p ./bin ./include ./src

clean:
	rm ./bin/*
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/rayTracer
