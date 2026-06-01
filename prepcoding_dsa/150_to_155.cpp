#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int val){
      this->data = val;
      this->next = nullptr;
  }
};

class LinkedList{
  Node* head = nullptr;
  int size = 0;

  public:
  int len(){
      return size;
  }
  
  void add(int val){
      Node* temp = new Node(val);
      Node* curr = head;
      
      if(head == nullptr){
          head = temp;
      }else{
          while(curr->next != nullptr){
              curr = curr->next;
          }
          curr->next = temp;
      }
      size++;
  }
  
  void display(){
      Node* curr = head;
      
      while(curr->next != nullptr){
          cout<<curr->data<<" ";
          curr = curr->next;
      }
      cout<<endl;
  }
  
  Node* popFront(){
      Node* curr = head;
      if(head == nullptr)
            return nullptr;
      else {
          head = head->next;
          return curr;
      }
  }
 
//Node* popBack(){
//       Node* curr = head;
//       Node* temp = curr;
      
//       if(curr == nullptr)
//             return nullptr;
//       else {
//           while(curr->next !=  nullptr){
//               curr->next = curr;
//           }
//           Node* ans = curr;
//           curr = nullptr;
//           cout<<ans<<" ans\n";
//           head = temp;
//           return ans;
//       }
//}
  Node* popBack(){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        Node* ans = head;
        head = nullptr;
        size--;
        return ans;
    }
    Node* curr = head;
    while(curr->next->next != nullptr){
        curr = curr->next;
    }
    Node* ans = curr->next;
    curr->next = nullptr;
    size--;
    return ans;
 }
 
//   Node* returnAtInd(int ind){
//       if(ind<0 || ind>size){
//           return nullptr;
//       }else{
//           Node* curr = head;
//           Node* temp = curr;
//           if(ind==0){
//               head = head->next;
//               curr->next = nullptr;
//               return curr;
//           }
//           ind--;
//           while(ind != 0){
//               if(curr->next != nullptr && curr->next->next != nullptr){
//                   curr->next = curr->next->next;
//               }else if(curr->next == nullptr){
//                   temp = curr->next;
//                   curr=nullptr
//               }
//               curr = curr->next;
//               ind--;
//           }
//           return temp;
//       }
//   }

    Node* returnAtInd(int ind){
        if(ind < 0 || ind >= size){   // invalid index
            return nullptr;
        }
    
        Node* curr = head;
    
        if(ind == 0){
            head = head->next;
            curr->next = nullptr;
            size--;
            return curr;
        }
    
        Node* prev = nullptr;
        for(int i = 0; i < ind; i++){
            prev = curr;
            curr = curr->next;
        }

    
        prev->next = curr->next;
        curr->next = nullptr;
        size--;
    
        return curr;   // return removed node
    }
  
};

int main() {
    LinkedList* head = new LinkedList();
    head->add(10);
    head->add(20);
    head->add(30);
    head->add(40);
    head->add(50);
    head->add(60);
    head->add(70);
    head->add(80);
    head->add(90);
    cout<<head->len()<<" size \n";
    // head->display();
    Node* temp1 = head->popFront();
    cout<<temp1->data<<" data\n";
    cout<<head->len()<<" size \n";
    
    Node* temp3 = head->popFront();
    cout<<temp3->data<<" data\n";
    cout<<head->len()<<" size \n";
    head->display();
    
    Node* temp2 = head->popBack();
    if(temp2 != nullptr){
        cout<<temp2->data<<" data\n";
    }
    
    Node* temp4 = head->returnAtInd(5);

    
    cout<<temp4->data<<" remove "<<endl;

    // head->display();
    
    return 0;
    
}
