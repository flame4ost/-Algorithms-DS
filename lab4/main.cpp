#include <iostream>
#include <ctime>
#include <cstdlib>

int NUMBER = 0;
class Branch
{
public:
    int value;
    Branch* left;
    Branch* right;

    Branch() : value(NUMBER++), left(0), right(0)
    { }
};

void fillBranch(Branch* branch)
{
    if (rand() % 2 == 1)
    {
        branch->left = new Branch;
        fillBranch(branch->left);
    }
    if (rand() % 2 == 1)
    {
        branch->right = new Branch;
        fillBranch(branch->right);
    }
}

int calcBranchsCount(Branch* branch)
{
    int n = 0;
    if (branch->left)
    {
        n++;
        n += calcBranchsCount(branch->left);
    }
    if (branch->right)
    {
        n++;
        n += calcBranchsCount(branch->right);
    }
    return n;
}

void recursiveViewBranchs(Branch* root)
{
    int l = 0, r = 0;
    if (root->left)
    {
        recursiveViewBranchs(root->left);
        l = calcBranchsCount(root->left);
        l++;
    }
    if (root->right)
    {
        recursiveViewBranchs(root->right);
        r = calcBranchsCount(root->right);
        r++;
    }

    if(l != r)
    std::cout << "В " << root->value << " ветке разное кол-во веток[" << l << ',' << r << "];" << std::endl;
}

int main()
{
    srand(time(0));
    setlocale(0, "");
    Branch b;
    fillBranch(&b);

    recursiveViewBranchs(&b);

    return 0;
}

