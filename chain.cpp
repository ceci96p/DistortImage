#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){ /*your code here*/
clear();
}

/**
 * Inserts a new node in position one of the Chain,
 * after the sentinel node.
 * This function **SHOULD** create a new Node.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertFront(const Block & ndata){
  Node* curr = head_; 
  Node* pos_2 = head_->next;
  Node* temp = NULL;

  temp = new Node(ndata);

  temp->next = pos_2;
  pos_2->prev = temp;
  curr->next = temp;
  temp->prev = curr;
  length_++;
  return;
  std::cout << "a" << std::endl;
}

/**
 * Inserts a new node at the back of the Chain,
 * but before the tail sentinel node.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
  Node* curr = tail_;
  Node* prev_tail = tail_->prev;
  Node* temp = NULL;

  temp = new Node(ndata);

  temp->next = curr;
  curr->prev = temp;
  prev_tail->next = temp;
  temp->prev = prev_tail;
  length_++; 
  return;
  std::cout << "b" << std::endl;
}

/**
 * Modifies the Chain by moving a contiguous subset of Nodes to
 * the end of the chain. The subset of len nodes from (and
 * including) startPos are moved so that they
 * occupy the last len positions of the
 * chain (maintaining the sentinel at the end). Their order is
 * not changed in the move.
 */
void Chain::moveToBack(int startPos, int len){
   Node* curr = head_;
   Node* tail = tail_;
   Node* prev_tail = tail_->prev;
   Node* a = walk(curr,startPos);
   Node* b = walk(a,  len - 1); 
   Node* prev_a = a->prev;
   Node* next_b = b->next;
  
  
   

  if ((2 <= startPos <= length_) && (1 <=  len <= length_) && (a != NULL) && (a != NULL)) { //if a and b are at acceptable places*********
  	//(walk(curr,startPos) != NULL) && (walk(a, + len - 1) != NULL)

  	if (len == 1){
   		a->prev = prev_tail;
  	 	prev_tail->next = a;
   		a->next = tail;
   		tail->prev = a;
   		prev_a->next = next_b;
   		next_b->prev = prev_a;
   		}

  	else{
   		a->prev = prev_tail;
   		prev_tail->next = a;
   		b->next = tail;
   		tail->prev = b;
   		prev_a->next = next_b;
   		next_b->prev = prev_a;
	}
	
   }

	return;
	std::cout << "c" << std::endl;
}


/**
 * Rotates the current Chain by k nodes: removes the first
 * k nodes from the Chain and attaches them, in order, at
 * the end of the chain (maintaining the sentinel at the end).
 */
void Chain::rotate(int k){
	Node* curr = head_;
	Node* tail = tail_;
	Node* a = curr->next;
	Node* b = walk(curr,k ); // CHECK THIS +1?
	Node* next_b = b ->next;
	Node* prev_tail = tail_->prev;

	if (1 < k <= length_){
		if (a == b){
			curr->next = next_b;
			next_b->prev = curr;
			a->prev = prev_tail;
			prev_tail->next = a;
			a->next = tail;
			tail->prev = a;

			return;

		}
		else{
			curr->next = next_b;
			next_b->prev = curr;
			a->prev = prev_tail;
			prev_tail->next = a;
			b->next = tail;
			tail->prev = b;
			
		}
		
	}
	return;
	std::cout << "d" << std::endl;

}

/**
 * Modifies the current chain by swapping the Node at pos1
 * with the Node at pos2. the positions are 1-based.
 */
void Chain::swap(int pos1, int pos2){
   Node* curr = head_;
   Node* a = walk(curr,pos1);
   Node* b = walk(curr,pos2);
   Node* prev_a = a->prev;
   Node* next_a = a->next;
   Node* prev_b = b->prev;
   Node* next_b = b->next;

   //big if statement validating  pos1 and pos2 to 1<pos1<length_+1 and 1<pos2<length_+1
   

   if (pos1 == pos2){                          // if a and b are the same do nothing
	   return;
	}

   if (a == NULL || b == NULL){          // if a or b are null do nothing
   	   return;
   }

   if (pos1 + 1 == pos2 || pos2 + 1 == pos1 ){   // if a or b are adjacent then:::
	   if (pos1 < pos2){                      // if a is less than b
			a->next = next_b;
			next_b->prev = a;  
			a->prev = b;
			b->next = a;
			b->prev=prev_a;
			prev_a->next = b;

			return;	
		}

		else if(pos2 < pos1){                //if b is less than a
			b->next = next_a;
			next_a->prev = b;
			b->prev = a;
			a->next = b;
			a->prev = prev_b;
			prev_b->next = a;

			return;
		}
	}

   if (pos1 < pos2){                        //
   	   a->next = next_b; //change a to b
   	   next_b->prev = a;
   	   a->prev = prev_b;
   	   prev_b->next = a;
   	   b->next = next_a; //change b to a
       next_a->prev = b;
       b->prev = prev_a;
       prev_a->next = b;

    return;
   }


    else if (pos2 < pos1){
       b->next = next_a; //change b to a
   	   next_a->prev = b;
   	   b->prev = prev_a;
   	   prev_a->next = b;
   	   a->next = next_b; //change a to b
       next_b->prev = a;
       a->prev = prev_b;
       prev_b->next = a;

     return;
    }
   }


/*
 *  Modifies both the current and input chains by trading
 * nodes in even positions between the chains. Length
 * of each chain should stay the same. If the h
 * are NOT the same, the funtion has no effect and a simple
 * error message is output: cout << "Block sizes differ." << endl;
 */

void Chain::twist(Chain & other){
  Node* prev1 = head_->next;
  Node* curr1 = prev1->next;

  Node* prev2 = other.head_->next;
  Node* curr2 = prev2->next;
 
if ( (height_ != other.height_) || width_ != other.width_){ 
 std::cout << "Block sizes differ." << std::endl;
    return;
}

while ((prev1 != tail_) || (prev2 != other.tail_)){

  prev1->next = curr2;
  curr2->prev =prev1;

  prev2->next = curr1;
  curr1->prev = prev2;

  prev1 = curr1;
  prev2 = curr2;
  curr1 = curr1->next;
  curr2 = curr2->next;

}

return;

}





/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() { 
   Node* temp = NULL;
   Node* curr = head_;

   while(curr != NULL){
   		temp = curr;
   		curr = curr->next;
   		delete temp;
   }
   return;

}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {

  length_ = other.length_;
	width_ = other.width_;
	height_ = other.height_;

	Node* curr = other.head_;
	Node* n = NULL;

	head_ = new Node(Block (curr->data));
	head_->prev = NULL;
	Node* prev = head_;

	curr = curr->next;
	
	while (curr != NULL){
			n = new Node (Block (curr->data)); 
			prev->next = n;
			n->prev = prev;

			prev = n;
			curr = curr->next;
		}	

	if (curr == NULL){
		tail_ = prev;
		prev->next = NULL;
	}

return;
}
//
	



	

	



