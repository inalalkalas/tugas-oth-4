#include <stdio.h>
#include <stdlib.h>

typedef struct NODE *node;

struct NODE 
{
    int value_node;
    node next;
    node prev;
};

node head = NULL;

node create_node(int value) 
{
    node local = (node)malloc(sizeof(node));
    local->value_node = value;
    local->next = local->prev = head;
    return local;
}

void insert_first(int value) 
{
    node node_local = create_node(value);

    (head == NULL) ? (head = node_local, head->next = head->prev = node_local) : (node_local->next = head, node_local->prev = head->prev, head->prev->next = node_local, head = node_local);
}

void insert_last(int value) 
{
    node node_local = create_node(value);

    (head == NULL) ? (head = node_local, head->next = head->prev = node_local) : (node_local->next = head, node_local->prev = head->prev, head->prev->next = node_local, head->prev = node_local);

}

void swap (node *head, node a, node b)
{
    if (a == b) return;  // No need to swap identical nodes

    node a_prev = a->prev;
    node a_next = a->next;
    node b_prev = b->prev;
    node b_next = b->next;

    if (a->next == b) 
    {  
        // a and b are adjacent with a before b
        a->next = b_next;
        a->prev = b;
        b->next = a;
        b->prev = a_prev;
        a_prev->next = b;
        b_next->prev = a;
    } else if (b->next == a) 
    {  
        // a and b are adjacent with b before a
        b->next = a_next;
        b->prev = a;
        a->next = b;
        a->prev = b_prev;
        b_prev->next = a;
        a_next->prev = b;
    } else 
    {  
        // a and b are not adjacent
        a->next = b_next;
        a->prev = b_prev;
        b->next = a_next;
        b->prev = a_prev;
        a_prev->next = b;
        a_next->prev = b;
        b_prev->next = a;
        b_next->prev = a;
    }

    if (*head == a) *head = b;
    else if (*head == b) *head = a;
}

void sort_list()
{
    if(head == NULL) return;

    node current;
    int temp;

    do 
    {
        temp = 0;
        current = head;

        do
        {
            if (current->value_node > current->next->value_node) 
            {
            // tukar node menggunakan fungsi
            swap(&head, current, current->next);
            // ubah nilai repeat jadi 1 agar bisa melakukan looping dari awal lagi
            temp = 1;
            } else 
            {
            // jika node tidak memenuhi kriteria, maka lanjut ke node selanjutnya
            current = current->next;
            }
        } while(current->next != head);

    } while (temp);
}

void show_list()
{
    node local = head; 

    if (head == NULL) return;

    do 
    {
        printf("Address: %p\nValue: %d\n", local, local->value_node);
        local = local->next;

    } while (local != head);
    
    printf("\n");
}

int main() 
{
    int choice, value_, length, buffer;

    do 
    {
        printf("1. Tambahkan di Awal List\n");
        printf("2. Tambahkan di Akhir List\n");
        printf("3. Tampilkan Nilai List\n");
        printf("4. Add with Limitid number\n");
        printf("0. Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &value_);

                insert_first(value_);
                printf("\n");
                break;
            case 2:
                printf("Masukkan nilai: ");
                scanf("%d", &value_);

                insert_last(value_);
                printf("\n");
                break;
            case 3:
                printf("\nList saat ini:\n");
                show_list();
                printf("\n");
                sort_list();
                show_list();
                printf("\n");
                break;
            case 4: 
                printf("Masukan Panjang Linked list: ");
                scanf("%d", &length);

                printf("1. Insert fisrt | 2. Insert Last: ");
                scanf("%d", &value_);

                if (value_ == 1)
                {
                    for (int i = 0; i < length; i++) 
                    {
                        scanf("%d", &buffer);
                        // tambah node baru menggunakan insertLast
                        insert_first(buffer);
                        // jika list kosong, maka ubah list first juga
                        if (head == NULL) head;
                    }

                    printf("\nList saat ini:\n");
                    show_list();
                    printf("\n");
                    sort_list();
                    show_list();
                    printf("\n");

                } else
                {
                    for (int i = 0; i < length; i++) {
                        scanf("%d", &buffer);
                        // tambah node baru menggunakan insertLast
                        insert_last(buffer);
                        // jika list kosong, maka ubah list first juga
                        if (head == NULL) head;
                    }

                    printf("\nList saat ini:\n");
                    show_list();
                    printf("\n");
                    sort_list();
                    show_list();
                    printf("\n");
                }
                return 0;
            case 0:
                return 0;
            default:
                break;
        }
    } while (choice != 0);
    return 0;
}
