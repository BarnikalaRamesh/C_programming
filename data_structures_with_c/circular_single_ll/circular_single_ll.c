#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct node *add_head(struct node *head)
{
	struct node *new_node = NULL, *tmp;
	int val;

	new_node = (struct node*)calloc(1, sizeof(struct node));
        printf("enter a value to insert:");
        scanf("%d", &val);
	new_node->data = val;
	new_node->next = head;
	if (head == NULL) {
		new_node->next = new_node;
		return new_node;
	}
	tmp = head;
	while (tmp != head)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->next = head;
	return new_node;
}

void add_tail(struct node **head)
{
	struct node *tmp;
	struct node *new_node;
	int val;

	printf("enter a value to insert:");
	scanf("%d", &val);
	new_node = (struct node*)calloc(1, sizeof(struct node));
	new_node->data = val;
	new_node->next = *head;
	if (*head == NULL) {
		new_node->next = new_node;
		*head = new_node;
	} else {
		tmp = *head;
		while (tmp->next != *head)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

struct node *delete_first_node(struct node *head)
{
        struct node *tmp;

        if (head == NULL) {
                printf("list empty\n");
                return NULL;
        }
	tmp = head;
	if (tmp->next == head) {
		free(tmp);
		return NULL;
	}
	/* go to the last node */
	while (tmp->next != head)
		tmp = tmp->next;

	tmp->next = head->next;
	free(head);
	head = tmp->next;
	return head;
}

void delete_last_node(struct node **head)
{
        struct node *tmp;
	struct node *prev = NULL;

        if (*head == NULL) {
                printf("list empty\n");
                return;
        }
        tmp = *head;
        while (tmp->next != *head) {
		prev = tmp;
                tmp = tmp->next;
	}
        free(tmp);
	if (prev)
		prev->next = *head;
	else
		*head = NULL;
}

void delete_node(struct node **head)
{
	int val;
	struct node *tmp, *node;

	if (*head == NULL) {
		printf("List empty\n");
		return;
	}
	printf("enter value to delete:");
	scanf("%d", &val);

	if ((*head)->data == val) {
		*head = delete_first_node(*head);
		return;
	}
	tmp = *head;
	while (tmp->next != *head && tmp->next->data != val) {
		tmp = tmp->next;
	};
	if (tmp->next == *head) {
		printf("node not found with val:%d\n", val);
		return;
	}
	printf("deleting a node\n");
	node = tmp->next;
	tmp->next = tmp->next->next;
	free(node);
}

void display_list(struct node *head)
{
	struct node *tmp;

	if (head == NULL) {
		printf("List empty\n");
		return;
	}
	tmp = head;
	printf("printing the list\n");
	do {
		printf("data=%d\n", tmp->data);
		tmp = tmp->next;
	} while (tmp != head);
}

int main()
{
        struct node *head = NULL, *tmp = NULL, *new_node = NULL;
        char ch;
        int val;

        while (1) {
		printf("\n");
		printf("--------- Enter your option ---------\n");
                printf("i - insert a node at begining\n");
                printf("e - insert a node at the end\n");
                printf("d - delete of a node by data\n");
                printf("f - delete first node\n");
                printf("l - delete last node\n");
                printf("p - print the nodes in list\n");
		printf("q - to quit the application\n");
                printf("Enter your option:");
                scanf("%c", &ch);

                switch (ch) {
                        case 'i':
			head = add_head(head);
                        break;

                        case 'e':
			add_tail(&head);
                        break;

                        case 'd':
			delete_node(&head);
                        break;

                        case 'f':
                        head = delete_first_node(head);
                        break;

                        case 'l':
                        delete_last_node(&head);
                        break;

                        case 'p':
			display_list(head);
                        break;

                        case 'q':
                        printf("Application quiting\n");
                        return 0;
                        default:
                        printf("invalid option\n");
                }
                while(getchar() != '\n');

        }
        return 0;
}
