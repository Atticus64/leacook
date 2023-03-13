TARGET     =  learnc
MAIN 			 =  main.c 
CXX       ?=  gcc

$(TARGET): 
	$(CXX) $(MAIN) -o $@ 

