#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>


class Petris {
 public:
  void Insert(int col_number, int color) {
    if (grid_.empty()) {
      grid_.push_back({});
    }

    auto& column = GetColumn(col_number);
    column.push_back(color);
    UpadeColumn(column);
    if (column.empty()) {
      UpdateGrid();
    }
  }

  void Print(int cases) {
    if (!grid_.empty()) {
      std:: cout << "caso " << cases << ":";
      for (auto& col : grid_) {
        std::cout << " " << col.back();
      }
      std::cout << std::endl;
    }
    else {
      std::cout << "caso " << cases << ":" << std:: endl;
    }
  }

  void Clear() {
    grid_.clear();
  }

 private:
  using Column = std::vector<int>;

  Column& GetColumn(int col_number) {
    if (col_number == grid_.size() + 1) {
      grid_.push_back({});
      return grid_.back();
    }
    if (col_number == 0) {
      grid_.push_front({});
      return grid_.front();
    }
    return grid_[col_number - 1];
  }

  void UpadeColumn(Column& column) {
    if (column.size() > 1) {
      auto size = column.size();
      bool is_last_two_equal = column[size - 1] == column[size - 2];
      if (is_last_two_equal) {
        column.pop_back();
        column.pop_back();
      }
    }
  }

  void UpdateGrid() {
    auto it =
        std::find_if(grid_.begin(), grid_.end(), [](const Column& col) { return col.empty(); });
    grid_.erase(it);
  }

  std::deque<Column> grid_; //grid da classe petris de tamanho n colunas do tipo deque
};

int main() {
  Petris petris{};

  //std:: string str;
  //std:: string sentinel = "END";

  int num_cases = 0;
  int i = 0;
  
  std:: cin >> num_cases;
  std:: cin.clear();
  std:: cin.ignore(100, '\n');
 
  while(i < num_cases) {
    //std::getline(std::cin, str);
    int fds[2] = {6969, 6969};
    std:: cin >> fds[0] >> fds[1];

    std:: cin.clear();
    std:: cin.ignore(100, '\n');

    if (fds[1] == 6969) {
      petris.Print(i);
      petris.Clear();
      ++i;
    }
    // if(str.compare(sentinel) == 0) {
    //   petris.Print(i);
    //   petris.Clear();
    //   ++i; //so vai pro pox. caso se chegar no fim
    // }
    else{
      //extractIntegerWords(str, fds);
      petris.Insert(fds[0], fds[1]);  
    }

  }
  return 0;
}
