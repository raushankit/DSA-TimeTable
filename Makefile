CPP = g++ 
FLAGS = -O5 -Wall -W
RM  = rm -f -r
EXEC = a.out
INCLUDES = -Iincludes/
SRCPATH = classes
OBJDIR = build

CLASSES = \
	 course.o \
	 dept.o \
	 prof.o \
	 timetable.o \

FUNCTS = \
	 main.o \
	 function.o \

OBJECTS = $(addprefix $(OBJDIR)/, $(FUNCTS)) $(addprefix $(OBJDIR)/, $(CLASSES))

all: $(OBJECTS) compile touch

$(OBJDIR)/main.o: main.cpp | $(OBJDIR)
					 $(CPP) $(FLAGS) $(INCLUDES) -c main.cpp -o $(OBJDIR)/main.o
$(OBJDIR)/function.o: function.cpp | $(OBJDIR)
					 $(CPP) $(FLAGS) $(INCLUDES) -c function.cpp -o $(OBJDIR)/function.o
$(OBJDIR)/%.o: $(SRCPATH)/%.cpp | $(OBJDIR)
					 $(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR):
					 mkdir $@
clean:  
					 $(RM) $(OBJDIR) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "
