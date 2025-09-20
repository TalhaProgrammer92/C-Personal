#pragma once

#include <iostream>

class Node
{
public:
	// Attributes
	int data;
	Node* next, * prev;

	// Constructors
	Node(const int &data, Node *next = nullptr, Node *previous = nullptr)
		: data(data), next(next), prev(previous) { }
	Node(const Node &other)
		: data(other.data), next(other.next), prev(other.prev) { }
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
			head->prev = node;
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
			node->prev = tail;
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
			tail = tail->prev;
			tail->next = node->prev = nullptr;
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
			head->prev = node->next = nullptr;
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

