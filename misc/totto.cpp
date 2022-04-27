#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumSoldiers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 *  3. 2D_INTEGER_ARRAY C
 */

int minimumSoldiers(vector<int> A, vector<int> B, vector<vector<int>> swaps) {
    int soldiers_alive = 0;

    for (auto swap : swaps) {
        // perform swap on the copy
        // vector<int> A_copy = A;
        int temp = A[swap[0]];
        A[swap[0]] = A[swap[1]];
        A[swap[1]] = temp;
    }

    // compare
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            ++soldiers_alive;
        }
    }

    return soldiers_alive;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string A_count_temp;
    getline(cin, A_count_temp);

    int A_count = stoi(ltrim(rtrim(A_count_temp)));

    vector<int> A(A_count);
    string A_row_temp_temp;
    getline(cin, A_row_temp_temp);
    vector<string> A_row_temp = split(rtrim(A_row_temp_temp));
    for (int i = 0; i < A_count; i++) {
        int A_item = stoi(ltrim(rtrim(A_row_temp[i])));

        A[i] = A_item;
    }

    string B_count_temp;
    // getline(cin, B_count_temp);

    int B_count = A_count;
    vector<int> B(B_count);
    string B_row_temp_temp;
    getline(cin, B_row_temp_temp);
    vector<string> B_row_temp = split(rtrim(B_row_temp_temp));
    for (int i = 0; i < B_count; i++) {
        int B_item = stoi(ltrim(rtrim(B_row_temp[i])));

        B[i] = B_item;
    }

    string C_rows_temp;
    getline(cin, C_rows_temp);

    int C_rows = stoi(ltrim(rtrim(C_rows_temp)));

    int C_columns = 2;

    vector<vector<int>> C(C_rows);

    for (int i = 0; i < C_rows; i++) {
        C[i].resize(C_columns);

        string C_row_temp_temp;
        getline(cin, C_row_temp_temp);

        vector<string> C_row_temp = split(rtrim(C_row_temp_temp));

        for (int j = 0; j < C_columns; j++) {
            int C_row_item = stoi(C_row_temp[j]);

            C[i][j] = C_row_item;
        }
    }

    int result = minimumSoldiers(A, B, C);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
