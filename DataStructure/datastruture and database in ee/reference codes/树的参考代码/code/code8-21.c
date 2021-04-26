void huffman_tree(BiTree *huffmantree, int weights[], int tmpweights[], int len, BiTreeNode **nodes) {
	int MAXVALUE = 100;	/* 最大权值 */
	int x1, x2, m1, m2; /*x1,x2,m1,m2分别存储最小和次小的位置和节点值*/
	int i, j;
    int *flags = malloc(sizeof(int)*(2*len-1));	/* 标志weights和tmpWeights是否已经处理过 */
    for(i = 0; i < 2*len-1; i++)
    	flags[i] = 0;
    /*形成len个叶节点 */
    for (i = 0; i < len; i++) {
        nodes[i] = (BiTreeNode *)malloc(sizeof(BiTreeNode));
        nodes[i]->children[BITREE_NODE_LEFT] = NULL;
        nodes[i]->children[BITREE_NODE_RIGHT] = NULL;
        nodes[i]->value = &weights[i];
        nodes[i]->parent = NULL;
    }
    for (i = 0; i < len - 1; i++) { /*构造哈夫曼树*/
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (j = 0; j < len; j++) {
            if (flags[j] < 1 && weights[j] < m1) {
                m2 = m1;
                x2 = x1;
                m1 = weights[j];
                x1 = j;
            } else if (flags[j] < 1 && weights[j] < m2) {
                m2 = weights[j];
                x2 = j;
            }
        }
        for(j = 0; j < i; j++) {
            if (flags[j+len] < 1 && tmpweights[j] < m1) {
                m2 = m1;
                x2 = x1;
                m1 = tmpweights[j];
                x1 = j+len;
            } else if (flags[j+len] < 1 && tmpweights[j] < m2) {
                m2 = tmpweights[j];
                x2 = j+len;
            }
        }
        flags[x1] = 1;
        flags[x2] = 1;
        tmpweights[i]  = m1+m2;
        nodes[i + len] = (BiTreeNode *)malloc(sizeof(BiTreeNode));
        nodes[i + len]->children[BITREE_NODE_LEFT] = nodes[x1];
        nodes[i + len]->children[BITREE_NODE_RIGHT] = nodes[x2];
        nodes[i + len]->value = &(tmpweights[i]);
        nodes[i + len]->parent = NULL;
        nodes[x1]->parent = nodes[i+len];
        nodes[x2]->parent = nodes[i+len];
    }
    huffmantree->rootnode = nodes[2*len-2];
    huffmantree->nodenum = 2*len-1;
}