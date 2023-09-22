#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



int namesq(int a, int b)
{
    if (b == 0)
        return 0;
    else
        return a / b + namesq(b, a % b);
}

void dop3(vector<int>& nums, int index) {
    if (index == nums.size()) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
  
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        dop3(nums, index + 1);
        swap(nums[index], nums[i]);
    }
}


int min_border_count = INT_MAX;
vector<int> best_partition;

void partition_countries(const vector<std::vector<int>>& adj_matrix, vector<int>& current_partition, int index) {
    if (index == adj_matrix.size()) {
        int border_count = 0;
        for (int i = 0; i < adj_matrix.size(); i++) {
            for (int j = i + 1; j < adj_matrix.size(); j++) {
                if (adj_matrix[i][j] == 1 && current_partition[i] != current_partition[j]) {
                    border_count++;
                }
            }
        }
        if (border_count < min_border_count) {
            bool isSame = true;
            for (int i = 1; i < current_partition.size(); i++) {
                if (current_partition[i - 1] != current_partition[i]) {
                    isSame = false;
                    break;
                }
            }
            if (!isSame) {
                min_border_count = border_count;
                best_partition = current_partition;
            }
            
        }
        return;
    }

    current_partition[index] = 0;
    partition_countries(adj_matrix, current_partition, index + 1);
    current_partition[index] = 1;
    partition_countries(adj_matrix, current_partition, index + 1);
}

void generate_numbers(int A, int position, vector<int>& current_number, ofstream& output_file) {
    if (position == A) {
        for (int digit : current_number) {
            output_file << digit;
        }
        output_file << endl;
        return;
    }

    for (int i = 1; i <= A; i++) {
        current_number[position] = i;
        generate_numbers(A, position + 1, current_number, output_file);
    }
}

void main()
{
    setlocale(LC_ALL, "rus");
    int a, b, n;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    int numSquares = namesq(a, b);
    cout << numSquares << endl;
    cout << "dop3" << endl;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    dop3(nums, 0);
    //dop2
    cout << "dop2" << endl;
    cout << "количество стран:";
    cin >> n;
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }
    /* 0 1 1 0
       1 0 1 1
       1 1 0 1
       0 1 1 0*/
    vector<int> current_partition(n);

    partition_countries(adj_matrix, current_partition, 0);

    cout << "Минимальное количество пар с общими границами: " << min_border_count << std::endl;

    cout << "Подразделение стран:" << endl;
    for (int i = 0; i < n; i++) {
        if (best_partition[i] == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (best_partition[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    cout << "dop1" << endl;
    int A;
    cout << "Введите цифру A: ";
    cin >> A;
    vector<int> current_number(A);
    ofstream output_file("numbers.txt");
    generate_numbers(A, 0, current_number, output_file);
    output_file.close();
}