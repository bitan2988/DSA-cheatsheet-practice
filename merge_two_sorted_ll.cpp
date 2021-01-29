node* merge_two_sorted(node* head1, node* head2)
{
	node* p1=head1;
	node* p2=head2;
	node* dummy_node = new  node(-1);
    node* p3  = dummy_node;
    while(p1!=NULL and p2!=NULL)
    {
        if(p1->data<=p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if(p1!=NULL)
    {
        while(p1!=NULL)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
    }
    else
    {
        while(p2!=NULL)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    return dummy_node->next;
}

node* merge_recursive(node* head1,node* head2)
{
    node* result;
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<=head2->data)
    {
        result = head1;
        result->next = merge_recursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = merge_recursive(head1, head2->next);
    }
    return result;
}

