#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct node *add_head(struct node *head)
{
	struct node *new_node = NULL;
	int val;

	new_node = (struct node*)calloc(1, sizeof(struct node));
        printf("enter a value to insert:");
        scanf("%d", &val);
	new_node->data = val;
	if (head == NULL)
		return new_node;

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
	if (*head == NULL)
		*head = new_node;
	else {
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void delete_node(struct node **head)
{
	int val;
	struct node *tmp, *node;

	if (head == NULL) {
		printf("List empty\n");
		return;
	}
	printf("enter value to delete:");
	scanf("%d", &val);

	if ((*head)->data == val) {
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		return;
	}
	tmp = *head;
	while (tmp->next != NULL && tmp->next->data != val) {
		tmp = tmp->next;
	};
	if (tmp->next == NULL) {
		printf("node not found with val:%d\n", val);
		return;
	}
	printf("deleting a node\n");
	node = tmp->next;
	tmp->next = tmp->next->next;
	free(node);
}

struct node *delete_first_node(struct node *head)
{
        struct node *tmp;

        if (head == NULL) {
                printf("list empty\n");
                return NULL;
        }
        tmp = head;
        head = tmp->next;
        free(tmp);
        return head;
}

void delete_last_node(struct node **head)
{
        struct node *tmp;

        if (*head == NULL) {
                printf("list empty\n");
                return;
        }
        if ((*head)->next == NULL) {
                free(*head);
                *head = NULL;
		return;
        }
        tmp = *head;
        while (tmp->next->next != NULL)
                tmp = tmp->next;
        free(tmp->next);
        tmp->next = NULL;
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
	while(tmp != NULL) {
		printf("data=%d\n", tmp->data);
		tmp = tmp->next;
	}
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
