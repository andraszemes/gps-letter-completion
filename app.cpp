#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
	// Load search string
	const std::string search = argv[1] ? argv[1] : std::string();

	// Initialize variables
	std::string place, res, msg;

	// Parse through stdin places
	while(std::getline(std::cin, place)) 
	{
		// If match found, append following character to result string
		if(!place.rfind(search, 0))
        	res += place[search.size()];
    }

    // Sort characters alphabetically
    std::sort(res.begin(), res.end());

    // Transform characters to uppercase
	transform(res.begin(), res.end(), res.begin(), ::toupper);

	// Determine feedback message
	switch(res.size())
	{
		case 0:
			msg = "Not found";
			break;
 
		case 1:
			msg = "Found: ";
			break;

		default:
			msg = "Enable: ";
	}

	// Remove duplicate characters from result
	res.erase(std::unique(res.begin(), res.end()), res.end());

	// Print result
	std::cout << msg << res;
}