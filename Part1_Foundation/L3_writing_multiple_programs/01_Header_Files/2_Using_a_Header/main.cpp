/*

Using a Header
One other way to solve the code problem above (without rearranging the functions) would have been to declare each function at the top of the file.
A function declaration is much like the first line of a function definition - it contains the return type,
function name, and input variable types. The details of the function definition are not needed for the declaration though.

To avoid a single file from becomming cluttered with declarations and definitions for every function,
it is customary to declare the functions in another file, called the header file.
In C++, the header file will have filetype .h, and the contents of the header file must be included at the top of the .cpp file.
See the following example for a refactoring of the code above into a header and a cpp file.

使用标题
解决上述代码问题的另一种方法（无需重新排列函数）是在文件顶部声明每个函数。
函数声明很像函数定义的第一行——它包含返回类型，
函数名和输入变量类型。但是，声明不需要函数定义的详细信息。

为了避免单个文件被每个函数的声明和定义弄得杂乱无章，
通常在另一个文件中声明函数，称为头文件。
在 C++ 中，头文件的文件类型为 .h，头文件的内容必须包含在 .cpp 文件的顶部。
有关将上述代码重构为标头和 cpp 文件的示例，请参见以下示例。 

*/



// The contents of header_example.h are included in
// the corresponding .cpp file using quotes:

//find .h in the same directory as the .cpp file
#include "header_example.h"

#include <iostream>
using std::cout;

void OuterFunction(int i)
{
    InnerFunction(i);
}

void InnerFunction(int i)
{
    cout << "The value of the integer is: " << i << "\n";
}

int main()
{
    int a = 5;
    OuterFunction(a);
}
