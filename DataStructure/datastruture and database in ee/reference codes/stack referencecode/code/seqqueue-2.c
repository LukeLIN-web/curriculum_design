SeqQueueValue seqqueue_pop(SeqQueue *seqqueue){
    void *result;
    int i;
    if (seqqueue->len == 0)    /* 要求队列非空  */
        return NULL;
    result = seqqueue->array[0];
    /* 队列中剩下的元素向队头移动一位 */
    for (i = 1; i < seqqueue->len; i++)
        seqqueue->array[i - 1] = seqqueue->array[i];
    seqqueue->len--;
    return result;
}