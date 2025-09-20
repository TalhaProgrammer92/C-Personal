#pragma once

#include <iostream>

class Node
{
public:
	// Attributes
	int data;
	Node* next, * previous;

	// Constructors
	Node(const int &data, Node *next = nullptr, Node *previous = nullptr)
		: data(data), next(next), previous(previous) { }
	Node(const Node &other)
		: data(other.data), next(other.next), previous(other.previous) { }
};

class List
{
public:
	// Attributes
	Node* head, * tail;

	// Constructor
	List(Node *head = nullptr, Node *tail = nullptr)
		: head(head), tail(tail) { }

	// Method - Push Front
	void push_front(const int &data)
	{
		Node* node = new Node(data);

		// If both head and tail do not exist
		if (head == tail && head == nullptr)
			head = tail = node;
		else
		{
			head->previous = node;
			node->next = head;
			head = node;
		}
	}
	void push_back(const int& data)
	{
		Node* node = new Node(data);

		// If both head and tail do not exist
		if (head == tail && head == nullptr)
			head = tail = node;
		else
		{
			tail->next = node;
			node->previous = tail;
			tail = node;
		}
	}

	// Methods - Pop
	void pop_front()
	{
		Node* node = nullptr;

		if (head == tail)
		{
			node = head;
			head = tail = nullptr;
		}
		else
		{
			node = tail;
			tail = tail->previous;
			tail->next = node->previous = nullptr;
		}

		if (node != nullptr)
			delete node;
	}
	void pop_back()
	{
		Node* node = nullptr;

		if (head == tail)
		{
			node = head;
			head = tail = nullptr;
		}
		else
		{
			node = head;
			head = head->next;
			head->previous = node->next = nullptr;
		}

		if (node != nullptr)
			delete node;
	}

	// Method - Get size
	int size() const
	{
		int size = 0;
		Node* node = head;

		while (node != nullptr)
		{
			size++;
			node = node->next;
		}

		return size;
	}

	// Method - Display
	void display()
	{
		Node* node = head;

		while (node != nullptr)
		{
			std::cout << node->data << "<->";

			node = node->next;
		}
		std::cout << "NULL" << std::endl;
	}
};

