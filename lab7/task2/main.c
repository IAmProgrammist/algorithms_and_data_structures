#include <assert.h>

#include <algc.h>

void testInitTree() {
    Tree root = InitTree(0);
    assert(TreeError == TreeUnder);

    root = InitTree(10);
    assert(TreeError == TreeOk && Size == 10);

    root = InitTree(TreeBufferSize + 1);
    assert(TreeError == TreeNotMem);
}

void testCreateRoot() {
    Tree init = InitTree(1);
    Tree root = CreateRoot();
    assert(TreeError == TreeNotMem);

    init = InitTree(2);
    root = CreateRoot();
    assert(TreeError == TreeOk);
    assert(IsEmptyTree(root));
    root = CreateRoot();
    assert(TreeError == TreeNotMem);
}

void testMemEmpty() {
    Tree init = InitTree(1);
    assert(EmptyMem());

    init = InitTree(2);
    assert(!EmptyMem());

    init = InitTree(2);
    Tree root = CreateRoot();
    assert(EmptyMem());
}

void testNewMem() {
    Tree init = InitTree(1);
    Tree newEl = NewMem();
    assert(TreeError == TreeNotMem);

    init = InitTree(2);
    newEl = NewMem();
    assert(TreeError == TreeOk);
    NewMem();
    assert(TreeError == TreeNotMem);
}

void testDisposeMem() {
    Tree init = InitTree(2);
    Tree newEl = NewMem();
    assert(TreeError == TreeOk && EmptyMem());
    DisposeMem(newEl);
    assert(TreeError == TreeOk && !EmptyMem());
}

void testWriteReadDataTree() {
    Tree init = InitTree(2);
    Tree root = CreateRoot();

    int someVal = 15;
    WriteDataTree(root, &someVal);
    assert(TreeError == TreeOk);
    assert(*(int*)ReadDataTree(root) == someVal && TreeError == TreeOk);
}

void testIsLSonMoveToLSon() {
    Tree init = InitTree(6);
    Tree root = CreateRoot();

    Tree ex = MoveToLSon(root);
    assert(TreeError == TreeUnder);

    Tree newEl = NewMem();
    MemTree[root].LSon = newEl;
    assert(IsLSon(root) && TreeError == TreeOk && MoveToLSon(root) == newEl && TreeError == TreeOk);
}

void testIsRSonMoveToRSon() {
    Tree init = InitTree(6);
    Tree root = CreateRoot();

    Tree ex = MoveToRSon(root);
    assert(TreeError == TreeUnder);

    Tree newEl = NewMem();
    MemTree[root].RSon = newEl;
    assert(IsRSon(root) && TreeError == TreeOk && MoveToRSon(root) == newEl && TreeError == TreeOk);
}

void testDelTree() {
    Tree init = InitTree(6);
    Tree root = CreateRoot();

    Tree newEl1 = NewMem();
    MemTree[root].LSon = newEl1;
    Tree newEl2 = NewMem();
    MemTree[root].RSon = newEl2;

    MemTree[newEl1].LSon = 0;
    MemTree[newEl1].RSon = 0;
    MemTree[newEl2].LSon = 0;
    MemTree[newEl2].RSon = 0;

    DelTree(root);
    assert(TreeError == TreeOk);
}

void test() {
    testInitTree();
    testCreateRoot();
    testMemEmpty();
    testNewMem();
    testDisposeMem();
    testWriteReadDataTree();
    testIsLSonMoveToLSon();
    testIsRSonMoveToRSon();
    testDelTree();
}

int main() {
    test();

    return 0;
}