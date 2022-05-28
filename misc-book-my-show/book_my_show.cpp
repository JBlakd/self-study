#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BookMyShow {
   public:
    BookMyShow(int n, int m) : rows(n), cols(m), num_avail_seats(rows, cols) {
    }

    vector<int> gather(int k, int maxRow) {
        for (int row = 0; row <= maxRow; ++row) {
            if (num_avail_seats[row] >= k) {
                // the group will sit starting from
                int start_seat = cols - num_avail_seats[row];
                num_avail_seats[row] -= k;
                return {row, start_seat};
            }
        }

        return {};
    }

    bool scatter(int k, int maxRow) {
        int last_row = -1;
        // Check if there are available seats first
        for (int row = 0; row <= maxRow; ++row) {
            if (num_avail_seats[row] != 0) {
                k -= num_avail_seats[row];
                if (k <= 0) {
                    last_row = row;
                    break;
                }
            }
        }

        if (last_row == -1) {
            return false;
        }

        // must be true
        for (int row = 0; row < last_row; ++row) {
            num_avail_seats[row] = 0;
        }
        // Do the last row
        num_avail_seats[last_row] = k * -1;
        return true;
    }

   private:
    int rows;
    int cols;
    vector<int> num_avail_seats;
};

template <typename T>
void print_vector(vector<T> vec) {
    cout << "{";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}";
}

int main() {
    BookMyShow solution(2, 5);
    print_vector(solution.gather(4, 0));  // {0,0}
    cout << endl;
    print_vector(solution.gather(2, 0));  // {}
    cout << endl;
    cout << solution.scatter(5, 1) << endl;  // 1
    cout << solution.scatter(5, 1) << endl;  // 0
}
