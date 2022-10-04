//Jordan Rood
//Homework 2 - Linked Stack

template<class ItemType>
linkedStack<ItemType>::linkedStack(){
    topStackPtr = nullptr;
}
template<class ItemType>
linkedStack<ItemType>::linkedStack(const linkedStack<ItemType>& oldStack){
    int count = 0;

    Node<ItemType>* oldNodePtr = oldStack.topStackPtr;
    Node<ItemType>* endPtr;

    while(oldNodePtr != nullptr){
        push(oldNodePtr->getItem());
        if(count == 0){
            endPtr = topStackPtr;
        }
        oldNodePtr = oldNodePtr->getNext();
        count++;
    }

    while(topStackPtr != endPtr){
        Node<ItemType>* next = topStackPtr->getNext();
        topStackPtr->setNext(endPtr->getNext());
        endPtr->setNext(topStackPtr);
        topStackPtr = next;
    }
}

template<class ItemType>
bool linkedStack<ItemType>::isEmpty() const{
    return topStackPtr == nullptr;
}

template<class ItemType>
bool linkedStack<ItemType>::push(const ItemType& newEntry){

    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topStackPtr);
    topStackPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<class ItemType>
bool linkedStack<ItemType>::pop(){

    bool canPop = false;
    if(!isEmpty()){
        Node<ItemType>* nodeToDelete = topStackPtr; //create node to delete
        topStackPtr = topStackPtr->getNext(); //get node to delete's next ptr to assign as top
        nodeToDelete->setNext(nullptr); //set node to deletes next to null
        delete nodeToDelete; //delete node to delete

        canPop = true;
    }
    return canPop;
}

template<class ItemType>
ItemType linkedStack<ItemType>::peek() const{

    if(!isEmpty()){
        return topStackPtr->getItem();
    }
    else{
        throw "Stack is empty!";
    }
}

template<class ItemType>
linkedStack<ItemType>::~linkedStack(){
    while(!isEmpty()){
        pop();
    }
}