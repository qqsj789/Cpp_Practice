/*

Vector push_back

Now that you are able to process a string, you may want to store the results of the processing in a convenient container for later use.
In the next exercise, you will store the streamed ints from each line of the board in a vector<int>.
To do this, you will add the ints to the back of the vector, using he vector method push_back:

向量 push_back

既然您能够处理字符串，您可能希望将处理结果存储在方便的容器中以备后用。
在下一个练习中，您将把来自棋盘每一行的流式整数存储在一个 vector<int> 中。
为此，您将使用向量方法 push_back 将整数添加到向量的后面： 

*/


#include <vector>
#include <iostream>
using std::vector;
using std::cout;


/////////////////////
// push_back(data)
/////////////////////
int main() {
    // Initial Vector
    vector<int> v {1, 2, 3};
    // vector v {1, 2, 3}; //works only on c++17 without vector type

    // Print the contents of the vector
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }

    // Push 4 to the back of the vector
    v.push_back(4);

    // Print the contents again
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }

}
