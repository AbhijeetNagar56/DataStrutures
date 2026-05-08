class DynamicArray {
private:
    int* _data;
    int _capacity;
    int _size;
    void _copy(int* source, int* dest, int size) {
        for(int i = 0; i < size; i++) dest[i] = source[i];
    }
public:

    DynamicArray(int capacity) {
        _data = new int[capacity];
        _capacity = capacity;
        _size = 0;
    }

    int get(int i) {
        if(i > _size) return -1;
        return _data[i];
    }

    void set(int i, int n) {
        if(i > _size) return;
        _data[i] = n;
    }

    void pushback(int n) {
        if(_size == _capacity) resize();
        _data[_size++] = n;
    }

    int popback() {
        if(_size == 0) return -1;
        int e = _data[_size - 1];
        _size--;
        return e;

    }

    void resize() {
        int* _tmp = _data;
        _capacity *= 2;
        _data = new int[_capacity];
        _copy(_tmp, _data, _size);
        delete[] _tmp;
    }

    int getSize() {
        return _size;
    }

    int getCapacity() {
        return _capacity;
    }
};
