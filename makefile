CC = g++ -g
EXE_FILE = assignment3.exe

$(EXE_FILE): coffee.o order.o menu.o shop.o display.o prog.cpp
	$(CC) coffee.o order.o menu.o shop.o display.o prog.cpp -o $(EXE_FILE)

display.o: display.cpp display.h
	$(CC) -c display.cpp

shop.o: shop.cpp shop.h
	$(CC) -c shop.cpp

menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp

order.o: order.cpp order.h
	$(CC) -c order.cpp

coffee.o: coffee.cpp coffee.h
	$(CC) -c coffee.cpp

clean:
	rm -f *.out *.o $(EXE_FILE)

run: $(EXE_FILE)
	@clear && $(EXE_FILE)