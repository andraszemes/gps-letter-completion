#include <iostream>
#include <string>
#include <algorithm>


// Class of const return messages
class Message
{
public:
    static constexpr const char* MATCH_FOUND = "Match found";
    static constexpr const char* NOT_FOUND = "Not found";
    static constexpr const char* FOUND = "Found: ";
    static constexpr const char* ENABLE = "Enable: ";
};


int main(int argc, char *argv[])
{
    // Load search string
    const std::string search = argv[1] ? argv[1] : std::string();
    const int len = search.size();

    // Initialize variables
    std::string place, res, msg;

    // Parse through stdin places
    while(std::getline(std::cin, place)) 
    {
        // If exact match found
        if(!place.compare(search))
            msg = Message::MATCH_FOUND;

        // If partial match found, append following character to result string
        else if(!place.rfind(search, 0))
            res += place[search.size()];
    }

    // Sort characters alphabetically
    std::sort(res.begin(), res.end());

    // Transform characters to uppercase
    transform(res.begin(), res.end(), res.begin(), ::toupper);

    // Determine feedback message
    if(msg.empty())
    {
        switch(res.size())
        {
            case 0:
                msg = Message::NOT_FOUND;
                break;
    
            case 1:
                msg = Message::FOUND;
                break;
    
            default:
                msg = Message::ENABLE;
        }
    }

    // Remove duplicate characters from result
    res.erase(std::unique(res.begin(), res.end()), res.end());

    // Print result and search term
    std::cout << msg << res << std::endl;
    std::cout << "Search term: " << search;

    return 0;
}