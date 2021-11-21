CPP = g++ 
FLAGS = -O5 -Wall -W
RM  = rm -f
EXEC = a.out
path = classes/

OBJECTS = \
	 main.o \
	 course.o \
	 dept.o \
	 function.o \
	 prof.o \
	 timetable.o \

all: $(OBJECTS) compile touch 

main.o : main.cpp 
					 $(CPP) $(FLAGS) -c main.cpp
course.o : $(addprefix $(path),course.cpp)
			   		 $(CPP) $(FLAGS) -c $(addprefix $(path),course.cpp)
dept.o : $(addprefix $(path),dept.cpp) $(addprefix $(path),scalar.h) $(addprefix $(path),pair.h)
					 $(CPP) $(FLAGS) -c $(addprefix $(path),dept.cpp)
function.o : function.cpp
					 $(CPP) $(FLAGS) -c function.cpp
prof.o : $(addprefix $(path),prof.cpp)
					 $(CPP) $(FLAGS) -c $(addprefix $(path),prof.cpp)
timetable.o : $(addprefix $(path),timetable.cpp)
					 $(CPP) $(FLAGS) -c $(addprefix $(path),timetable.cpp)
clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "
