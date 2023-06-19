#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <cstring>

class Petris {
 public:
  void Insert(int color) {
    if (grid_.empty()) {
      grid_.push_back({});
    }

    auto& column = GetColumn(1);
    column.push_back(color);
    UpdateColumn(column);
    //if (column.empty()) {
      //UpdateGrid();
    //}
  }

  void Print(int cases) {
    auto& column = GetColumn(1);
    if (column.size() < 1) {
        std:: cout << "caso " << cases << ": 0 -1" << std::endl;
        column.clear();
    }
    else {
        std:: cout << "caso " << cases << ": " << column.size() << " " << column.back() << std::endl;
        column.clear();
    }
    
  }

 private:
  using Column = std::vector<int>;

  Column& GetColumn(int col_number) {
    // if (col_number == grid_.size() + 1) {
    //   grid_.push_back({});
    //   return grid_.back();
    // }
    // if (col_number == 0) {
    //   grid_.push_front({});
    //   return grid_.front();
    // }
    return grid_[col_number - 1];
  }

  void UpdateColumn(Column& column) {
    if (column.size() > 1) {
      auto size = column.size();
      bool is_last_two_equal = column[size - 1] == column[size - 2];
      if (is_last_two_equal) {
        column.pop_back();
        column.pop_back();
      }
    }
  }

  //void UpdateGrid() {
    //auto it =
        //std::find_if(grid_.begin(), grid_.end(), [](const Column& col) { return col.empty(); });
    //grid_.erase(it);
  //}

  std::deque<Column> grid_;
};

int main() {
    Petris petris{};

    char str[4];
    char sentinel[] = "END";

    int num_cases = 0;
    int i = 0;
    std:: cin >> num_cases;

    while(i < num_cases) {
        std:: cin >> str;
        if(strcmp(str, sentinel) == 0) {
            petris.Print(i);
            ++i; //so vai pro pox. caso se chegar no fim
        }
        else{
            int val = std:: atoi(str);
            petris.Insert(val);
        }

    }








//   petris.Insert(4);
//   petris.Insert(4);
//   petris.Insert(2);
//   petris.Insert(3);
//   petris.Insert(4);
//   petris.Insert(4);
//   petris.Insert(3);
//   petris.Insert(2);
//   petris.Insert(4);
//   petris.Insert(2);
//   petris.Insert(3);
//   petris.Insert(4);
//   petris.Insert(4);

  return 0;
}
