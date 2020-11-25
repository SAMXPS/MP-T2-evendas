IDIR =../headers	# Diretório de include	

CC=g++
CFLAGS=-I$(IDIR) -ljsoncpp
GTEST_FLAGS=-lgtest -lpthread

ODIR :=../bin/obj	# Diretório de objetos
LDIR :=../lib		# Diretório de libs

LIBS=-lm

SRC_FILES := JsonModule.cpp Backend.cpp #$(wildcard *.cpp)
OBJ_FILES := $(patsubst ./%.cpp,$(ODIR)/%.o,$(SRC_FILES))

TEST_SRC_FILES := JsonModule.cpp Test.cpp
TEST_OBJ_FILES := $(patsubst ./%.cpp,$(ODIR)/%.o,$(TEST_SRC_FILES))

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_OBJ_FILES)
	$(CC) -o ../bin/$@ $^ $(CFLAGS) $(LIBS) $(GTEST_FLAGS)

backend:  $(OBJ_FILES)
	$(CC) -o ../bin/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean cleanTest

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 