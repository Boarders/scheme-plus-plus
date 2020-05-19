#include <unordered_map>
#include <vector>
#include <string>
#include <variant>
#include <sstream>

enum lv_type {lv_atom, lv_list, lv_num, lv_string, lv_boolean};

typedef struct _lisp_val{
    lv_type lv_type;
    union {
        std::string* atom;
        std::vector<lisp_val>* list;
        int num;
        std::string* string;
        bool boolean;
    };
} lisp_val;

std::stringstream print_val(lisp_val);
std::stringstream print_list_val (std::vector<lisp_val>*);

