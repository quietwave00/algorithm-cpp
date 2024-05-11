/**
 * Linked List 구현
*/
#include <stddef.h>

struct Node {
    int data;
    Node* nextNode;
};

class LinkedList {
    private:
        Node* head = new Node;
        Node* tail = new Node;

    public:
        LinkedList() {
            head->nextNode = tail; // head node의 다음 노드로 tail node를 가리킴
            tail->nextNode = NULL; // tail node의 다음 노드는 존재하지 않음
        }

        // 리스트의 시작 부분에 새로운 요소를 추가
        void push_front(int data) {
            Node* newNode = new Node;
            newNode->data = data; // 새로운 노드의 data를 인자의 data로

            // NULL의 경우
            if(head == NULL) {
                head = newNode;
                tail = newNode;

                // head가 됨
            }

            // head - tail의 경우
            else {
                newNode->nextNode = head;
                head = newNode;

                // newNode - head - tail이 됨
            }
        }

        // 리스트의 끝에 새로운 요소를 추가
        void push_back(int data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->nextNode = NULL;

            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }

            else {
                tail->nextNode = newNode;
                tail = newNode;

                // head - tail - newNode가 됨
            }
        }

        // 지정된 위치에 새로운 요소를 추가
        void insert(Node* prevNode, int data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->nextNode = prevNode->nextNode;
            prevNode->nextNode = newNode;

            // ex) 0 1 2 3에서 prevNode = 3
            // 0 1 2 newNode 3
            // 세 번째 다음 newNode가 위치하게 됨
        }

        // 요소를 삭제
        void erase(Node* prevNode) {
            Node* newNode = prevNode->nextNode;
            prevNode->nextNode = newNode->nextNode;
            delete newNode;

            // ex) 0 1 2 3 4에서 prevNode = 3
            // newNode는 prevNode의 다음 노드인 3노드가 됨
            // 2의 다음 노드가 4가 됨
            // 3노드가 지워짐
            // 0124
        }
};