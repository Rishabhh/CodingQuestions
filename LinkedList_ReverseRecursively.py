# we need to reverse a linked list recursively without using a second parameter of previous pointer and finally return a
# a pointer to the head of the new reversed linked list so that it can be tested that the list got reversed .

def reverseRecursively(head) :

    if head == None:
        return None
    if head.next == None:
        return head      # this is what we have to return from every recursive call to finally return the head of new LL .
    
    output = reverseRecursively(head.next)
    head.next.next = head
    head.next = None
    
    return output
