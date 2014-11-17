//
//  extras.h
//  Sample
//
//  Created by Lyle Moffitt on 11/17/14.
//  Copyright (c) 2014 Lyle Moffitt. All rights reserved.
//

#ifndef Sample_extras_h
#define Sample_extras_h

#include <string>
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#include <typeinfo>
#include <type_traits>

inline
std::string 
demangle(const char* name) 
{//src: http://stackoverflow.com/questions/281818/unmangling-the-result-of-stdtype-infoname    
    int status = -4; // some arbitrary value to eliminate the compiler warning
    
    std::unique_ptr<char, void(*)(void*)> res {
        //see: https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a01696.html
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };
    
    return (status==0) ? res.get() : name ;
}



#define print_type( type )\
std::cout<<"\ttypeof( "<< #type <<") is "<<demangle(typeid(type).name())<<std::endl 


#endif
