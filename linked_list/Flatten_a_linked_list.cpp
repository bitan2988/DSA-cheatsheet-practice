//FLATTEN A LINKED LIST        https://www.youtube.com/watch?v=ysytSSXpAI0
//we will print the ll using the bottom pointer in this case and not the next

node* merge(node* p1, node* p1){       //sorting using comparison method of merge sort
    node* temp = new node(-1);   //dummy node
    node* res = temp;  //give resturn result
    while(a!=NULL and b!=NULL){
        if(p1->data < p2->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if(a){
        temp->bottom = a;    //some elements of a are remaining
    }
    else{
        temp->bottom = b;    //some elements of b are remaining
    }

    return res->bottom;  //pointing to the first node  of this sorted linked list
}

node* flatten(){
    if(head==NULL || head->next==NULL){         // if it had reached the last ll then return the it 
        return head; //let the ll be  l1->l2->l3->l4->l5 ; so we sort l5 and l4 first then sort their output with l3 then their output with l2 and finallly with l2
    }
    head->next = flatten(head->next);     //if not the last ll then keep looking forward for it

    head = merge(head, head->next);      //if found the current last ll then sort them both and store as another ll

    return head;
}