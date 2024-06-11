template <typename T>
T maxValue (const T value1, const T value2) {
    return value1 > value2 ? value1 : value2;
}

char toupper(const char c) {
    return ('A' <= c && c <= 'Z') ? c : c - 'a' + 'A';
}

template <>
char maxValue(const char value1, const char value2) {
    return toupper(value1) >= toupper(value2) ? value1 : value2;
}