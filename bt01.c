#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjacencyMatrix[MAX][MAX];
int vertexCount = 0;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX];

void initGraph() {
    for (int i = 0; i < MAX; i++) {
        adjacencyList[i] = NULL;
        for (int j = 0; j < MAX; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addVertex() {
    vertexCount++;
    printf("\nThem dinh %d thanh cong!", vertexCount - 1);
}

void addEdgeMatrix(int u, int v, int directed) {
    adjacencyMatrix[u][v] = 1;
    if (!directed) {
        adjacencyMatrix[v][u] = 1;
    }
}

void addEdgeList(int u, int v, int directed) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;

    if (!directed) {
        Node* newNode2 = (Node*)malloc(sizeof(Node));
        newNode2->vertex = u;
        newNode2->next = adjacencyList[v];
        adjacencyList[v] = newNode2;
    }
}

void displayMatrix() {
    printf("\nMa tran ke:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayList() {
    printf("\nDanh sach ke:\n");
    for (int i = 0; i < vertexCount; i++) {
        printf("%d: ", i);
        Node* temp = adjacencyList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, u, v, directed;
    initGraph();

    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Them dinh\n");
        printf("2. Them canh\n");
        printf("3. Hien thi ma tran ke\n");
        printf("4. Hien thi danh sach ke\n");
        printf("5. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVertex();
                break;

            case 2:
                printf("Nhap dinh bat dau: ");
                scanf("%d", &u);
                printf("Nhap dinh ket thuc: ");
                scanf("%d", &v);
                printf("Ðo thi co huong? (1: Co, 0: Khong): ");
                scanf("%d", &directed);
                addEdgeMatrix(u, v, directed);
                addEdgeList(u, v, directed);
                printf("Them canh (%d, %d) thanh cong!\n", u, v);
                break;

            case 3:
                displayMatrix();
                break;

            case 4:
                displayList();
                break;

            case 5:
                printf("Thoat chuong trinh.\n");
                exit(0);

            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

