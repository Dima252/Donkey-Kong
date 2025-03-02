#include <limits>
#include <fstream>

#include "Results.h"

Results Results::loadResults(const std::string& filename) {
	std::ifstream results_file(filename);
	Results results;
	size_t size;
	results_file >> size;
	while (!results_file.eof() && size-- != 0) {
		size_t iteration;
		int result;
		results_file >> iteration >> result;
		results.addResult(iteration, static_cast<ResultValue>(result));
	}
	return results;
}

void Results::saveResults(const std::string& filename) const {
    // Step 1: Read the existing file contents
    std::ifstream infile(filename);
    size_t existing_size = 0;
    std::string file_contents;

    if (infile) {
        infile >> existing_size; // Read first number (previous results size)
        infile.ignore(); // Ignore the newline after the size
        
        // Read the rest of the file into `file_contents`
        file_contents.assign(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());

        infile.close();
    }

    // Step 2: Compute new total size
    size_t new_size = existing_size + results.size();

    // Step 3: Rewrite the entire file with the updated size
    std::ofstream outfile(filename);
    outfile << new_size << '\n'; // Overwrite first line with updated size

    // Preserve the rest of the file
    if (!file_contents.empty()) {
        outfile << file_contents;
    }

    // Step 4: Append the new results
    for (const auto& result : results) {
        outfile << '\n' << result.first << ' ' << result.second;
    }

    outfile.close();
}


size_t Results::getNextBombIteration() const {
	if (!results.empty() && results.front().second == hitBomb) {
		return results.front().first;
	}
	else return std::numeric_limits<size_t>::max(); // a big number we will never reach
}
