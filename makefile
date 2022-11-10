main: main.o InputModule.o OutputModule.o creat_inputs.o run_programs.o judge.o tool.o
	g++ -o main InputModule.o OutputModule.o main.o creat_inputs.o run_programs.o judge.o tool.o
main.o: main.cpp InputModule.h OutputModule.h creat_inputs.h run_programs.h judge.h
	g++ -c -O2 main.cpp
InputModule.o:InputModule.cpp InputModule.h tool.h
	g++ -c -O2 InputModule.cpp
OutputModule.o:OutputModule.cpp OutputModule.h tool.h
	g++ -c -O2 OutputModule.cpp
creat_inputs.o: creat_inputs.cpp creat_inputs.h tool.h
	g++ -c -O2  creat_inputs.cpp
run_programs.o: run_programs.cpp  run_programs.h tool.h
	g++ -c -O2 run_programs.cpp
judge.o: judge.cpp  judge.h OutputModule.h
	g++ -c -O2 judge.cpp
tool.o:tool.cpp tool.h
	g++ -c -O2 tool.cpp
clean:
	rm *.o main