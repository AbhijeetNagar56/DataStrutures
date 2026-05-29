#include <iostream>
#include <vector>
using namespace std;

class min_heap { // push, pop, top, size, empty
private:
    vector<int> pq;
public:
    void push(int val) {
        pq.push_back(val);
        heapify_up(pq.size() - 1);
    }

    int size() {
        return pq.size();
    }

    int top() {
        if(empty()) return -1;
        return pq[0];
    }

    void pop() {
        if(pq.size() == 0) return;
        pq[0] = pq[pq.size() - 1];
        pq.erase(pq.begin() + pq.size() - 1);
        heapify_down(0);
    }

    bool empty() {
        return pq.size()==0;
    }

    void heapify_up(int i) {
        int parent = (i - 1) / 2;

        if(i >= 0 && pq[i] < pq[parent]) {
            pq[i] = pq[i] + pq[parent] - (pq[parent] = pq[i]);
            heapify_up(parent);
        }
    }

    void heapify_down(int i) {
        int n = pq.size();
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && pq[left] < pq[smallest]) {
            smallest = left;
        }

        if(right < n && pq[right] < pq[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            pq[i] = pq[i] + pq[smallest] - (pq[smallest] = pq[i]);
            heapify_down(smallest);
        }
    }
    
    void display() {
        for(int n: pq) {
            cout << n << " ";
        }
        cout << endl;
    }

};

class max_heap { // push, pop, 
private:
    vector<int> pq;
public:
    void push(int val) {
        pq.push_back(val);
        heapify_up(pq.size() - 1);
    }

    int size() {
        return pq.size();
    }

    int top() {
        if(empty()) return -1;
        return pq[0];
    }

    void pop() {
        if(pq.size() == 0) return;
        pq[0] = pq[pq.size() - 1];
        pq.erase(pq.begin() + pq.size() - 1);
        heapify_down(0);
    }

    bool empty() {
        return pq.size()==0;
    }

    void heapify_up(int i) {
        int parent = (i - 1) / 2;

        if(i >= 0 && pq[i] > pq[parent]) {
            pq[i] = pq[i] + pq[parent] - (pq[parent] = pq[i]);
            heapify_up(parent);
        }
    }

    void heapify_down(int i) {
        int n = pq.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && pq[left] > pq[largest]) {
            largest = left;
        }

        if(right < n && pq[right] > pq[largest]) {
            largest = right;
        }

        if (largest != i) {
            pq[i] = pq[i] + pq[largest] - (pq[largest] = pq[i]);
            heapify_down(largest);
        }
    }
    
    void display() {
        for(int n: pq) {
            cout << n << " ";
        }
        cout << endl;
    }

};




int main () {
    min_heap h;

    h.push(1);
    h.push(2);
    h.push(3);
    h.push(4);
    h.display();

    h.pop();
    h.display();

    cout << h.top() << endl;
    return 0;
}