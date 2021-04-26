int in_order_print(BiTreeNode *node) {
    if(node) {
        if(in_order_print(node->children[BITREE_NODE_LEFT])) {
            printf("%s ", node->value);
            if(in_order_print(node->children[BITREE_NODE_RIGHT]))
				return 1;
            return 0;
        }
        return 0;
    }
    return 1;
}

int post_order_free(BiTreeNode *node) {
    if(node) {
        if(post_order_free(node->children[BITREE_NODE_LEFT])) {
            if(post_order_free(node->children[BITREE_NODE_RIGHT])) {
                free(node->value);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 1;
}