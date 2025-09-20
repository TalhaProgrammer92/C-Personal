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
                Node* small = node->next, * head = node->prev, * tail = small->next;

                // Update large
                node->next = tail;
                node->prev = small;

                // Update small
                small->next = node;
                small->prev = head;

                // Update head
                if (head != nullptr)
                    head->next = small;

                // Update tail
                if (tail != nullptr)
                    tail->prev = node;
                
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