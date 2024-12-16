#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjacencyMatrix[MAX][MAX];
int vertexCount = 0;

void initGraph() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addVertex() {
    vertexCount++;
    printf("\nThem dinh %d thanh cong!", vertexCount - 1);
}

void addEdge(int u, int v) {
    if (u >= vertexCount || v >= vertexCount) {
        printf("\nLoi: Dinh khong hop le!\n");
        return;
    }
    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1; 
    printf("\nThem canh (%d, %d) thanh cong!\n", u, v);
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

int main() {
    int choice, u, v;
    initGraph();

    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Them dinh\n");
        printf("2. Them canh\n");
        printf("3. Hien thi ma tran ke\n");
        printf("4. Thoat\n");
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
                addEdge(u, v);
                break;

            case 3:
                displayMatrix();
                break;

            case 4:
                printf("Thoat chuong trinh.\n");
                exit(0);

            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

