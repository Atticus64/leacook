TARGET     =  learnc
DEPS  		 =  basics/*.c app/*.c
MAIN 			 =  main.c 
CXX       ?=  gcc


$(TARGET):  $(DEPS)
	$(CXX) $(MAIN) $(DEPS) -o $@ 

