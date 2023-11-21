#include "commandline.hpp"
#include "models/database.hpp"

#include <iostream>
#include <cstring>
#include <cstdlib>

int main(int argc, char* argv[]) {
	setenv("DBNAME", "database.db", 0);
	if (argc > 1 && strcmp(argv[1], "migrate") == 0) {
		Database database;
		database.createDb();
	} else {
		CommandLine commandLine;
		commandLine.run();
	}
}
