Node* deleteNode(Node* head, int x) {
        // Your code here
     int count=1;
     Node*temp=head;
     while(count<x){
         temp=temp->next;
         count++;
     }
     if(temp->prev==NULL){
         head=temp->next;
         delete temp;
         return  head;
         
     }
     if(temp->next==NULL){
         temp->prev->next=NULL;
         delete temp;
         return head;
     }
      if(temp->next!=NULL || temp->prev!=NULL){
         temp->prev->next=temp->next;
         temp->next->prev=temp->prev;
         delete temp;
         return head;
     }
    }