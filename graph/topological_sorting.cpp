#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    int size;
    int currentNode;
};

void insertNode(struct LinkedList *l, int n)
{
    struct Node *newNode = new Node;
    newNode->data = n;

    if (!l->head)
        l->head = newNode;
    else
    {
        struct Node *p = l->head;
        while (p->next)
            p = p->next;
        p->next = newNode;
    }
}

class Graph
{
    int V;
    struct LinkedList *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new LinkedList[V];
        for (int i = 0; i < V; i++)
        {
            l[i].size = 0;
            l[i].currentNode = i;
        }
    }

    void addEdge(int src, int dtn)
    {
        insertNode(&l[src], dtn);
        l[src].size++;
    }

    int dfs(struct LinkedList *list, int isVisited[], int ordering[], int i)
    {
        isVisited[list->currentNode] = 1;
        if (list->size)
        {
            int connectedNodes[list->size];
            int j = 0;

            for (struct Node *p = list->head; p != NULL; p = p->next)
                connectedNodes[j++] = p->data;

            for (auto node : connectedNodes)
                if (!isVisited[node])
                    i = dfs(&l[node], isVisited, ordering, i);
        }
        ordering[i] = list->currentNode;
        return i - 1;
    }

    void topologicalSort()
    {
        int isVisited[V] = {0}, ordering[V] = {0};
        int i = V - 1;

        /*for every node in the graph, if they have not been visited yet, topological go over
        them with the help of depth first search and place them in the ordering array */
        for (int currentNode = 0; currentNode < V; currentNode++)
            if (!isVisited[currentNode])
                i = dfs(&l[currentNode], isVisited, ordering, i);

        for (auto order : ordering)
            cout << order << " ";
    }
};

int main()
{
    int V = 6;
    /*cin >> V;*/
    Graph g(V);

    /*int src, dest;
    for (int i = 0; i < V; i++)
    {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }*/

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
}