obj=Meeting.o User.o Date.o Storage.o AgendaService.o AgendaUI.o

th:$(obj) Agenda.cpp
	g++ -std=c++0x -o th $(obj) Agenda.cpp
AgendaUI.o:AgendaUI.h AgendaUI.cpp
	g++ -std=c++0x -c AgendaUI.cpp
AgendaService.o:AgendaService.h AgendaService.cpp
	g++ -std=c++0x -c AgendaService.cpp
Meeting.o:Meeting.cpp Meeting.h
	g++ -std=c++0x -c Meeting.cpp
Date.o:Date.cpp Date.h
	g++ -std=c++0x -c Date.cpp
User.o:User.h User.cpp
	g++ -std=c++0x -c User.cpp
Storage.o:Storage.h Storage.cpp
	g++ -std=c++0x -c  Storage.cpp
.PHONY:clean
clean:
	-rm $(obj) th
