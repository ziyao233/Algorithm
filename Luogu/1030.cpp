#include<iostream>
#include<string>
#include<algorithm>

void traverse(std::string inorder,std::string postorder)
{
	if (inorder.size() == 0)
		return;
	char root = postorder[postorder.size() - 1];
	std::cout << root;
	int idx = inorder.find(root);
	traverse(inorder.substr(0,idx),postorder.substr(0,idx));
	traverse(inorder.substr(idx + 1),
		 postorder.substr(idx,postorder.size() - idx - 1));
	return;
}

int main()
{
	std::string inorder,postorder;
	std::cin >> inorder >> postorder;
	traverse(inorder,postorder);
	std::cout << std::endl;
	return 0;
}
