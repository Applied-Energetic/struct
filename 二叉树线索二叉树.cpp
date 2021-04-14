

void Inorder (BTptr BT){
	if (BT == NULL){
		return ;
	}
	Inorder(BT->Lchild);
	visit (BT);
	Inorder(BT->Rchild);
} 
