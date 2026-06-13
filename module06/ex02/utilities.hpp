#pragma once

#include "Base.hpp"
#include <cstdlib>
#include <ctime> 
#include <iostream> 
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);

void identify(Base* p);

void identify(Base& p);
