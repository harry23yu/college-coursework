CC=g++
EXE_FILE=driver_run
all: $(EXE_FILE)
$(EXE_FILE): student_db.o student_db.h driver.cpp
	$(CC) student_db.o driver.cpp -o $(EXE_FILE)
student_db.o: student_db.h student_db.cpp
	$(CC) -c student_db.cpp