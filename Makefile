TARGET  =  learnc
DEPS  	=  basics/*.c 
MAIN    =  main.c 
CXX     =  gcc


$(TARGET):  $(DEPS)
	$(CXX) $(MAIN) $(DEPS) -o $@ 

