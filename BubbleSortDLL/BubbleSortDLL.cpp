#include <iostream>
#include "../BubbleSortDLL/linked_list.h"

using namespace std;

void sort(List& list)
{
    const int size = list.size();
    
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            Node* node = list.head;

            if (node->data > node->next->data)
            {
                /*Node* temp = node->next;

                node->next = temp->next;
                temp->next = node;

                node->previous = temp;
                temp->previous = node->previous;*/
                
                swapped = true;
            }

            if (!swapped) return;

            node = node->next;
        }
    }
}

int main()
{
    List list;

    list.push_front(5);
    list.push_front(2);
    list.push_front(1);
    list.push_front(3);
    list.push_front(4);

    list.display();
    sort(list);
    list.display();
}