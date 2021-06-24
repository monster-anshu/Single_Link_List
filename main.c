#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
typedef struct single
{
    int data;
    struct single *link;
} Node;
void Create_List(Node **head)
{
    (*head) = NULL;
}
void Insert_Start(Node **head, int item)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->link = (*head);
    (*head) = temp;
}
void Insert_End(Node **head, int item)
{
    Node *temp, *current;
    temp = (Node *)malloc(sizeof(Node));
    temp->link = NULL;
    temp->data = item;
    if ((*head) == NULL)
        (*head) = temp;
    else
    {
        current = (*head);
        while (current->link != NULL)
            current = current->link;
        current->link = temp;
    }
}

void Search_list(Node **head, int search)
{
    if ((*head) == NULL)
    {
        printf("\n\tEmpty List ! ");
        getch();
    }
    else
    {
        Node *current;
        int count = 0, position = 0;
        current = (*head);
        printf("\n\t\tSearching......");
        while (current != NULL)
        {
            if (current->data == search)
            {
                printf("\n\tElelement %d Found at position %d ", search, position + 1);
                count++;
            }
            current = current->link;
            position++;
        }
        if (count == 0)
        {
            printf("\n\tElelemt %d Not found in the List", search);
        }
        else
        {
            printf("\n\t___________________________________\n\tElelment found %d time(s)", count);
        }
    }
}
void Insert_After(Node **head, int item, int after)
{
    if ((*head) == NULL)
    {
        printf("\n\tEmpty List !\n");
        getch();
    }
    else
    {
        int count = 0;
        Node *current = (*head);
        while (current != NULL)
        {
            if (current->data == after)
            {
                count++;
                break;
            }
            current = current->link;
        }
        if (count == 0)
        {
            printf("\n\tEnters Elelment %d not found ! \n\t", after);
            printf("\n\tAdding Element at end of the List ");
            Insert_End(head, item);
            printf("\n\tOperation Successful ! ");
        }
        else
        {
            Node *temp;
            temp = (Node *)malloc(sizeof(Node));
            temp->data = item;
            temp->link = current->link;
            current->link = temp;
            printf("\n\tOperation Successful ! ");
        }
    }
}
void Delete_Element(Node **head, int element)
{
    if ((*head) == NULL)
        printf("\n\tEmpty List");
    else if ((*head)->data == element)
        (*head) = (*head)->link;
    else
    {
        int i = -1;
        Node *current = (*head);
        while (current->link != NULL)
        {
            if (element == current->link->data)
            {
                i = 1;
                break;
            }
            current = current->link;
        }
        if (i == 1)
            current->link = current->link->link;
        else
            printf("\n\tCan't Find Element !");
    }
}
void Insert_Index(Node **head, int index, int data)
{
    if ((*head) == NULL)
    {
        printf("\n\tList is Empty \n\tAdding Element At beinning of list !");
        Insert_Start(head, data);
    }
    else if (index == 0)
    {
        Insert_Start(head, data);
    }
    else
    {
        Node *current;
        int count = 0, i = 0;
        current = (*head);
        while (current != NULL)
        {
            if (i == index - 1)
            {
                count++;
                break;
            }
            i++;
            current = current->link;
        }
        if (count == 0)
        {
            printf("\n\tCan't Find Index : %d", index);
            printf("\n\tAdding Element at the end of list !");
            Insert_End(head, data);
        }
        else
        {
            Node *temp;
            temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->link = current->link;
            current->link = temp;
        }
    }
    printf("\n\tOperation Successful\n\t");
}

void Delete_Index(Node **head, int index)
{
    if ((*head) == NULL)
        printf("\n\tEmpty List");
    else if (index == 0)
    {
        (*head) = (*head)->link;
    }
    else
    {
        Node *current;
        current = (*head);
        int i = 0;
        while (i != index - 1)
        {
            current = current->link;
            if (current == NULL)
            {
                i = -1;
                break;
            }
            i++;
        }
        if (i == -1)
            printf("\n\tCan't find %d Index", index);
        else
            current->link = current->link->link;
    }
}

void Delete_beg(Node **head)
{
    if (*head == NULL)
        printf("\n\tEmpty List");
    else
        *head = (*head)->link;
}

void Delete_end(Node **head)
{
    if (*head == NULL)
        printf("\n\tEmpty List");
    else
    {
        Node *current = *head;
        while (current->link->link != NULL)
            current = current->link;
        current->link = NULL;
    }
}

void Menu()
{
    printf("\n\t\t     *******Linked List*******\n");
    printf("\t=====================================================");
    printf("\n\tPress 1 for Inster Element At Beginning of Linked list \n");
    printf("\n\tPress 2 for Inster Element At Endding of Linked list \n");
    printf("\n\tPress 3 for Inster Element At Index of Linked list \n");
    printf("\n\tPress 4 for Inster Element At After a Element \n");
    printf("\n\tPress 5 for Search a Elelment in the List \n");
    printf("\n\tPress 6 for Display Linked List \n");
    printf("\n\tPress 7 for Delete in Index  \n");
    printf("\n\tPress 8 for Delete in Beginning  \n");
    printf("\n\tPress 9 for Delete in Ending  \n");
    printf("\n\tPress 10 for Delete A Element  \n");
    printf("\n\tPress 0 for Exit  \n");
    printf("\n\t====================================================\n");
    printf("\tEnter Choise : ");
}
void Display_List(Node **head)
{
    Node *temp;
    if ((*head) == NULL)
    {
        printf("\n\tEmpty List ! ");
    }
    else
    {
        printf("\t Index \t|\t Element");
        temp = (*head);
        int i = 0, data;
        while (temp != NULL)
        {
            data = temp->data;
            printf("\n\t-------------------------------");
            printf("\n\t %d \t|\t %d", i++, data);
            temp = temp->link;
        }
    }
}

int main()
{
    int choise, item, after;
    Node *head;
    head = NULL;
    while (1)
    {
        system("cls");
        Menu();
        scanf("%d", &choise);
        switch (choise)
        {
        case 0:
            exit(1);
            break;
        case 1:
            system("cls");
            printf("\n\tEnter item to inster at beginning : ");
            scanf("%d", &item);
            Insert_Start(&head, item);
            break;
        case 2:
            system("cls");
            printf("\n\tEnter item to inster at endding : ");
            scanf("%d", &item);
            Insert_End(&head, item);
            break;
        case 3:
            system("cls");
            printf("\n\t======================\n\t\tInsert at index\n\t======================");
            printf("\n\tEnter Index : ");
            scanf("%d", &after);
            printf("\n\tEnter Elment to insert : ");
            scanf("%d", &item);
            Insert_Index(&head, after, item);
            break;
        case 4:
            system("cls");
            printf("\n\tAfter which element You want to insert Elment : ");
            scanf("%d", &after);
            printf("\n\tEnter Element to insert : ");
            scanf("%d", &item);
            Insert_After(&head, item, after);
            break;
        case 5:
            system("cls");
            printf("\t=====================\n\t\tSearch a Elelment\n\t=====================");
            printf("\n\tEnter a Element to search : ");
            scanf("%d", &item);
            Search_list(&head, item);
            break;
        case 6:
            system("cls");
            printf("\n\tList : \n\n");
            Display_List(&head);
            break;
        case 7:
            system("cls");
            printf("\n\tEnter Index to delete element from ");
            scanf("%d", &after);
            Delete_Index(&head, after);
            break;
        case 8:
            Delete_beg(&head);
            break;
        case 9:
            Delete_end(&head);
            break;
        case 10:
            printf("\n\tEnter Element to Delete : ");
            scanf("%d", &after);
            Delete_Element(&head, after);
            break;
        default:
            printf("\tEnter valid choise ! ");
        }
        if (choise == 1 || choise == 2)
            ;
        else
        {
            printf("\n\tPress Any key To continue .....");
            getch();
        }
    }
}
