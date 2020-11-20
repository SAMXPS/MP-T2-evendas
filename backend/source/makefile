IDIR =../headers	# Diretório de include	

CC=g++
CFLAGS=-I$(IDIR) -lgtest -lpthread 

ODIR :=../bin/obj	# Diretório de objetos
LDIR :=../lib		# Diretório de libs

LIBS=-lm

SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst ./%.cpp,$(ODIR)/%.o,$(SRC_FILES))

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ_FILES)
	echo $(SRC_FILES)
	$(CC) -o ../bin/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean cleanTest

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 