
/*

In the previous exercises, you stored and printed the board as a vector<vector<int>>,
where only two states were used for each cell: 0 and 1. This is a great way to get started,
but as the program becomes more complicated, there will be more than two possible states for each cell.
Additionally, it would be nice to print the board in a way that clearly indicates open areas and obstacles,
just as the board is printed above.

To do this clearly in your code, you will learn about and use something called an enum.
An enum, short for enumerator, is a way to define a type in C++ with values that are restricted to a fixed range.
For an explanation and examples, see the notebook below.

在前面的练习中，您将电路板存储并打印为 vector<vector<int>>，
每个单元格只使用两种状态：0 和 1。这是一个很好的入门方式，
但随着程序变得越来越复杂，每个单元格将有两个以上的可能状态。
此外，以清晰指示开放区域和障碍物的方式打印板会很好，
就像上面印有电路板一样。

为了在您的代码中清楚地做到这一点，您将学习并使用称为枚举的东西。
enum 是 enumerator 的缩写，是一种在 C++ 中定义类型的方法，其值限制在固定范围内。
有关解释和示例，请参阅下面的笔记本。 

*/


#include <iostream>
using std::cout;


/*
Enums
C++ allows you to define a custom type which has values limited to a specific range you list or "enumerate".
This custom type is called an "enum".

Suppose you were writing a program that stores information about each user's car, including the color.
You could define a Color enum in your program, with a fixed range of all the acceptable values:

C++ 允许您定义一个自定义类型，该类型的值仅限于您列出或“枚举”的特定范围。
这种自定义类型称为“枚举”。

假设您正在编写一个程序来存储每个用户的汽车信息，包括颜色。
你可以在你的程序中定义一个 Color 枚举，所有可接受的值都有一个固定的范围 

We want to limited the possible colors.


    white
    black
    blue
    red

https://en.cppreference.com/w/cpp/language/enum

scoped enums
    => enum + class/structure + name {items}

unscoped enums (only remove the class/sturcture from scoped enums)
    => enum + name {items}

*/

void scoped_enum(){
    // Create the enum Color with fixed values.
    // scoped enum
    enum class Color {white,
                      black,
                      blue,
                      red};

    // Create a Color variable and set it to Color::blue.
    Color my_color;
    //assign
    my_color = Color::blue;

    // Test to see if my car is red.
    if (my_color == Color::red) {
        cout << "The color of my car is red!" << "\n";
    } else {
        cout << "The color of my car is not red." << "\n";
    }
}

void unscoped_enum(){

    enum Color {  white =0,
                  black,
                  blue,
                  red};

    Color my_color = blue;
    cout << my_color << "\n";
    // Test to see if my car is red.
    if (my_color == red) {
        cout << "The color of my car is red!" << "\n";
    } else {
        cout << "The color of my car is not red." << "\n";
    }
}

void enum_switch(){

    enum class keypad {up,down,left,right};

    keypad input;
    input = keypad::down;

    switch(input){
        case keypad::up:
            cout<<"up"<<"\n";
            break;
        case keypad::down:
            cout<<"down"<<"\n";
            break;
        case keypad::left:
            cout<<"left"<<"\n";
            break;
        case keypad::right:
            cout<<"right"<<"\n";
            break;
    }
}

int main()
{
    scoped_enum();
    unscoped_enum();
    enum_switch();
}
