# makefile for "SortedListTester (olaDLL & olaALL & olaSLC)" program(s)
#

CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g


# Create linked-list version (olaDLL) of "SortedListTester" program
olaDLL:                DLLtester.o DLL.o
	$(CXX) $(CXXFLAGS) DLLtester.o DLL.o -o olaDLL

DLLtester.o:                    SortedListTester.cpp DLL.h
	$(CXX) $(CXXFLAGS) -c -DDLL SortedListTester.cpp -o DLLtester.o

DLL.o:                    DLL.cpp DLL.h
	$(CXX) $(CXXFLAGS) -c DLL.cpp


# Create linked-list version (olaALL) of "SortedListTester" program
olaALL:                ALLtester.o ALL.o
	$(CXX) $(CXXFLAGS) ALLtester.o ALL.o -o olaALL

ALLtester.o:                    SortedListTester.cpp ALL.h
	$(CXX) $(CXXFLAGS) -c -DALL SortedListTester.cpp -o ALLtester.o

ALL.o:                    ALL.cpp ALL.h
	$(CXX) $(CXXFLAGS) -c ALL.cpp


# Create simple array-based version (olaSLC) of "SLCtester" program
olaSLC:                SLCtester.o SLC.o
	$(CXX) $(CXXFLAGS) SLCtester.o SLC.o -o olaSLC

SLCtester.o:                    SortedListTester.cpp SLC.h
	$(CXX) $(CXXFLAGS) -c -DSLC SortedListTester.cpp -o SLCtester.o

SLC.o:                    SLC.cpp SLC.h
	$(CXX) $(CXXFLAGS) -c SLC.cpp


# Remove object and executable files
clean:
	rm -f *.o olaDLL olaALL olaSLC 
