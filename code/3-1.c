#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	char name[20];
	int score;
};

int main() {
	char command[10];
	struct Node *head = NULL;
	int size = 0;

	scanf("%s", command);

	while(strcmp(command, "quit")) {
		if(!strcmp(command, "print")) {
			for(int i = 0; i < size; i++) {
				printf("%s %d\n", head[i].name, head[i].score);
			}
		} else if(!strcmp(command, "add")) {
			if(!size) {
				size++;
				head = malloc(size * sizeof(struct Node));
				scanf("%s", head[0].name); 
				scanf("%d", &head[0].score); 
			} else {
				size++;
				head = realloc(head, size * sizeof(struct Node));
				scanf("%s", head[size-1].name);
				scanf("%d", &head[size-1].score);
			}


		} else if(!strcmp(command, "delete")) {
			char c[20];
			scanf("%s", c);
			size--;
			struct Node *temp = malloc(size * sizeof(struct Node));
			
			for(int i = 0, j = 0; i < size + 1; i++) {
				if(!strcmp(head[i].name, c)) continue;
				strcpy(temp[j].name, head[i].name); 
				temp[j].score = head[i].score;
				j++;
			}
			free(head);
			head = temp;
		}
		
		scanf("%s", command);
	}


	free(head);
	head = NULL;

}
