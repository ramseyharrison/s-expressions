#include "types.hpp"
#include <vector>
class parser {
private:
    std::string input;
    std::string buffer;
    exp *parse_result;
    std::string::iterator it;

    exp *atom_or_pair();

    exp *pair();

    exp *atom();

    void next();

    void add();

    bool see_initial();

    bool see_subsequent();

    bool see_letter();

    bool see_digit();

    bool see_quote();

    exp *string();

    exp *identifier();

    exp *integer();

    bool see_boolean();


public:
    parser(std::string);
    exp *get_result();
    std::string::iterator get_it();
    std::string get_input();
    std::string remaining_input();

};
