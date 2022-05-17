#include "problem_18.h"
#include "utils.h"
#include <string.h>
#include <sstream>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Tree {
    struct Node *node;
    struct Tree *next;
};

struct Node* new_node(int data)
{
    struct Node *my_node = NULL;

    my_node = (struct Node*)malloc(sizeof(struct Node));
    my_node->data = data;
    my_node->left = NULL;
    my_node->right = NULL;

    return my_node;
}

int compute_sum(struct Node *head)
{
    int sum = head->data;
    struct Node *current = head;

    while (current->left != NULL) {
        sum += current->data;
        current = current->left;
    }

    return sum;
}

int file_get_number_of_lines(const char *file)
{
    FILE *f = fopen(file, "r");
    char c = '0';
    int n = 0;

    while(c != EOF) {
        c = getc(f);
        if (c == '\n' || c == EOF)
            n++;
    }
    fclose(f);

    return n;
}

vector<vector<int>> read_file(const char *filename)
{
    ifstream file(filename);
    vector<vector<int>> all_num;
    string line;
    string num;

    if (file.fail()) {
        cout << "Error: " << filename << " does not exist ! " << endl;
        exit(-1);
    }

    while(getline(file, line)) {
        vector<int> v;
        stringstream ss;
        ss << line;
        while (getline(ss, num, ' ')) {
            v.push_back(stoi(num));
        }
        all_num.push_back(v);
    }

    return all_num;
}

struct Node *vector_to_tree(vector<vector<int>> v)
{
    struct Tree *tree = NULL;
    struct Node *head = NULL;
    struct Tree *current = NULL;

    tree = (struct Tree*)malloc(sizeof(struct Tree));

    head = new_node(v[0][0]);
    head->left = new_node(v[1][0]);
    head->right = new_node(v[1][1]);
    tree->node = head;

    for (int i = 1; i < v.size()-1; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            current->node = new_node(v[i][j]);
            // cout << v[i+1][j] << endl;
            current->node->left = new_node(v[i+1][j]);
            current->node->right = new_node(v[i+1][j+1]);

            tree->next = current;
            current->next = current;
            //tree->next = tree;
        }
    }

    return  tree->node;
}

int print_tree(vector<vector<int>> v, int i, int j, int sum)
{
    static int total = 0;

    sum += v[i][j];

    if (i == v.size()-1) {
        if (sum > total)
            total = sum;
        return total;
    }

    print_tree(v, ++i, j, sum);
    print_tree(v, i, ++j, sum);

    return total;
}

void display_tree(struct Node *n)
{
    if (n == NULL)
        return;

    cout << n->data << endl;
    display_tree(n->left);
    display_tree(n->right);
}

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int size = 0;
    int total = 0;
    vector<vector<int>> numbers;
    struct Node *tree = NULL;

    numbers = read_file(opt.file);
    size = numbers.size() * (numbers.size() + 1) / 2;

    /*
    tree = vector_to_tree(numbers);
    cout << "===========" << endl;
    display_tree(tree);
    */
    total = print_tree(numbers, 0, 0, 0);

    cout << "Result: " << total << endl;

    return 0;
}
