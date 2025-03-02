
#include "Steps.h"
#include <fstream>

Steps Steps::loadSteps(const std::string& filename) {
	Steps steps;
	std::ifstream steps_file(filename);
	steps_file >> steps.randomSeed;
	size_t size;
	steps_file >> size;
	while (!steps_file.eof() && size-- != 0) {
		size_t iteration;
		char step;
		steps_file >> iteration >> step;
		steps.addStep(iteration, step);
	}
	steps_file.close();
	return steps;
}

void Steps::saveSteps(const std::string& filename) const {
    // Check if file is empty
    std::ifstream infile(filename, std::ios::ate); // Open in read mode, seek to end
    bool isEmpty = infile.tellg() == 0; // Check file size
    infile.close(); // Close the read file

    std::ofstream steps_file(filename, std::ios::app); // Open in append mode

    // Write randomSeed and steps.size() only if the file is empty
    if (isEmpty) {
        steps_file << randomSeed << '\n' << steps.size();
    }

    for (const auto& step : steps) {
        steps_file << '\n' << step.first << ' ' << step.second;
    }

    steps_file.close();
}
