// The header file with just the function declarations.
// When you click the "Run Code" button, this file will
// be saved as header_example.h.


//include guard
#ifndef HEADER_EXAMPLE_H
#define HEADER_EXAMPLE_H

//don't need variable names, just variable types.
void OuterFunction(int);
void InnerFunction(int);

#endif


/*
NOTE:
The function declarations in the header file don't need variable names, just variable types.
You can put names in the declaration, however, and doing this often makes the code easier to read.
The #include statement for the header used quotes " " around the file name, and not angle brackets <>.
We have stored the header in the same directory as the .cpp file, and the quotes tell the preprocessor
to look for the file in the same directory as the current file - not in the usual set of directories where libraries are typically stored.

笔记：
头文件中的函数声明不需要变量名，只需要变量类型。
但是，您可以将名称放在声明中，这样做通常会使代码更易于阅读。
标题的#include 语句在文件名周围使用引号“”，而不是尖括号<>。
我们将头文件存储在与 .cpp 文件相同的目录中，引号告诉预处理器
在与当前文件相同的目录中查找文件 -而不是在通常存储库的通常目录集中。

Finally, there is a preprocessor directive(预处理程序指令):
    #ifndef HEADER_EXAMPLE_H
    #define HEADER_EXAMPLE_H
at the top of the header, along with an #endif at the end. This is called an "include guard".
Since the header will be included into another file, and #include just pastes contents into a file,
the include guard prevents the same file from being pasted multiple times into another file.
This might happen if multiple files include the same header, and then are all included into the same main.cpp, for example.
The ifndef checks if HEADER_EXAMPLE_H has not been defined in the file already. If it has not been defined yet,
then it is defined with #define HEADER_EXAMPLE_H, and the rest of the header is used. If HEADER_EXAMPLE_H has already been defined,
then the preprocessor does not enter the ifndef block. Note: There are other ways to do this.
Another common way is to use an #pragma oncepreprocessor directive, but we won't cover that in detail here. See this Wikipedia article for examples.

在标题的顶部，最后是 #endif。这称为“包含保护”。
由于标题将被包含到另一个文件中，而#include 只是将内容粘贴到一个文件中，
包含保护可防止将同一文件多次粘贴到另一个文件中。
例如，如果多个文件包含相同的标头，然后都包含在同一个 main.cpp 中，则可能会发生这种情况。
ifndef 检查 HEADER_EXAMPLE_H 是否尚未在文件中定义。如果还没有定义，
然后用#define HEADER_EXAMPLE_H 定义它，并使用标题的其余部分。如果已经定义了 HEADER_EXAMPLE_H，
那么预处理器不会进入 ifndef 块。注意：还有其他方法可以做到这一点。
另一种常见的方法是使用 #pragma oncepreprocessor 指令，但我们不会在这里详细介绍。有关示例，请参阅此 Wikipedia 文章。

*/
