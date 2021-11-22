CPP = g++ 
FLAGS = -O5 -Wall -W
RM  = rm -f -r
EXEC = a.out

CRDIR = createdir
INCLUDES = -Iincludes/
SRCPATH = classes
OBJDIR = build
OBJDIRFUNCTS = main
OBJDIRCLASSES = classes

CLASSES = \
	 course.o \
	 dept.o \
	 prof.o \
	 timetable.o \

FUNCTS = \
	 main.o \
	 function.o \

OBJECTS = \
	 $(addprefix $(OBJDIR)/$(OBJDIRFUNCTS)/, $(FUNCTS)) \
	 $(addprefix $(OBJDIR)/$(OBJDIRCLASSES)/, $(CLASSES)) \

all: $(OBJECTS) compile touch

$(OBJDIR)/$(OBJDIRFUNCTS)/%.o: %.cpp | $(CRDIR)/$(OBJDIR)/$(OBJDIRFUNCTS)
					 $(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/$(OBJDIRCLASSES)/%.o: $(SRCPATH)/%.cpp | $(CRDIR)/$(OBJDIR)/$(OBJDIRCLASSES)
					 $(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@
$(CRDIR)/%:
					 mkdir -p $*
clean:  
					 $(RM) $(OBJDIR) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "
