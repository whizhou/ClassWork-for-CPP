#ifndef ARRAY_H
#define ARRAY_H

class Container
{
public:
    // 在下标index的位置插入value，成功返回true，否则返回false
    virtual bool insert(const int index, const int value) { return false; }
    // 删除下标index的元素，成功返回true，否则返回false
    virtual bool remove(const int index) { return false; }
    // 将下标index的元素设置为value，成功返回true，否则返回false
    virtual bool set(const int index, const int value) { return false; }
    // 获取下标index的元素，并存储在value中，成功返回true，否则返回false
    virtual bool get(const int index, int &value) const { return false; }

    // 获取容器中的元素数量
    int size() const { return num_items; };

protected:
    // 容器中的元素的数量
    int num_items;

public:
    Container() {}
    virtual ~Container() {}
};

class Array : public Container
{
public:
    Array();
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);

    bool insert(const int index, const int value);
    bool remove(const int index);
    bool set(const int index, const int value);
    bool get(const int index, int &value) const;

private:
    int *data;    // 指向存放元素的数组
    int capacity; // data的长度
};

#endif

#define fo(i, x, y) for(int i = x, endI = y; i < endI; ++ i)
 
Array::Array() : data(new int[0]), capacity(0) { num_items = capacity; }

Array::Array(const Array &other) {
    capacity = other.capacity;
    data = new int[capacity];
    fo(i, 0, capacity)
        data[i] = other.data[i];
    num_items = capacity;
}

Array::~Array() { delete[] data; }

Array& Array::operator=(const Array &other) {
    if (this == &other) return *this;
    delete[] data;
    capacity = other.capacity;
    data = new int[capacity];
    fo(i, 0, capacity)
        data[i] = other.data[i];
    num_items = capacity;
    return *this;
}

bool Array::insert(const int index, const int value) {
    if (index > capacity)
        return 0;
    int *tmp = new int[capacity + 1];
    fo(i, 0, index) tmp[i] = data[i];
    tmp[index] = value;
    fo(i, index, capacity)
        tmp[i + 1] = data[i];
    delete[] data;
    ++ capacity;
    data = tmp;
    num_items = capacity;
    return 1;
}

bool Array::remove(const int index) {
    if (index >= capacity)
        return 0;
    int *tmp = new int[capacity - 1];
    fo(i, 0, index) tmp[i] = data[i];
    fo(i, index + 1, capacity)
        tmp[i - 1] = data[i];
    delete[] data;
    -- capacity;
    data = tmp;
    num_items = capacity;
    return 1;
}

bool Array::set(const int index, const int value) {
    return index < capacity ? (data[index] = value, 1) : 0;
}

bool Array::get(const int index, int &value) const {
    return index < capacity ? (value = data[index], 1) : 0;
}
