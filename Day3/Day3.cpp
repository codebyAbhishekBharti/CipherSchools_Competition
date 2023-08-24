#include <iostream>
#include "vector"
using namespace std;
struct Node{
    int data;
    struct Node* next;
    Node(int x) : data(x), next(NULL) {}
};

Node* merge(Node* low, Node* high) {
    if(!low)return high;
    if(!high)return low;

    Node*result=NULL;
    if(low->data <= high->data){
        result = low;
        result->next = merge(low->next,high);
    } 
    else{
        result = high;
        result->next = merge(low,high->next);
    }
    return result;
}
void split(Node* head, Node** front, Node** back) {
    Node* right;
    Node* left;
    left = head;
    right = head->next;
    while (right != NULL) {
        right = right->next;
        if (right != NULL) {
            left = left->next;
            right = right->next;
        }
    }
    *front= head;
    *back= left->next;
    left->next = NULL;
}
void mergeSort(Node** r_head) {
    Node* low;    
    Node* head = *r_head;
    Node* high;
    if (head == NULL or head->next == NULL)
        return;
    split(head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    *r_head = merge(low, high);
}
void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
int main() {
    int n;
    cin>> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    Node* head = new Node(v[0]);
    Node* current = head;
    for (int i = 1; i<n; ++i) {
        current->next = new Node(v[i]);
        current = current->next;
    }
    mergeSort(&head);
    printList(head);
    return 0;
}
