#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int partition_size;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} MemoryAllocator;

MemoryAllocator* create_allocator() {
    MemoryAllocator* allocator = (MemoryAllocator*)malloc(sizeof(MemoryAllocator));
    allocator->head = NULL;
    return allocator;
}

void add_partition(MemoryAllocator* allocator, int size) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->partition_size = size;
    new_node->next = NULL;

    if (allocator->head == NULL) {
        allocator->head = new_node;
    } else {
        Node* temp = allocator->head;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

void display_memory(MemoryAllocator* allocator) {
    Node* current = allocator->head;

    if (current == NULL) {
        printf("No partitions available.\n");
        return;
    }

    printf("Memory Partitions: ");
    while (current) {
        printf("%d ", current->partition_size);
        current = current->next;
    }
    printf("\n");
}

int first_fit(MemoryAllocator* allocator, int request_size) {
    Node* current = allocator->head;

    while (current) {
        if (current->partition_size >= request_size) {
            current->partition_size -= request_size;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int best_fit(MemoryAllocator* allocator, int request_size) {
    Node* current = allocator->head;
    Node* best = NULL;
    int min_diff = INT_MAX;

    while (current) {
        if (current->partition_size >= request_size) {
            int diff = current->partition_size - request_size;
            if (diff < min_diff) {
                min_diff = diff;
                best = current;
            }
        }
        current = current->next;
    }

    if (best) {
        best->partition_size -= request_size;
        return 1;
    }
    return 0;
}

int worst_fit(MemoryAllocator* allocator, int request_size) {
    Node* current = allocator->head;
    Node* worst = NULL;
    int max_size = -1;

    while (current) {
        if (current->partition_size >= request_size &&
            current->partition_size > max_size) {

            max_size = current->partition_size;
            worst = current;
        }
        current = current->next;
    }

    if (worst) {
        worst->partition_size -= request_size;
        return 1;
    }
    return 0;
}

int main() {

    MemoryAllocator* allocator = create_allocator();
    int choice, size, request, n;

    while(1) {
        printf("\nALLOCATION MENU\n");
        printf("1. Add Partitions\n");
        printf("2. Display Memory\n");
        printf("3. First Fit Allocation\n");
        printf("4. Best Fit Allocation\n");
        printf("5. Worst Fit Allocation\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of partitions: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter size of partition %d: ", i + 1);
                    scanf("%d", &size);
                    add_partition(allocator, size);
                }
                break;

            case 2:
                display_memory(allocator);
                break;

            case 3:
                printf("Enter memory request: ");
                scanf("%d", &request);
                if (first_fit(allocator, request))
                    printf("Allocated using First Fit.\n");
                else
                    printf("Allocation Failed.\n");
                break;

            case 4:
                printf("Enter memory request: ");
                scanf("%d", &request);
                if (best_fit(allocator, request))
                    printf("Allocated using Best Fit.\n");
                else
                    printf("Allocation Failed.\n");
                break;

            case 5:
                printf("Enter memory request: ");
                scanf("%d", &request);
                if (worst_fit(allocator, request))
                    printf("Allocated using Worst Fit.\n");
                else
                    printf("Allocation Failed.\n");
                break;

            case 6:
                printf("Exiting :)\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
