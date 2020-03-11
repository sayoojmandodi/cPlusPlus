all: livevision

livevision: utils.o plc.o database.o config.o camera.o baumercamera.o baslercamera.o processor.o main.o
	g++ -std=c++11 utils.o plc.o database.o config.o camera.o baumercamera.o baslercamera.o processor.o main.o -o livevision

utils.o: ./app/utils/utils.cpp
	g++ -std=c++11 -c ./app/utils/utils.cpp -o utils.o

plc.o: ./app/plc/plc.cpp
	g++ -std=c++11 -c ./app/plc/plc.cpp -o plc.o

database.o: ./app/database/database.cpp
	g++ -std=c++11 -c ./app/database/database.cpp -o database.o

config.o: ./app/config/config.cpp
	g++ -std=c++11 -c ./app/config/config.cpp -o config.o

camera.o: ./app/camera/camera.cpp
	g++ -std=c++11 -c ./app/camera/camera.cpp -o camera.o

baumercamera.o: ./app/baumer/baumercamera.cpp
	g++ -std=c++11 -c ./app/baumer/baumercamera.cpp -o baumercamera.o

baslercamera.o: ./app/basler/baslercamera.cpp
	g++ -std=c++11 -c ./app/basler/baslercamera.cpp -o baslercamera.o

processor.o: ./app/plc/plc.cpp
	g++ -std=c++11 -c ./app/processor/processor.cpp -o processor.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o	

clean:
	rm *.o livevision
