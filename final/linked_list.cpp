#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct headNode
{
	int count;
	Node *headPtr;
};

class LinkedList
{
	public:
			LinkedList();
			~LinkedList();

			void addToHead( int );
			bool removeFromHead();

//			bool addToTail ( int );
//			bool removeFromTail();

			void addNode ( int );
			bool deleteNode ( int );
			void deleteAllNodes();

			bool isEmpty;
			int getNoOfNodes();

			void displayAllNodes();

	private:
		int dataCmp ( int, int );
		void displayNode ( node* );

		HeadNode head;
};

LinkedList::LinkedList()
{
	head.count = 0;
	head.headPtr = NULL;
	return;
}

LinkedList::~LinkedList()
{
	deleteAllNodes();
	return;
}

void LinkedList::addToHead ( int newData )
{
	Node *pNew = new Node;
	pNew -> data = newData;
	pNew -> next = head.headPtr;
	head.headPtr = pNew;
	head.count++;
}

bool LinkedList::removeFromHead()
{
	bool exit;
	Node *temp;

	if ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
		exit = true;		// returns true if it's successful
	}
	else
		exit = false;		// returns false if it's not successful
	return exit;
}

/*
bool LinkedList::addToTail( int )
{

}
bool Linked::removeFromTail();
{

}
*/

void LinkedList::addNode ( int newData )
{
	Node *pNew = new Node,
	     *pPre = NULL,
	     *pCur = head.headPtr;
	pNew -> data = newData;

	while ( pCur && dataCmp( pNew -> data, pCur -> data ) >= 0 )
		{
			pPre = pCur;
			pCur = pCur -> next;
		}

	if ( pPre )
	{
		pNew -> next = pPre -> next;
		pPre -> next = pNew;
		head.count++;
	}
	else
	{
		pNew -> next = head.headPtr;
		head.headPtr = pNew;
		head.count++;
	}
}

bool LinkedList::deleteNode( int data )
{
	bool exit;
	Node *pPre = NULL,
	     *pCur = head.headPtr;

	while ( pCur && dataCmp( pCur -> data, data ) < 0 )
	{
		pPre = pCur;
		pCur = pCur -> next;
	}

	if ( pCur && dataCmp( pCur -> data, data ) == 0 )
	{
		if ( pPre )
		{
			pPre -> next = pCur -> next;
			delete pCur;
			head.count--;
			exit = true; // return true if successful
		}
		else
		{
			head.headPtr = pCur -> next;
			delete pCur;
			head.count--;
			exit = true; // return true if successful
		}
	}
	else
		exit = false; // return false if unsuccessful

	return exit;
}

void LinkedList::deleteAllNodes()

