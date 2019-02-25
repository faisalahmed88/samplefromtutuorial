/* Functors or Function Objects

1. What are functors ?

Define class X and define the operator() for X which would take string as
a parameter.
In the first example, we can use foo as it is a function. Functors expands the
idea of function as any thing behave like a function is function, provided by
functors.

This is a type conversion statement very similar to functor operator function.
Difference lies in the positioning of type before in functor statement and
after in type conversion statement.

operator string () const {return "X";} // type conversion function
void operator()(std::string str) {} // functor statement

2. Benifits ?

Functors are Smart function that can do more things than regular functions
take class X. X can define own member data to remember the state of the
functor. Using these members, function for functors can be overloaded.

Two functors can have different types even though they have the same
signatures.

Functors intoduces parametrized function e.g.
class X {
    public:
    X(int i) {}
    void operator() (std::string str) {
        std::cout<<"Calling functor X with parameter "<<str<<std::endl;
    }

int main () {
    X(8)("Hi");
    return 0;
}

The question is why do we want something like that X(8)("Hi");

See example 2:



void add2(int i) {
    std::cout<<i+2<<std::endl;
}


int main () {
    std::vector<int> vec = {2, 3, 4, 5};
    for_each(vec.begin(), vec.end(), add2)

    return 0;
}


The issue in above add2 function is 2 and the hard coded should be avoided.
1 way is define a global variable and place it into integer. NOT GOOD IDEA,
global variables are not preferred.

2nd way is to define a template
template<int val>
void addVal(int i) {
std::cout<<val+i<<std::endl;
}

and in main function
for_each(vec.begin(), vec.end(), addVal<2>);

In the above template addition case: it seems to work but if i put
x=2; and put x instead of 2 in next line
for_each(vec.begin(), vec.end(), addVal<x>); it will not work


DO, Waht is the best solutuion: Functors (Parametrized)


*/



/*

// Example 1: How to define them?

#include<iostream>
#include<thread>
#include<string>
using namespace std;

class X {
public:
    void operator()(std::string str) {
        std::cout<<"Calling functor X with parameter "<<str<<std::endl;
    }
};
int main() {
X foo;
foo("Hi");
return 0;
}
*/


// Example 2: Benifits: Parameterization

/*
#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class addValue {
    int val;
public:
    addValue(int j): val(j) {}
    void operator()(int i) {
        std::cout<<i+val<<std::endl;
    }
};
int main () {
    std::vector<int> vec = {2, 3, 4, 5};
    int x=2;
    for_each(vec.begin(), vec.end(), addValue(x));

    return 0;
}


*/

// Build in dunctions

/*
standard library provide built in functors for:
less greater greater_equal less_equal not_equal_to
logical_and logical_not logical_or
multiplies minus plus divide modulud negate

int x = multiplies<int> () (3,4);
if (not_equal_to<int>()(x, 10))
std::cout<<x<<std::endl;




//Parameter Binding

set<int> myset = {2, 3, 4, 5};
vector<int> vec;

int x = multiplies<int>()(3,4);

// multiplies mysets elements by 10 and save in vec
transform(myset.begin(), myset.end(),
          back_inserter(vec), //destination
          bind(multiplies<int>(), placeholders::_1, 10)); //functor
// 1st parameter of multiplies<int>() is substituted with mysets element
*/

#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
