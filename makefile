BIN_FOLDER = ./bin/
SRC_FOLDER = ./src/
FILES_FOLDER = ./files_output/

CC = gcc

all:

execute_1: 
	$(CC) $(SRC_FOLDER)koch_island.c -o $(BIN_FOLDER)koch_island
	$(BIN_FOLDER)koch_island

execute_2:
	$(CC) $(SRC_FOLDER)hilbert_curve.c -o $(BIN_FOLDER)hilbert_curve
	$(BIN_FOLDER)hilbert_curve

execute_3:
	$(CC) $(SRC_FOLDER)my_curve.c -o $(BIN_FOLDER)my_curve
	$(BIN_FOLDER)my_curve


clean_bin:
	@rm -rf $(BIN_FOLDER)*

clean_files:
	@rm -rf $(FILES_FOLDER)*

clean:
	@rm -rf $(BIN_FOLDER)* $(FILES_FOLDER)*