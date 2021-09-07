#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void print_list(struct node* head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

struct node* create_node(int data){
	struct node* newnode = malloc(sizeof(struct node));
	newnode->data = data;
	return newnode;
}

struct node* find_node(struct node* head, int index){
	struct node* temp = head;
	for(int i = 0; i < index; i++){
		if(temp == NULL){
			return NULL;
		}
		temp = temp->next;
	}
	return temp;
}

void insert_node(struct node* head, struct node* newnode, struct node* existing){
	struct node* temp;
	if(head != NULL){
		temp = existing->next;
		existing->next = newnode;
		newnode->next = temp;
	}
	else{
		head = newnode;
	}
}

void delete_node(struct node* head, struct node* deletenode){
	struct node* temp = head;
	if(deletenode != head) {
		while(temp->next != deletenode){
			temp = temp->next;
		}
		temp->next = deletenode->next;
	}
	free(deletenode);
}

int main() {
	struct node* head = create_node(1);
	struct node* node1 = create_node(35);
	struct node* node2 = create_node(55);
	insert_node(NULL, head, NULL);
	print_list(head);
	insert_node(head, node2, head);
	print_list(head);
	insert_node(head, node1, head);
	print_list(head);
	delete_node(head, node2);
	print_list(head);
}
  
