OBJDIR=obj
BIN=bin
SRC=.
CC=g++
vpath $(SRC)
source=$(wildcard $(SRC)/*.cpp)
# objs=$(source: %.cpp=$(OBJDIR)/%.o)
all: $(BIN)/6.out $(BIN)/7.out $(BIN)/8.out $(BIN)/9.out $(BIN)/10.out \
$(BIN)/11.out $(BIN)/12.out $(BIN)/15.out $(BIN)/16.out $(BIN)/17.out \
$(BIN)/18.out $(BIN)/20.out $(BIN)/24.out $(BIN)/25.out $(BIN)/26.out \
$(BIN)/28.out $(BIN)/29.out $(BIN)/30.out
.PHONY: all

$(BIN)/%.out: $(OBJDIR)/%.o
	@mkdir -p $(BIN)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRC)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ -std=c++11 -g

# 保留make 过程产生的过程文件  .o  文件
.PRECIOUS: $(OBJDIR)/%.o

clean:
	@rm -r $(BIN)/*
	@rm -r $(OBJDIR)/*
.PHONY: clean
