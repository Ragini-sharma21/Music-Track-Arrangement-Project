#include <stdio.h>  //C CODE 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node{
char data[100];        // self referencing structure
struct Node*next;
};

// code to add song in the playlist

void AddToPlaylist(struct Node **head, char temp[])
{
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    strcpy(current->data, temp);
    current->next = NULL;

    if (*head == NULL)
    {
        *head = current;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = current;
}



 // Code to delete a song from the playlist

void DeleteFromPlayList(struct Node **head, char temp[])
{
    struct Node *current = *head, *prev;
    if (current != NULL && strcmp(current->data,temp)==0)
        {
        *head = current->next; // Changed head
        free(current); // free old head
        return;

    }
    while (current != NULL && strcmp(current->data, temp) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL){
        printf("This song is not in our playlist\n");
        return;

    }
    prev->next = current->next;
    free(current);
}


// code to display the full Playlist

void DisplayPlaylist(struct Node*head)
{
if(head==NULL)
    {
 printf("Nothing is in the Playlist\n");
 return;
}


  while(head!=NULL)
  {

    puts(head->data);
    head=head->next;
  }
}

//code for sorting playlist

void sortPlayList(struct Node**head)
{
char temp[100];
struct Node* chnge = *head;

struct Node*current=NULL;
while(chnge->next!=NULL)
{
    current=chnge->next;
    while(current!=NULL)
    {
        if(strcmp(chnge->data,current->data)>0)
           {
           strcpy(temp,chnge->data);

           strcpy(chnge->data,current->data);

           strcpy(current->data,temp);
    }
    current=current->next;
}
chnge=chnge->next;
}
}

int main()
{
    bool quit = false;
    int choice;
    struct Node *head = NULL;
    char exit[] = "quit";
    char temp[100];
    char temp2[100];

    while (!quit)
    {
        printf("1. Add Song to Your Playlist \n");
        printf("2. Delete Song from Playlist \n"); //choose one option among them
        printf("3. Display Your Playlist \n");
        printf("4. Sort Your Playlist \n");
        printf("5. quit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the name of the song: \n");
            scanf("%s", temp);
            while(strcmp(temp, exit) != 0){
                AddToPlaylist(&head, temp);
                printf("Enter the name of the song: \n");
                scanf("%s", temp);
            }
            break;

        case 2:
            printf("Enter the name of the song to be deleted : \n");
            scanf("%s", temp2);
            while(strcmp(temp2, exit) != 0){
                DeleteFromPlayList(&head, temp2);;
                printf("Enter the name of the song to be deleted: \n");
                scanf("%s", temp2);
            }
            break;

        case 3:

            DisplayPlaylist(head);
            break;
        case 4:

            sortPlayList(&head);
            break;
        case 5:

            quit = true;
            break;

        default:
            printf("This is not a valid input \n");
            quit = true;
        }
    }
}

