#include <iostream>
#include <string>
#include "BST.h"
#include <fstream>

using namespace std;

BST::BST(){
	root = NULL;
}

void BST::insert(string *s, int times){
	tree_node *temp = new tree_node;
	temp->word = s;
	temp->times = times;
	temp->left = NULL;
	temp->right = NULL;
	temp->dic_left = NULL;
	temp->dic_right = NULL;
	root = InsertRecursion(root, temp);
}

tree_node* BST::InsertRecursion(tree_node *node, tree_node *new_node){
	if(node == NULL){
			return new_node;
	}
	if(times_string_compare(new_node, node)){
		node->right = InsertRecursion(node->right, new_node);
	}
	else{
		node->left = InsertRecursion(node->left, new_node);
	}
	return node;
}


bool BST::times_string_compare(tree_node *n1, tree_node *n2){ // 擺前面 return true
	if(n1->times > n2->times){ // time大者擺前面
		return true;
	}
	else if(n1->times < n2->times){
		return false;
	}
	else{
		return string_compare(n1,n2); // time相同者比較Word的次序
	}
}

bool BST::string_compare(tree_node *n1, tree_node *n2){ // 擺前面 return true
	int i = 1;
	int min;
	string *s1 = n1->word;
	string *s2 = n2->word;
	if(s1->size() <= s2->size()){
		min = s1->size();
	}
	else{
		min = s2->size();
	}
	if(s1[0] < s2[0]){ // a < b
		return true;
	}
	else if(s1[0] > s2[0]){ // b > a
		return false;
	}
	else{
		while(i < min){
			if(s1[i] < s2[i]){ // a < b
				return true;
			}
			else if(s1[0] > s2[0]){ // b > a
				return false;
			}
			else{
				i++;
			}
		}
		if(s1->size() == min){
			return true;
		}
		else{
			return false;
		}
	}
}



void BST::printBST(tree_node *node, ofstream &fp){
	//印在output.txt
	if(node==NULL)
	{
		return;
	}
    printBST(node->right, fp);
    fp << *(node->word) << " " << node->times << endl;
    printBST(node->left, fp);
}

void BST::printBST(){
	ofstream fp;
	fp.open("output.txt");
	this->printBST(root, fp);
	fp.close();
}

void BST::printBST_terminal(tree_node *node){
	//印在terminal
	if(node==NULL)
	{
		return;
	}
    printBST_terminal(node->right);
    cout << *(node->word) << " " << node->times << endl;
    printBST_terminal(node->left);
}

void BST::printBST_terminal(){
	this->printBST_terminal(root);
}