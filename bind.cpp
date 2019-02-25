//Parameter Binding
#include<iostream>
##include<algorithm>
##include<vector>
##include<set>

int main() {
set<int> myset = {2, 3, 4, 5}; // creating a set
vector<int> vec;

int x = multiplies<int>()(3,4);

// multiplies mysets elements by 10 and save in vec
transform(myset.begin(), myset.end(),
          back_inserter(vec), //destination
          bind(multiplies<int>(), placeholders::_1, 10)); //functor
// 1st parameter of multiplies<int>() is substituted with mysets element

}
