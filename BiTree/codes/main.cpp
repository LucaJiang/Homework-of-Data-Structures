//实验六2019-05-06
//树及其操作
//最后修改2019-05-10
#include <iostream>
#include "BiTree.cpp"
using namespace std;
int main()
{ 
	//--------第1题-----------
	BiTree<char> bt; //创建一棵树 
	BiNode<char>* root = bt.Getroot();  //获取指向根结点的指针 
	cout << "------前序遍历------ " << endl;
	bt.PreOrder(root);
	cout << endl;
	cout << "------中序遍历------ " << endl;
	bt.InOrder(root);
	cout << endl;
	cout << "------后序遍历------ " << endl;
	bt.PostOrder(root);
	cout << endl;
	cout << "------层序遍历------ " << endl;
	bt.LeverOrder(root);
	cout << endl << endl;
	//--------第2题-----------
	cout << "查询节点a:";
	bt.info('a');
	cout << endl;   
	cout << "查询节点+:";
	bt.info('+');
	cout << endl;
	cout << "查询节点b:";
	bt.info('b');
	cout << endl ;
	//--------第3题----------- 
	cout << "节点数 " << bt.countNode() << "、叶子的数目 " 
		<< bt.countLeaves() << "、只有左子树的节点数目 " 
		<< bt.countOnlyLchild() << endl << endl;
	//--------第4题----------- 
	cout << "删除结点+及其子树\t";
	if (bt.Delete('+'))
		cout << "成功删除!\n\n";
	else
		cout << "删除失败，请检查结点是否存在!\n\n";
	//--------第5题-----------      
	bt.PrintTree();
	system("pause");
 	return 0;
}
