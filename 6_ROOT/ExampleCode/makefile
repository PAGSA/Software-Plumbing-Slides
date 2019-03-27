OPT = -Wall -std=c++98
CXX = g++ $(OPT)
ROOTFLAGS = `root-config --glibs --cflags`

all: Process

Process: Process.o
	@echo " "
	@echo "Compiling"
	$(CXX) $(ROOTFLAGS) Process.o -o runProcess
Process.o: Process.cxx
	@echo " "
	@echo "Making Objects"
	$(CXX) $(ROOTFLAGS) -c Process.cxx
clean:
	rm -f Process.o
	rm -f Process
