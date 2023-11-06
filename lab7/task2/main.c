#include <assert.h>

#include <algc.h>

void test() {
    Tree root = CreateRoot();

    assert(IsEmptyTree(root) && TreeError == TreeOk);

    // Создадим 5 деревьев
    InitTree(root, 5);
    assert(TreeError == TreeOk);
    assert(!IsEmptyTree(root) && TreeError == TreeOk);

    Tree t1 = MoveToRSon(root);
    assert(TreeError == TreeOk);
    Tree t2 = MoveToLSon(t1);
    assert(TreeError == TreeOk);
    Tree t3 = MoveToLSon(t2);
    assert(TreeError == TreeOk);
    Tree t4 = MoveToLSon(t3);
    assert(TreeError == TreeOk);
    Tree t5 = MoveToLSon(t4);
    assert(TreeError == TreeOk);

    int i1 = 1;
    WriteDataTree(t1, &i1);
    assert(TreeError == TreeOk && *((int*)ReadDataTree(t1)) == 1 && TreeError == TreeOk);
    
    DelTree(t1);
    assert(IsEmptyTree(t1) && TreeError == TreeOk);

    InitTree(t2, TreeBufferSize - Size);
    assert(TreeError == TreeOk && EmptyMem());
    InitTree(t3, 1);
    assert(TreeError == TreeNotMem);

    DelTree(root);
    assert(IsEmptyTree(root) && TreeError == TreeOk);
    InitTree(root, 5);
    InitMem();
    assert(IsEmptyTree(root) && TreeError == TreeOk);
}

int main() {
    test();

    return 0;
}