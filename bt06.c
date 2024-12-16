#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define INFINITY INT_MAX

int adjacencyMatrix[MAX][MAX];
int vertexCount = 0;

void initGraph() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjacencyMatrix[i][j] = (i == j) ? 0 : INFINITY;
        }
    }
}

void addVertex() {
    vertexCount++;
    printf("\nThem dinh %d thanh cong!", vertexCount - 1);
}

void addEdge(int u, int v, int weight) {
    if (u >= vertexCount || v >= vertexCount) {
        printf("\nLoi: Dinh khong hop le!\n");
        return;
    }
    adjacencyMatrix[u][v] = weight;
    adjacencyMatrix[v][u] = weight;
    printf("\nThem canh (%d, %d) voi trong so %d thanh cong!\n", u, v, weight);
}

void displayMatrix() {
    printf("\nMa tran ke:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            if (adjacencyMatrix[i][j] == INFINITY)
                printf("INF ");
            else
                printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void bfs(int startVertex) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = true;

    printf("\nThu tu cac dinh duyet BFS: ");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[currentVertex][i] != INFINITY && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

void dijkstra(int startVertex) {
    int distance[MAX];
    bool visited[MAX] = {false};

    for (int i = 0; i < vertexCount; i++) {
        distance[i] = INFINITY;
    }
    distance[startVertex] = 0;

    for (int count = 0; count < vertexCount - 1; count++) {
        int minDistance = INFINITY, minIndex;

        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = true;

        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v] && adjacencyMatrix[u][v] != INFINITY && distance[u] != INFINITY &&
                distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjacencyMatrix[u][v];
            }
        }
    }

    printf("\nKhoang cach ngan nhat tu dinh %d:\n", startVertex);
    for (int i = 0; i < vertexCount; i++) {
        if (distance[i] == INFINITY)
            printf("Dinh %d: INF\n", i);
        else
            printf("Dinh %d: %d\n", i, distance[i]);
    }
}

void findHighestDegreeVertex(bool isDirected) {
    int degree[MAX] = {0};
    int maxDegree = 0, maxVertex = -1;

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            if (adjacencyMatrix[i][j] != INFINITY && adjacencyMatrix[i][j] != 0) {
                degree[i]++;
                if (!isDirected) {
                    degree[j]++;
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxVertex = i;
        }
    }

    if (maxVertex != -1) {
        printf("\nDinh co bac cao nhat la: %d voi bac: %d\n", maxVertex, maxDegree);
    } else {
        printf("\nKhong co dinh nao trong do thi.\n");
    }
}

int main() {
    int choice, u, v, weight, startVertex;
    bool isDirected = false;
    initGraph();

    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Them dinh\n");
        printf("2. Them canh\n");
        printf("3. Hien thi ma tran ke\n");
        printf("4. Duyet BFS\n");
        printf("5. Thuat toan Dijkstra\n");
        printf("6. Tim dinh co bac cao nhat\n");
        printf("7. Thoat\n");
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
                printf("Nhap trong so: ");
                scanf("%d", &weight);
                addEdge(u, v, weight);
                break;

            case 3:
                displayMatrix();
                break;

            case 4:
                printf("Nhap dinh bat dau BFS: ");
                scanf("%d", &startVertex);
                bfs(startVertex);
                break;

            case 5:
                printf("Nhap dinh nguon: ");
                scanf("%d", &startVertex);
                dijkstra(startVertex);
                break;

            case 6:
                printf("Do thi co huong? (1: Co, 0: Khong): ");
                scanf("%d", &isDirected);
                findHighestDegreeVertex(isDirected);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                exit(0);

            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

