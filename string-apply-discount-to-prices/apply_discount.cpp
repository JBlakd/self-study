#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string discountPrices(string sentence, int discount) {
        istringstream iss(sentence);
        string word;
        string ret = "";

        while (iss >> word) {
            // reject words which don't start with '$'
            if (!is_valid_price(word)) {
                ret.append(word);
                ret.append(" ");
                word == "";
                continue;
            }

            if (discount == 100) {
                ret.append("$0.00 ");
                word == "";
                continue;
            }

            // convert int discount into double
            double discount_percentage = (double)discount / 100.0;

            double price = stod(word.substr(1)) * (1.0 - discount_percentage);

            ostringstream oss;
            oss << fixed << setprecision(2) << price;

            string trimmed_price = oss.str();

            ret.append("$");
            ret.append(trimmed_price);
            ret.append(" ");
            word == "";
        }

        // remove trailing space
        ret.pop_back();

        return ret;
    }

   private:
    bool is_valid_price(string word) {
        if (word.length() == 1) {
            return false;
        }

        if (word[0] != '$') {
            return false;
        }

        // at this point must start with '$'

        for (int i = 1; i < word.length(); ++i) {
            if (word[i] != '.' && !isdigit(word[i])) {
                return false;
            }
        }

        return true;
    }
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
    Solution solution;
    string sentence;
    int discount;

    sentence = "$1";
    discount = 99;
    cout << solution.discountPrices(sentence, discount) << endl;

    sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    discount = 100;
    cout << solution.discountPrices(sentence, discount) << endl;

    sentence = "there are $1 $2 and 5$ candies in the shop";
    discount = 50;
    cout << solution.discountPrices(sentence, discount) << endl;

    sentence = "$9999999999";
    discount = 5;
    cout << solution.discountPrices(sentence, discount) << endl;

    sentence = "$76111 ab $6 $";
    discount = 48;
    cout << solution.discountPrices(sentence, discount) << endl;
}
