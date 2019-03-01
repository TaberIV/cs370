CXX      = g++
CXX_FILE = puzzlesolver.cpp
TARGET   = $(patsubst %.cpp,%,$(CXX_FILE))
CXXFLAGS = -std=c++17 -g -fmessage-length=0

all:
	$(CXX) $(CXXFLAGS) $(CXX_FILE) -o $(TARGET)
clean:
	rm -f $(TARGET) $(TARGET).exe
