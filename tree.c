#include<stdio.h>
#include<stdlib.h>


struct tree
{
	int data;
	struct tree *l;
	struct tree *r;
}*head=NULL;


struct tree *insert(struct tree *temp,int data)
{
	if(temp==NULL)
	{
		temp=(struct tree *)malloc(sizeof(struct tree));
		temp->data=data;
		temp->l=NULL;
		temp->r=NULL;
		
	}
	else{
	
		if(data>temp->data)
		{
			temp->r=insert(temp->r,data);
		}
		else
			temp->l=insert(temp->l,data);
	}
	return temp;
}

void inorder(struct tree *temp)
{
	if(temp !=NULL)
	{
	inorder(temp->l);
	printf("%d",temp->data);
	inorder(temp->r);
}
}


int height(struct tree *temp)
{
	if(temp==NULL){
		return -1;
	}else{
		int rh=height(temp->r);
		int lh=height(temp->l);
		if(rh>lh)
		return rh+1;
		else
		return lh+1;
	}
}
main()
{
	int i;
	
	head=insert(head,5);
	head=insert(head,3);
	head=insert(head,7);
	inorder(head);
	printf("%d",height(head));
}
