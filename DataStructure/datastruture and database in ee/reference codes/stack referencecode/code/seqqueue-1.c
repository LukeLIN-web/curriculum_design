int seqqueue_push(SeqQueue *seqqueue, SeqQueueValue data){
    if (seqqueue->len == MaxQueueSize) 	/* 要求队列未满 */
        return 0; 
    seqqueue->array[seqqueue->len++] = data;
    return 1;
}