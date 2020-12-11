#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {

}
void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );
#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV( Vertex V )
{
    printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

/* Your function will be put here */
void StronglyConnectedComponents(Graph G, void(*visit)(Vertex V)) {
    int isconnect[MaxVertices][MaxVertices] = { 0 };
    int i, j;
    for (i = 0; i < G->NumOfVertices; i++) {
        isconnect[i][i] = 1;
        int isread[MaxVertices] = { 0 };
        int t;
        int stack[MaxVertices];
        t = 0;
        stack[++t] = i;//结点入栈
        while (t!=0) {// 栈非空
            j = stack[t];
            t--;
            PtrToVNode tempNode;  // 搜索每一个结点
            tempNode = G->Array[j];
            while (tempNode != NULL) {  //沿着一条路搜索下去.
                //b = b->Next;
                isconnect[i][tempNode->Vert] = 1;
                if (isread[tempNode->Vert] == 0) {
                    isread[tempNode->Vert] = 1;
                    stack[++t] = tempNode->Vert; //搜索时，把当前搜索树中未处理的节点加入一个堆栈，
                    // 回溯时可以判断栈顶到栈中的节点是否为一个强连通分量。
                }
                tempNode = tempNode->Next; //搜索下一个结点
            }
        }
    }
    int *a = (int*)malloc(G->NumOfVertices*(sizeof(int)));
    for (i = 0; i < G->NumOfVertices ; i++)
        a[i] = 0;
    i = 0;
    while (i < G->NumOfVertices) {
        int j;
        int fir = 0;
        for (j = i; j < G->NumOfVertices; j++) {
            if (isconnect[i][j] == 1 && isconnect[j][i] == 1) {
                a[j] = 1;
                if (fir == 0) {
                    fir = 1;
                }
                else
                    printf(" ");
                (*visit)(j);
            }

        }
        printf("\n");
        while (a[i] != 0) {
            i++;
            if (i > G->NumOfVertices)
                break;
        }
    }
}