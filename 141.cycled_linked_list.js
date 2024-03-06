const hasCycle =(head)=>{
    let slow = head;
    let fast = head;
    while (fast !== null && slow !== null) {
        slow = slow.next;
        fast = fast?.next?.next;

        if (fast === slow) {
            return true;
        }
    }
    return false;
}
