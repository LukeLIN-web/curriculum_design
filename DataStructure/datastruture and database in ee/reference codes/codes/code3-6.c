/* 如果listentry被找到，返回前驱结点指针，否则返回尾结点 */
SListEntry *slist_find_previous(SListEntry **list, SListEntry *listentry){
    SlistEntry *rover;
    rover = *list;
    while(rover->next != NULL && rover->next != listentry)
        rover = rover->next;
    return rover;
}