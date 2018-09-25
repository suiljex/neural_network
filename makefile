
INCPATH = -I./ -I./include
SOURCE_DIR = src
INCLUDE_DIR = include
LIBS =
TARGET = NN
LINK = g++

CXX = g++
DEL_FILE = rm -f
CXXFLAGS = -m64 -pipe -g -std=c++0x -Wall -W -fPIC $(INCPATH)
LFLAGS =-m64 $(LIBS)

DIRS = $(SOURCE_DIR)
DIRS += $(INCLUDE_DIR)

OBJECTS = $(notdir $(patsubst %.cpp,%.o,$(wildcard $(addsuffix /*.cpp,$(SOURCE_DIR)))))

VPATH = $(SOURCE_DIR)

first: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(LFLAGS) -o $@ $^
	

clean: softclean
	@$(DEL_FILE) $(TARGET)
	

softclean: 
	@$(DEL_FILE) $(addsuffix /*~, $(DIRS)) $(addsuffix /*.*~, $(DIRS))
	@$(DEL_FILE) *.o *~ core *.core core* *.*~ *.d *.gcda *.gcno



