#ifndef H_doublyLinkedList
#define H_doublyLinkedList 

#include <iostream>
#include <cassert>

using namespace std;

///////////////////////////////////////////////////////////////////////
//
// Struct: nodeType                                          
//                                                                   
// Description:
//    represents a single node including it's info, pointer to the next
//    node, and pointer to the previous node        
//
//    info
//    next
//    back                                   
// 
///////////////////////////////////////////////////////////////////////
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* next;
    nodeType<Type>* back;
};

///////////////////////////////////////////////////////////////////////
//
// Class: doublyLinkedList                                          
//                                                                   
// Description:
//    represents a single doublyLinkedList including the number of nodes
//    in the list, a pointer to the first node, and a pointer to the 
//    last node.        
//
//    first
//    last
//    count
// 
//    doublyLinkedList
//    doublyLinkedList (copy constructor)
//    ~doublyLInkedList
//    initializeList
//    isEmptyList
//    destroy
//    print
//    reversePrint
//    length
//    front
//    back
//    search
//    insert
//    deleteNode
//    copyList
//    operator=                                    
// 
///////////////////////////////////////////////////////////////////////
template <class Type>
class doublyLinkedList
{
private:
    void copyList(const doublyLinkedList<Type>& otherList);

protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;

public:
    doublyLinkedList();
    doublyLinkedList(const doublyLinkedList<Type>& otherList);
    ~doublyLinkedList();
    void initializeList();
    bool isEmptyList() const;
    void destroy();
    void print() const;
    void reversePrint() const;
    int length() const;
    Type front() const;
    Type back() const;
    bool search(const Type& searchItem) const;
    void insert(const Type& insertItem);
    void deleteNode(const Type& deleteItem);

    const doublyLinkedList<Type>& operator=
        (const doublyLinkedList<Type>&);
};

///////////////////////////////////////////////////////////////////////
//
// Function: doublyLinkedList                                        
//                                                                   
// Description:
//    creates a doublyLinkedList object and initializes all variables
//
// Parameters:  
//    first : pointer to the first node in the list
//    last : pointer to the last node in the list
//    count : number of nodes in the list             
//                                                       
// Returns:  
//    none               
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function: ~doublyLinkedList                                        
//                                                                   
// Description:
//    destorys a doubleLinkedList object and deallocates the memory for
//    all of its nodes
//
// Parameters:  
//    first : pointer to the first node in the list
//    last : pointer to the last node in the list
//    count : number of nodes in the list             
//                                                       
// Returns:  
//    none               
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
doublyLinkedList<Type>::~doublyLinkedList()
{
    destroy();
}


///////////////////////////////////////////////////////////////////////
//
// Function: isEmptyList                                        
//                                                                   
// Description:
//    checks if a doublyLinkedList object is empty and returns result
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    true : returns if the pointer to the first node is NULL
//    false : returns if the pointer to the first node is not NULL              
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
    return (first == nullptr);
}

///////////////////////////////////////////////////////////////////////
//
// Function: destroy                                        
//                                                                   
// Description:
//    destorys a doubleLinkedList object and deallocates the memory for
//    all of its nodes
//
// Parameters:  
//    none            
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
void doublyLinkedList<Type>::destroy()
{
    nodeType<Type>* temp; 

    while (first != nullptr)
    {
        temp = first;
        first = first->next;
        delete temp;
    }

    last = nullptr;
    count = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function: initializeList                                        
//                                                                   
// Description:
//    reinitializes a doublyLinkedList object to an empty state
//
// Parameters:  
//    none            
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
void doublyLinkedList<Type>::initializeList()
{
    destroy();
}

///////////////////////////////////////////////////////////////////////
//
// Function: length                                        
//                                                                   
// Description:
//    returns the number of nodes currently in a doublyLinkedList 
//    object
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    count : the number of nodes currently in the list           
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
int doublyLinkedList<Type>::length() const
{
    return count;
}

///////////////////////////////////////////////////////////////////////
//
// Function: print                                        
//                                                                   
// Description:
//    prints the info contained in each node of a doublyLinkedList 
//    object, from first to last.
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    none        
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
void doublyLinkedList<Type>::print() const
{
    nodeType<Type>* current; 

    current = first;  

    while (current != nullptr)
    {
        cout << current->info << "  ";  
        current = current->next;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function: reversePrint                                        
//                                                                   
// Description:
//    prints the info contained in each node of a doublyLinkedList 
//    object, from last to first.
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    none        
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
    nodeType<Type>* current; 

    current = last;  

    while (current != nullptr)
    {
        cout << current->info << "  ";
        current = current->back;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function: search                                        
//                                                                   
// Description:
//    searches for a node in a doubleLinkedList object that contains 
//    info matching a search item, and returns the result
//
// Parameters:  
//    searchItem : the value to be searched for in the info of the nodes            
//                                                       
// Returns:  
//    found : returns true if item was found and false if not found.              
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
bool doublyLinkedList<Type>::
search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type>* current; 

    current = first;

    while (current != nullptr && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->next;

    if (found)
        found = (current->info == searchItem); 

    return found;
}

///////////////////////////////////////////////////////////////////////
//
// Function: front                                        
//                                                                   
// Description:
//    returns the info contained in the first node of a doublyLinkedList
//    object
//    if the list is empty the program terminates
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    first->info : the info contained in the first node of the list         
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
Type doublyLinkedList<Type>::front() const
{
    assert(first != nullptr);

    return first->info;
}

///////////////////////////////////////////////////////////////////////
//
// Function: back                                        
//                                                                   
// Description:
//    returns the info contained in the last node of a doublyLinkedList
//    object
//    if the list is empty the program terminates
//
// Parameters:  
//    none             
//                                                       
// Returns:  
//    last->info : the info contained in the last node of the list         
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
Type doublyLinkedList<Type>::back() const
{
    assert(last != nullptr);

    return last->info;
}

///////////////////////////////////////////////////////////////////////
//
// Function: insert                                        
//                                                                   
// Description:
//    inserts an item into a new node at the appropriate location in
//    a doubleLinkedList object
//
// Parameters:  
//    insertItem : the value of the info to be stored in the new node            
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
void doublyLinkedList<Type>::insert(const Type& insertItem)
{
    nodeType<Type>* current;      
    nodeType<Type>* trailCurrent; 
    nodeType<Type>* newNode;      
    bool found;

    newNode = new nodeType<Type>; 
    newNode->info = insertItem;  
    newNode->next = nullptr;
    newNode->back = nullptr;

    if (first == nullptr) 
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else
    {
        found = false;
        current = first;

        while (current != nullptr && !found) 
            if (current->info >= insertItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->next;
            }

        if (current == first) 
        {
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        }
        else
        {
            if (current != nullptr)
            {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                newNode->next = current;
                current->back = newNode;
            }
            else
            {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }

            count++;
        }
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function: deleteNode                                        
//                                                                   
// Description:
//    searches for a node in a doubleLinkedList object that contains 
//    info matching a search item, and if found deletes the node from
//    the list
//
// Parameters:  
//    deleteItem : the value of the info in the node to be deleted            
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent;
    bool found;

    if (first == nullptr)
        cout << "Cannot delete from an empty list." << endl;
    else if (first->info == deleteItem)
    {
        current = first;
        first = first->next;

        if (first != nullptr)
            first->back = nullptr;
        else
            last = nullptr;

        count--;

        delete current;
    }
    else
    {
        found = false;
        current = first;

        while (current != nullptr && !found)
            if (current->info >= deleteItem)
                found = true;
            else
                current = current->next;

        if (current == nullptr)
            cout << "The item to be deleted is not in "
            << "the list." << endl;
        else if (current->info == deleteItem)
        {
            trailCurrent = current->back;
            trailCurrent->next = current->next;

            if (current->next != nullptr)
                current->next->back = trailCurrent;

            if (current == last)
                last = trailCurrent;

            count--;
            delete current;
        }
        else
            cout << "The item to be deleted is not in list."
            << endl;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function: copyList                                        
//                                                                   
// Description:
//    copies all the nodes of a doublyLinkedList object into another 
//    doublyLinkedList object
//
// Parameters:  
//    otherList : the doublyLinkedList object to be copied          
//                                                       
// Returns:  
//    none              
//                                            
///////////////////////////////////////////////////////////////////////
template<class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList<Type>& otherList)
{
    //ENTER CODE HERE (20%)
}

///////////////////////////////////////////////////////////////////////
//
// Function: doublyLinkedList                                        
//                                                                   
// Description:
//    copy constructor for the doublyLinkedList class that copies all 
//    of the nodes from an existing doublyLinkedList object to a new 
//    one
//
// Parameters:  
//    otherList : the doublyLinkedList object to be copied            
//                                                       
// Returns:  
//                  
//                                            
///////////////////////////////////////////////////////////////////////
template<class Type>
doublyLinkedList<Type>::doublyLinkedList(const doublyLinkedList<Type>& otherList)
{
    //ENTER CODE HERE (20%)
}

///////////////////////////////////////////////////////////////////////
//
// Function: operator=                                      
//                                                                   
// Description:
//    Overloads the assignment operator for the doublyLinkedList class. 
//    Copies all of the nodes from an existing doublyLinkedList object 
//    to a new one
//
// Parameters:            
//    otherList : doublyLinkedList object being copied              
//                                                       
// Returns:  
//                 
//                                            
///////////////////////////////////////////////////////////////////////
template<class Type>
const doublyLinkedList<Type>& doublyLinkedList<Type>::operator=
(const doublyLinkedList<Type>& otherList)
{
    //ENTER CODE HERE (20%)
}

#endif