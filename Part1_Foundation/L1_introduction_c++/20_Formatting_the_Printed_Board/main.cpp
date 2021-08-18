/*
Formatting the Printed Board
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   ⛰️   0   0   0   0
0   0    0   0  ⛰️   0

The board will eventually have more than two cell states as the program becomes more complicated,
and it would be nice to add formatting to the printed output of the board to ensure readability as the number of board states increases.

To accommodate more board states and facilitate print formatting, we have provided the State enum
with enumerator values kEmpty and kObstacle. In this exercise,
you will write a CellString function which converts each State to an appropriate string.
In the next exercise, we will update the program to use the enum values and CellString function.

随着程序变得越来越复杂，董事会最终将拥有两个以上的单元格状态，
并且最好在板的打印输出中添加格式以确保随着板状态数量增加的可读性。

为了适应更多的董事会状态并促进打印格式，我们提供了 State 枚举
具有枚举值 kEmpty 和 kObstacle。在这个练习中，
您将编写一个 CellString 函数，该函数将每个状态转换为适当的字符串。
在下一个练习中，我们将更新程序以使用枚举值和 CellString 函数

*/


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

vector<int> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<int>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "
string CellString(State cell){
    switch(cell){
        case State::kEmpty:
            return "0  ";
        case State::kObstacle:
            return "⛰️  ";
    }
}


void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}
