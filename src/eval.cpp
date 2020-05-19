#include <unordered_map>
#include <vector>
#include <string>
#include <variant>
#include <sstream>
#include "eval.hpp"


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


// forward declaration
std::stringstream print_val(lisp_val);
std::stringstream print_list_val (std::vector<lisp_val>*);

std::stringstream print_val(lisp_val lv){
    std::stringstream sstr;
    switch(lv.lv_type){
        case lv_atom:
          sstr.str(*lv.atom);
          return sstr;
          break;
        case lv_list:
          print_list_val(lv.list);
          break;
        case lv_num:
          sstr.str(std::to_string(lv.num)); 
          return sstr;
          break;
        case lv_boolean:
          sstr.str(std::to_string(lv.boolean));
          break;
    }
}

std::stringstream print_list_val(std::vector<lisp_val>* list_lv){
    std::stringstream sstr("(", std::ios_base::app | std::ios_base::out);
    std::vector<lisp_val>::iterator ptr;
    for (ptr = list_lv->begin(); ptr < list_lv->end(); ptr++){
        sstr << print_val(*ptr).str();
    }
    return sstr;
}
